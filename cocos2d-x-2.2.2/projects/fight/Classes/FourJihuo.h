//
//  Jihuo.h
//  king04
//
//  Created by mac on 14-5-13.
//
//

#ifndef __king04__FourJihuo__
#define __king04__FourJihuo__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;


class FourJihuo : public CCLayer
{
public:
    FourJihuo();
    CREATE_FUNC(FourJihuo);
    bool init();
    static CCScene* scene(CCRenderTexture *sqr, bool isFlip );
    void resume(CCObject* pSender);
    void buy(CCObject* pSender);
    void showInfo(int id);
    void update(float dt);
    void jihuo();
    CCSprite* bg;
    CCMenuItem* xiaocha;
    CCMenuItem* goumai;
    CCSprite* background;
    bool ispop;
};

#endif /* defined(__king04__Jihuo__) */
