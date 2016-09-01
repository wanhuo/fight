//
//  Jihuo.cpp
//  king04
//
//  Created by mac on 14-5-13.
//
//

#include "Jihuo.h"
#include "Define.h"
#include "Hero.h"
#include "Game.h"
#include "GameScene.h"
#include "GameData.h"
#include "SelectScene.h"
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

Jihuo::Jihuo()
{
    ispop = false;
}

bool Jihuo::init()
{

    background = CCSprite::create("dalibao/beijing.png");
    this->addChild(background);
    background->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.5));
    
    bg = CCSprite::create("dalibao/onlineLibao.png");
    this->addChild(bg);
    bg->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.5));
    
    xiaocha = CCMenuItemImage::create("dalibao/x1.png", "dalibao/x2.png",this,menu_selector(Jihuo::resume));
    goumai = CCMenuItemImage::create("dalibao/goumai.png", "dalibao/goumai2.png",this,menu_selector(Jihuo::buy));
    CCMenu* menu = CCMenu::create();
    this->addChild(menu);
    menu->setPosition(0, 0);
    menu->addChild(xiaocha);
    
    xiaocha->setPosition(ccp(SIZE.width*0.82, SIZE.height*0.82));
    menu->addChild(goumai);
    goumai->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.22));

    return true;
}

CCScene* Jihuo::scene(CCRenderTexture *sqr, bool isFlip )
{
    CCScene *scene = CCScene::create();
    Jihuo* layer = Jihuo::create();
    scene->addChild(layer,100);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite *_spr = CCSprite::createWithTexture(sqr->getSprite()->getTexture());
    _spr->setPosition(ccp(size.width / 2, size.height / 2));
    _spr->setFlipY(true);  //是否翻转
    _spr->setColor(ccGRAY);  //颜色（变灰暗）
    scene->addChild(_spr);
    return scene;
}

void Jihuo::showInfo(int id)
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
#endif
}

void Jihuo::buy(CCObject* pSender)
{
    
    this->scheduleOnce(schedule_selector(Jihuo::buy2 ), 0.1);
    
    if (HUB!=NULL)
    {
        HUB->setVisible(false);
        gameLayer->setVisible(false);
    }
    
    
    CCLayerColor* layer = CCLayerColor::create(ccc4(0, 0, 0, 255), 800, 480);
    CCDirector::sharedDirector()->getRunningScene()->addChild(layer,10001,10001);
  
}

void Jihuo::buy2(float dt)
{
    
    showInfo(32);
    this->removeFromParent();
}
void Jihuo::resume(CCObject* pSender)
{
    this->removeFromParent();
}

void Jihuo::update(float dt)
{
    if (this->ispop)
    {
        this->jihuo();
    }
}

void Jihuo::jihuo()
{
    gameLayer->juqingThreeEnd();
    Role->fuhuo();
    CCDirector::sharedDirector()->popScene();
    KingData->setIsJihuo(true);
    HUB->jihuo();
    CCUserDefault::sharedUserDefault()->setBoolForKey("isJihuo",KingData->getIsJihuo());
    CCUserDefault::sharedUserDefault()->flush();
}

