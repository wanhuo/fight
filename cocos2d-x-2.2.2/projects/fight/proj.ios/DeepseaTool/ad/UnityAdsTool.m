//
//  UnityAdsTool.m
//  vpn
//
//  Created by caoyusheng on 28/8/16.
//  Copyright © 2016年 caoyusheng. All rights reserved.
//

#import "UnityAdsTool.h"
#import <UnityAds/UnityAds.h>
#import "AdTool.h"

@interface UnityAdsTool() <UnityAdsDelegate>


@property(nonatomic, strong) UIViewController* viewController;

@property(nonatomic, strong) AdDefine* define;

@property(nonatomic, assign) int adType;

@end

@implementation UnityAdsTool

static UnityAdsTool *instance = nil;

+ (instancetype)initWithViewController:(id)viewController define:(AdDefine *)adDefine
{
    if (!instance)
    {
        instance = [UnityAdsTool alloc];
        
        instance.viewController = viewController;
        instance.define = adDefine;
        
        [[UnityAds sharedInstance] startWithGameId:[adDefine getUnityGameId] andViewController:viewController];
        [[UnityAds sharedInstance] setDelegate:instance];
    }
    return instance;
}

- (UIView *) createBanner
{
    return nil;
}

- (void)unityAdsVideoCompleted:(NSString *)rewardItemKey skipped:(BOOL)skipped
{
    
}

- (void)unityAdsDidHide
{
    switch (_adType)
    {
        case AD_TYPE_INTERSTITIAL:
            [[AdTool alloc] showInterstitialAdSuccess];
            break;
        case AD_TYPE_VEDIO:
            [[AdTool alloc] showVedioAdSuccess];
            break;
        default:
            break;
    }
}

- (BOOL) showInterstitialAd
{
    if ([[UnityAds sharedInstance] setZone:@"defaultZone"] && [[UnityAds sharedInstance]canShowZone:@"defaultZone"])
    {
        _adType = AD_TYPE_INTERSTITIAL;
        [[UnityAds sharedInstance] show];
        return YES;
    }
    else
    {
        return NO;
    }
}

- (BOOL)showVedioAd
{
    if ([[UnityAds sharedInstance] setZone:@"rewardedVideoZone"] && [[UnityAds sharedInstance]canShowZone:@"rewardedVideoZone"])
    {
        _adType = AD_TYPE_VEDIO;
        [[UnityAds sharedInstance] show];
        return YES;
    }
    else
    {
        return NO;
    }
}

+ (UnityAdsTool *)sharedInstance
{
    @synchronized (self)
    {
        if (!instance)
        {
            instance = [[UnityAdsTool alloc] init];
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
