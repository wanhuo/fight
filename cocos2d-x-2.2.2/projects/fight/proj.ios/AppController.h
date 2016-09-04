#import <UIKit/UIKit.h>

@class RootViewController;

@interface AppController : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
}

- (void) showTost: (NSString *)text;

@end

#define TAG_TOST_VIEW 62388
#define TAG_TOST_LABEL 62389

