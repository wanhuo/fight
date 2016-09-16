//
//  Tool.h
//  vpn
//
//  Created by caoyusheng on 2/8/16.
//  Copyright © 2016年 caoyusheng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ToolDefine.h"

typedef void(^AfterInitTool)(id result);

@interface Tool : NSObject

@property (assign, nonatomic) BOOL isReplyLater;

+ (void) initWithViewController: (UIViewController *) viewController define:(ToolDefine *)define callback:(AfterInitTool)callback;

- (void) initUm;

- (BOOL) isReply;

- (void) share: (UIViewController *) viewController;

- (void) reply;

- (void) showReplyDialog;

- (BOOL) isNetWorkOk;

@end

#define REPLY_KWY_CHIN "REPLY_KWY_CHIN"
