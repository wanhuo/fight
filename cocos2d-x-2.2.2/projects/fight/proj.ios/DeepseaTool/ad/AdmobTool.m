//
//  AdmobTool.m
//  vpn
//
//  Created by caoyusheng on 28/8/16.
//  Copyright © 2016年 caoyusheng. All rights reserved.
//

#import "AdmobTool.h"
#import "AdTool.h"
@import Firebase;
@import GoogleMobileAds;

@interface AdmobTool() <GADBannerViewDelegate, GADInterstitialDelegate>

@property(nonatomic, strong) UIViewController* viewController;

@property(nonatomic, strong) AdDefine* define;

@property(nonatomic, strong) GADInterstitial *admobInterstitial;

@property(nonatomic, assign) int adType;

@end

@implementation AdmobTool

static AdmobTool *instance = nil;

dispatch_queue_t dispatchSerialQueue;

+ (instancetype)initWithViewController:(id)viewController define:(AdDefine *)adDefine
{
    if (!instance)
    {
        instance = [AdmobTool alloc];
        
        [FIRApp configure];
        
        instance.viewController = viewController;
        instance.define = adDefine;
        
        [instance createInterstitial];
    }
    return instance;
}

- (UIView *)createBanner
{
    NSLog(@"%@", @"pre show admob banner");
    
    GADBannerView *bannerView = [[GADBannerView alloc] initWithAdSize:kGADAdSizeSmartBannerPortrait];
    bannerView.frame = CGRectMake(0.0,
                                  _viewController.view.frame.size.height -
                                  bannerView.frame.size.height,
                                  bannerView.frame.size.width,
                                  bannerView.frame.size.height);
    
    bannerView.adUnitID = [_define getAdmobBannerKey];
    bannerView.delegate = self;
    
    GADRequest *request = [GADRequest request];
//    request.testDevices = @[kGADSimulatorID];
    [bannerView setRootViewController:_viewController];
    [bannerView loadRequest:request];
    
    return bannerView;
}

- (void) createInterstitial
{
    self.admobInterstitial = [[GADInterstitial alloc] initWithAdUnitID:[_define getAdmobInterstitialKey]];
    self.admobInterstitial.delegate = self;
    [self loadAdmobInterstitial];
}

-(void)loadAdmobInterstitial
{
    GADRequest *request = [GADRequest request];
//    request.testDevices = @[kGADSimulatorID];
    [self.admobInterstitial loadRequest:request];
}

- (BOOL) showInterstitialAd
{
    if ([self.admobInterstitial isReady])
    {
        _adType = AD_TYPE_INTERSTITIAL;
        [self.admobInterstitial presentFromRootViewController: _viewController];
        return YES;
    }
    else
    {
        return NO;
    }
}

- (void)interstitialDidDismissScreen:(GADInterstitial *)ad
{
    ad.delegate = nil;
    [self createInterstitial];
    
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

- (void)interstitial:(GADInterstitial *)ad didFailToReceiveAdWithError:(GADRequestError *)error
{
    [self loadAdmobInterstitial];
    NSLog(@"didFailToReceiveAdWithError ------------ : %@", error.localizedDescription);
}

- (void)adView:(GADBannerView *)adView didFailToReceiveAdWithError:(GADRequestError *)error
{
    NSLog(@"adView:didFailToReceiveAdWithError ------------ : %@", error.localizedDescription);
}

- (BOOL) showVedioAd
{
    if ([self.admobInterstitial isReady])
    {
        _adType = AD_TYPE_VEDIO;
        [self.admobInterstitial presentFromRootViewController: _viewController];
        return YES;
    }
    else
    {
        return NO;
    }
}

+ (AdmobTool *)sharedInstance
{
    @synchronized (self)
    {
        if (!instance)
        {
            instance = [[AdmobTool alloc] init];
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
