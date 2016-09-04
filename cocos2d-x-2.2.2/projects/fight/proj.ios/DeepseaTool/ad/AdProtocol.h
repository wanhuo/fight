//
//  AdProtocol.h
//  vpn
//
//  Created by caoyusheng on 28/8/16.
//  Copyright © 2016年 caoyusheng. All rights reserved.
//

#ifndef AdProtocol_h
#define AdProtocol_h

#import <UIKit/UIKit.h>
#import "AdDefine.h"

@protocol AdProtocol <NSObject>

@required
+ (instancetype) initWithViewController: (UIViewController *) viewController define:(AdDefine *)adDefine;

@required
- (UIView *) createBanner;

@required
- (BOOL) showInterstitialAd;

@required
- (BOOL) showVedioAd;

@end

#define AD_TYPE_BANNER 0
#define AD_TYPE_INTERSTITIAL 1
#define AD_TYPE_VEDIO 2

#endif /* AdProtocol_h */
