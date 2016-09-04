//
//  Config.h
//  vpn
//
//  Created by caoyusheng on 28/8/16.
//  Copyright © 2016年 caoyusheng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToolDefine.h"

typedef void(^AfterLoadSuccess)(id result);

@interface Config : NSObject <NSURLSessionDelegate>

@property(strong, nonatomic, readonly) NSDictionary* data;

- (void) loadConfig:(ToolDefine *)define callback:(AfterLoadSuccess) callback;

- (NSInteger) getConfigVersion;

- (NSArray *) getConfigAds: (NSString *) adMode;

@end
