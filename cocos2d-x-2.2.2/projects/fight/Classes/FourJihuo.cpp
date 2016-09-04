//
//  FourJihuo.cpp
//  kingYingJiFei
//
//  Created by mac on 14-7-1.
//
//

#include "FourJihuo.h"
#include "Define.h"
#include "Hero.h"
#include "Game.h"
#include "GameScene.h"
#include "GameData.h"
#include "SelectScene.h"
#include "MenuScene.h"
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

FourJihuo::FourJihuo()
{
    ispop = false;
}

bool FourJihuo::init()
{
    bg = CCSprite::create("dalibao/jihuotu.png");
    this->addChild(bg);
    bg->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.5));
    xiaocha = CCMenuItemImage::create("dalibao/x12.png", "dalibao/x22.png",this,menu_selector(FourJihuo::resume));
    goumai = CCMenuItemImage::create("dalibao/anniu1.png", "dalibao/anniu2.png",this,menu_selector(FourJihuo::buy));
    CCMenu* menu = CCMenu::create();
    this->addChild(menu);
    menu->setPosition(0, 0);
    menu->addChild(xiaocha);
    xiaocha->setPosition(ccp(SIZE.width*0.93, SIZE.height*0.93));
    menu->addChild(goumai);
    goumai->setPosition(ccp(SIZE.width*0.73, SIZE.height*0.38));
    Game::instance()->setFourJihuo(this);
    this->scheduleUpdate();
    return true;
}

CCScene* FourJihuo::scene(CCRenderTexture *sqr, bool isFlip )
{
    CCScene *scene = CCScene::create();
    FourJihuo* layer = FourJihuo::create();
    scene->addChild(layer,100);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite *_spr = CCSprite::createWithTexture(sqr->getSprite()->getTexture());
    _spr->setPosition(ccp(size.width / 2, size.height / 2));
    _spr->setFlipY(true);  //是否翻转
    _spr->setColor(ccGRAY);  //颜色（变灰暗）
    scene->addChild(_spr);
    return scene;
}

void FourJihuo::showInfo(int id)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo methodInfo;
    jobject jobj;
    bool isHave = JniHelper::getStaticMethodInfo(methodInfo, ANDROID_CLASS_NAME1,ANDROID_FUNCTION_NAME1,"(I)V");
    if (isHave)
    {
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, id);
    }else
    {
    }
#endif
}

void FourJihuo::buy(CCObject* pSender)
{
    showInfo(19);
    
    ispop = true;
}

void FourJihuo::resume(CCObject* pSender)
{
     CCDirector::sharedDirector()->replaceScene(MenuScene::scene() );
}

void FourJihuo::update(float dt)
{
    if (this->ispop)
    {
        this->jihuo();
    }
}

void FourJihuo::jihuo()
{
    gameLayer->juqingThreeEnd();
    Role->fuhuo();
    CCDirector::sharedDirector()->popScene();
    KingData->setIsJihuo(true);
    HUB->jihuo();
    CCUserDefault::sharedUserDefault()->setBoolForKey("isJihuo",KingData->getIsJihuo());
    CCUserDefault::sharedUserDefault()->flush();
}

