//
//  AdTool.h
//  vpn
//
//  Created by caoyusheng on 3/8/16.
//  Copyright © 2016年 caoyusheng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdDefine.h"

@interface AdTool : NSObject

+ (void) initWithViewController: (UIViewController *) viewController define:(AdDefine *)adDefine;

- (UIView *) createBanner;

- (void) showInterstitialAd;

- (void) showInterstitialAdSuccess;

- (void) showInterstitialAdFail;

- (void) showVedioAd;

- (void) showVedioAdSuccess;

- (void) showVedioAdFail;

@end

#define AD_CHANNEL_ADMOB "Admob"
#define AD_CHANNEL_UNITY_ADS "UnityAds"

#define AD_MODE_BANNER "banner"
#define AD_MODE_INTERSTITIAL "interstitial"
#define AD_MODE_VEDIO "vedio"
