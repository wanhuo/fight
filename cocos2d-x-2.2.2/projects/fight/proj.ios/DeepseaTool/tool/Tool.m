//
//  Tool.m
//  vpn
//
//  Created by caoyusheng on 2/8/16.
//  Copyright © 2016年 caoyusheng. All rights reserved.
//

#import "Tool.h"
#import "Config.h"
#import "KeychainItemWrapper.h"
#import "UMMobClick/MobClick.h"

@interface Tool()

@property (nonatomic, strong) ToolDefine *define;

@end

@implementation Tool

static Tool *instance = nil;

+ (void) initWithDefine: (ToolDefine *)define callback:(AfterInitTool)callback
{
    if (!instance)
    {
        instance = [Tool alloc];
        instance.define = define;
        [instance initUm];
        
        [[Config alloc] loadConfig:define callback:^(id result) {
            callback(result);
        }];
    }
}

- (void)initUm
{
    UMConfigInstance.appKey = [_define getUMKey];
    UMConfigInstance.channelId = [_define getChannel];
    [MobClick setLogEnabled:YES];
    [MobClick startWithConfigure:UMConfigInstance];
}

- (BOOL) isVIP
{
    return [self isReply];
}

- (BOOL) isReply
{
    NSInteger appVersion = [_define getAppVersion];
    NSInteger remoteVersion = [[Config alloc] getConfigVersion];
    
    if (remoteVersion > 0 && appVersion < remoteVersion)
    {
        KeychainItemWrapper *keyChin = [[KeychainItemWrapper alloc]initWithIdentifier:@REPLY_KWY_CHIN accessGroup:nil];
        return [@REPLY_KWY_CHIN isEqualToString:[keyChin objectForKey:(__bridge id)kSecValueData]];
    }
    else
    {
        return YES;
    }
}

- (void) reply
{
    NSString *templateReviewURL = @"itms-apps://ax.itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?type=Purple+Software&id=APP_ID";
    NSString *templateReviewURLiOS7 = @"itms-apps://itunes.apple.com/app/idAPP_ID";
    NSString *templateReviewURLiOS8 = @"itms-apps://itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?id=APP_ID&onlyLatestVersion=true&pageNumber=0&sortOrdering=1&type=Purple+Software";
    NSString *appId = [_define getAppId];
    
    NSString *reviewURL = [templateReviewURL stringByReplacingOccurrencesOfString:@"APP_ID" withString:[NSString stringWithFormat:@"%@", appId]];
    
    // iOS 7 needs a different templateReviewURL @see https://github.com/arashpayan/appirater/issues/131
    // Fixes condition @see https://github.com/arashpayan/appirater/issues/205
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0 && [[[UIDevice currentDevice] systemVersion] floatValue] < 8.0) {
        reviewURL = [templateReviewURLiOS7 stringByReplacingOccurrencesOfString:@"APP_ID" withString:[NSString stringWithFormat:@"%@", appId]];
    }
    // iOS 8 needs a different templateReviewURL also @see https://github.com/arashpayan/appirater/issues/182
    else if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
    {
        reviewURL = [templateReviewURLiOS8 stringByReplacingOccurrencesOfString:@"APP_ID" withString:[NSString stringWithFormat:@"%@", appId]];
    }
    
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:reviewURL]];
    
    KeychainItemWrapper * keyChin = [[KeychainItemWrapper alloc]initWithIdentifier:@REPLY_KWY_CHIN accessGroup:nil];
    [keyChin setObject: @REPLY_KWY_CHIN forKey:(id)kSecAttrService];
    [keyChin setObject: @REPLY_KWY_CHIN forKey:(__bridge id)kSecAttrAccount];
    [keyChin setObject: @REPLY_KWY_CHIN forKey:(__bridge id)kSecValueData];
}

- (void) clearKeyChin
{
    KeychainItemWrapper * keyChin = [[KeychainItemWrapper alloc]initWithIdentifier:@REPLY_KWY_CHIN accessGroup:nil];
    [keyChin setObject: @"1" forKey:(id)kSecAttrService];
    [keyChin setObject: @"2" forKey:(__bridge id)kSecAttrAccount];
    [keyChin setObject: @"3" forKey:(__bridge id)kSecValueData];
}

- (void) share: (UIViewController *) viewController
{
    NSString *textToShare = [_define getShareText];
    
    UIImage *imageToShare = [UIImage imageNamed: [_define getShareLogo]];
    
    NSURL *urlToShare = [NSURL URLWithString: [NSString stringWithFormat:@"https://itunes.apple.com/app/id%@", [_define getAppId]]];
    
    NSArray *activityItems = @[textToShare, imageToShare, urlToShare];
    
    UIActivityViewController *activityVC = [[UIActivityViewController alloc] initWithActivityItems:activityItems applicationActivities:nil];
    
    activityVC.excludedActivityTypes = @[UIActivityTypePrint, UIActivityTypeCopyToPasteboard,
                                         
                                         UIActivityTypeAssignToContact,UIActivityTypeSaveToCameraRoll];
    
    [viewController presentViewController:activityVC animated:TRUE completion:nil];
}

- (BOOL) isNetWorkOk
{
    UIApplication *app = [UIApplication sharedApplication];
    NSArray *children = [[[app valueForKeyPath:@"statusBar"]valueForKeyPath:@"foregroundView"]subviews];
    int netType = 0;
    for (id child in children) {
        if ([child isKindOfClass:NSClassFromString(@"UIStatusBarDataNetworkItemView")]) {
            netType = [[child valueForKeyPath:@"dataNetworkType"]intValue];
            switch (netType) {
                case 0:
                case 1:
                    return NO;
                case 2:
                case 3:
                case 5:
                    return YES;
                default:
                    break;
            }
        }
    }
    return NO;
}

+ (Tool *)sharedInstance
{
    @synchronized (self)
    {
        if (!instance)
        {
            instance = [[Tool alloc] init];
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
