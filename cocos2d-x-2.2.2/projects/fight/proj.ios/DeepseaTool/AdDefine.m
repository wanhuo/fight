//
//  VpnAdDefine.m
//  vpn
//
//  Created by caoyusheng on 28/8/16.
//  Copyright © 2016年 caoyusheng. All rights reserved.
//

#import "AdDefine.h"

@implementation AdDefine : NSObject

static AdDefine *instance = nil;

- (NSString *) getAdmobBannerKey
{
    return @"ca-app-pub-1463754682473987/6142889158";
}

- (NSString *) getAdmobInterstitialKey
{
    return @"ca-app-pub-1463754682473987/4666155957";
}

- (NSString *) getAdmobVedioKey
{
    return @"ca-app-pub-1463754682473987/1879519551";
}

- (NSString *) getUnityGameId
{
    return @"127514";
}

+(AdDefine *)sharedInstance
{
    @synchronized (self)
    {
        if (!instance)
        {
            instance = [[AdDefine alloc] init];
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
