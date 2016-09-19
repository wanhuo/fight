//
//  ToolDefine.m
//  vpn
//
//  Created by caoyusheng on 28/8/16.
//  Copyright © 2016年 caoyusheng. All rights reserved.
//

#import "ToolDefine.h"

@implementation ToolDefine

static ToolDefine *instance = nil;

- (NSString *)getAppId
{
    return @APP_ID;
}

- (NSString *)getShareLogo
{
    return @"logo";
}

- (NSString *)getShareText
{
    return @"一起来玩Fight吧，好玩!";
}

- (NSString *)getUMKey
{
    return @"57c8362ae0f55a5d680015d9";
}

- (NSString *)getChannel
{
    return @CHANNEL;
}

- (NSInteger)getAppVersion
{
    return [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"] integerValue];
}

- (NSString *)getConfigUrl
{
    return @"http://www.gameconfig.applinzi.com/fight/config.php";
}

+(ToolDefine *)sharedInstance
{
    @synchronized (self)
    {
        if (!instance)
        {
            instance = [[ToolDefine alloc] init];
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
