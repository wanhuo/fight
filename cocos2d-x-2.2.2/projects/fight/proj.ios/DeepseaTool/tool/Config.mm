//
//  Config.m
//  vpn
//
//  Created by caoyusheng on 28/8/16.
//  Copyright © 2016年 caoyusheng. All rights reserved.
//

#import "Config.h"
#import "AdTool.h"
#include "ConfigStore.hpp"

@interface Config()

@property (nonatomic, strong, readonly) ToolDefine *define;

@end

@implementation Config

static Config *instance = nil;

- (void) loadConfig:(ToolDefine *)define callback:(AfterLoadSuccess)callback
{
    _define = define;
    
    @try
    {
        [self load: callback];
    }
    @catch (NSException * e)
    {
        callback(nil);
        NSLog(@"Exception: %@", e);
    }
}

- (void) load: (AfterLoadSuccess)callback
{
    NSString *strUrl = [NSString stringWithFormat:@"%@?version=%ld", [_define getConfigUrl], (long)[_define getAppVersion]];
    NSURL *url = [NSURL URLWithString: strUrl];
    NSMutableURLRequest * request = [NSMutableURLRequest requestWithURL:url cachePolicy:NSURLRequestUseProtocolCachePolicy timeoutInterval:3];
    [request setHTTPMethod:@"GET"];
    
    NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:configuration delegate:self delegateQueue:nil];
    
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *taskData, NSURLResponse *taskResponse, NSError *taskConnectionError)
    {
        dispatch_semaphore_signal(semaphore);
        if (!taskConnectionError)
        {
            NSInteger statusCode = [(NSHTTPURLResponse *)taskResponse statusCode];
            if (statusCode == 200)
            {
                NSError * error;
                NSDictionary *resDict = [NSJSONSerialization JSONObjectWithData:taskData options:NSJSONReadingMutableLeaves error:&error];
                if (resDict)
                {
                    _data = resDict;
                    NSDictionary *configDict = [self getConfigDict];
                    if (configDict)
                    {
                        ConfigStore::getInstance()->configVersion = [configDict[@"version"] integerValue];
                    }
                }
            }
        }
        callback(_data);
    }];
    [dataTask resume];
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
}

- (NSArray *) getConfigAds: (NSString *) adMode
{
    NSArray *ads = @[@AD_CHANNEL_ADMOB];
    NSDictionary *configDict = [self getConfigDict];
    if (configDict && configDict[adMode])
    {
        ads = configDict[adMode];
    }
    return ads;
}

- (NSDictionary *) getConfigDict
{
    NSDictionary *dict = nil;
    if (_data)
    {
        dict = _data[[_define getChannel]];
    }
    return dict;
}


+ (Config*)sharedInstance
{
    @synchronized (self)
    {
        if (!instance)
        {
            instance = [[Config alloc] init];
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
