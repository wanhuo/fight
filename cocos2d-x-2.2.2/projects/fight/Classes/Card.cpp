//
//  Card.cpp
//  king04
//
//  Created by mac on 14-5-27.
//
//

#include "Card.h"
#include "ShopBuy.h"
#include "Define.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#endif
#define ANDROID_CLASS_NAME1 "com/game/fight/fight"
//"gedou/mofeng/cn/ooo"
#define ANDROID_FUNCTION_NAME1 "addXueTong"
//#define ANDROID_FUNCTION_NAME "charge"
#define ANDROID_PARAM_TYPE "(Ljava/lang/String;Ljava/lang/String;)V"

Card* Card::create(int id)
{
    Card* card = new Card();
    card->init(id);
    card->autorelease();
    return card;
}
bool Card::init(int id)
{
    if (!CCLayer::init())
    {
        return false;
    }
    this->id = id;
    
    background = CCSprite::create("dalibao/beijing.png");
    this->addChild(background);
    background->setPosition(ccp(SIZE.width/2, SIZE.height*0.5));
    bg = CCSprite::create(cards[id].c_str());
    this->addChild(bg);
    button = CCMenuItemImage::create("dalibao/goumai.png", "dalibao/goumai2.png", this,menu_selector(Card::huode));
    CCMenu* menu = CCMenu::create();
    this->addChild(menu);
    menu->setPosition(ccp(0, 0));
    menu->addChild(button);
	
    button->setPosition(ccp(SIZE.width/2, SIZE.height*0.25));
    bg->setPosition(ccp(SIZE.width/2, SIZE.height*0.52));
    xiaocha = CCMenuItemImage::create("dalibao/x1.png", "dalibao/x2.png",this,menu_selector(Card::remove));
    menu->addChild(xiaocha);
    xiaocha->setPosition(ccp(SIZE.width*0.77, SIZE.height*0.74));
    
    return true;
}

CCScene* Card::scene(CCRenderTexture *sqr, bool isFlip ,int id)
{
    CCScene *scene = CCScene::create();
    Card* layer = Card::create(id);
    scene->addChild(layer,100);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite *_spr = CCSprite::createWithTexture(sqr->getSprite()->getTexture());
    _spr->setPosition(ccp(size.width / 2, size.height / 2));
    _spr->setFlipY(true);  //ÊÇ·ñ·­×ª
    scene->addChild(_spr);
    return scene;
}

void Card::remove(CCObject* pSender)
{
	CCLog("Card::remove-->>");
    CCDirector::sharedDirector()->popScene();
}

void Card::huode(CCObject* pSender)
{
    CCLog("Card::huode-->>");
	/*
    this->setVisible(false);
    this->scheduleOnce(schedule_selector(Card::huode2 ), 0.5);
   */
    if (HUB!=NULL)
    {
        HUB->setVisible(false);
        gameLayer->setVisible(false);
    }
    
    
    CCLayerColor* layer = CCLayerColor::create(ccc4(0, 0, 0, 255), 800, 480);
    CCDirector::sharedDirector()->getRunningScene()->addChild(layer,10001,10001);
    Card::huode2(1.0);
}


void Card::huode2(float dt)
{
    CCLog("huode2-->>");
    if (this->id == 0)
    {
        showInfo(24);
    }else if (this->id == 1)
    {
        showInfo(8);
        CCDirector::sharedDirector()->pause();
    }else if (this->id == 2)
    {
        showInfo(9);
        CCDirector::sharedDirector()->pause();
    }else if (this->id == 3)
    {
        showInfo(23);
        CCDirector::sharedDirector()->pause();
    }
    CCDirector::sharedDirector()->popScene();
}


void Card::showInfo(int id)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo methodInfo;
    jobject jobj;
    bool isHave = JniHelper::getStaticMethodInfo(methodInfo, ANDROID_CLASS_NAME1,
                                                 ANDROID_FUNCTION_NAME1,
                                                 "(I)V");
    if (isHave)
    {
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, id);
        
    }else
    {
        
    }
#else
	

#endif
}








