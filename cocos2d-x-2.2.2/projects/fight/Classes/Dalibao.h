//
//  Dalibao.h
//  king04
//
//  Created by mac on 14-5-18.
//
//

#ifndef __king04__Dalibao__
#define __king04__Dalibao__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace gui;

class Dalibao : public CCLayer
{
public:
    
    static Dalibao* create(int idValue);
    bool init(int idValue);
    CCSprite* bg;
    CCMenuItem* xiaocha;
    CCMenuItem* goumai;
    CCMenuItem* duobi;
    CCMenuItem* shoushen;
    CCSprite* touming;
    CCSprite* touming2;
    CCSprite* xuanzekuang;
    void showInfo(int idValue);
    void buy(CCObject* pSender);
    void resume(CCObject* pSender);
    void duobiMenu(CCObject* pSender);
    void shoushenMenu(CCObject* pSender);
    void jinbi(CCObject* pSender);
    CCScene* scene(int idValue);
    int idValue;
    int libaoid;
    CCMenuItem* menu5888;
    CCMenuItem* menu2888;
    CCMenuItem* menu1888;
    
    CCSprite* yihuode;
    CCSprite* yihuode2;
    
    CCSprite* title;
    CCSprite* titleMoney;
    
    void buy2(float dt);
};

#endif /* defined(__king04__Dalibao__) */
