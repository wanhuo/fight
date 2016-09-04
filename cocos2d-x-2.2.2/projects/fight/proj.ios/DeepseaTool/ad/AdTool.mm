//
//  AdTool.m
//  vpn
//
//  Created by caoyusheng on 3/8/16.
//  Copyright © 2016年 caoyusheng. All rights reserved.
//

#import "AdTool.h"
#import "AdmobTool.h"
#import "UnityAdsTool.h"
#import "AdProtocol.h"
#import "Config.h"
#include "DeepseaTool.h"

@interface AdTool()

@property(nonatomic, strong) NSMutableDictionary *tools;

@end

@implementation AdTool

static AdTool *instance = nil;

+ (void) initWithViewController: (UIViewController *) viewController define:(AdDefine *)adDefine
{
    if (!instance)
    {
        instance = [AdTool alloc];
        
//        [instance createAdTools:@AD_MODE_BANNER viewController:viewController define:adDefine];
        [instance createAdTools:@AD_MODE_INTERSTITIAL viewController:viewController define:adDefine];
        [instance createAdTools:@AD_MODE_VEDIO viewController:viewController define:adDefine];
    }
}

- (void) createAdTools: (NSString *) adMode viewController: (UIViewController *)viewController define:(AdDefine *)adDefine
{
    if (!_tools)
    {
        _tools = [[NSMutableDictionary alloc] init];
    }
    _tools[adMode] = [[NSMutableArray<AdProtocol> alloc] init];
    NSArray *ads = [[Config alloc] getConfigAds: adMode];
    for (NSString *ad in ads)
    {
        [_tools[adMode] addObject:[self createAdTool:ad viewController:viewController define:adDefine]];
    }
}

- (UIView *) createBanner;
{
    for (id<AdProtocol> adTool in _tools[@AD_MODE_BANNER])
    {
        UIView *bannerView = [adTool createBanner];
        if (bannerView)
        {
            return bannerView;
        }
    }
    return nil;
}

- (id<AdProtocol>) createAdTool: (NSString *)adName viewController:(UIViewController *) viewController define:(AdDefine *)adDefine
{
    if ([@AD_CHANNEL_ADMOB isEqualToString:adName])
    {
        return [AdmobTool initWithViewController:viewController define:adDefine];
    }
    else if([@AD_CHANNEL_UNITY_ADS isEqualToString:adName])
    {
        return [UnityAdsTool initWithViewController:viewController define:adDefine];
    }
    
    return nil;
}

- (void) showInterstitialAd
{
    for(id<AdProtocol> adTool in _tools[@AD_MODE_INTERSTITIAL])
    {
        if ([adTool showInterstitialAd])
        {
            break;
        }
    }
}

- (void) showInterstitialAdSuccess
{
    DeepseaTool::getInstance()->showInterstitialAdSuccess();
}

- (void) showInterstitialAdFail
{
    DeepseaTool::getInstance()->showInterstitialAdFail();
}

- (void) showVedioAd
{
    for(id<AdProtocol> adTool in _tools[@AD_MODE_VEDIO])
    {
        if ([adTool showVedioAd])
        {
            break;
        }
    }
}

- (void) showVedioAdSuccess
{
    DeepseaTool::getInstance()->showVedioAdSuccess();
}

- (void) showVedioAdFail
{
    DeepseaTool::getInstance()->showVedioAdFail();
}

+ (AdTool *)sharedInstance
{
    @synchronized (self)
    {
        if (!instance)
        {
            instance = [[AdTool alloc] init];
        }
    }
    return instance;
}

+ (id)allocWithZone:(struct _NSZone *)zone
{
    @synchronized(self)
    {
        if (!instance)
        {
            instance = [super allocWithZone:zone];
        }
    }
    return instance;
}

+ (id)copyWithZone:(struct _NSZone *)zone
{
    return instance;
}

@end
