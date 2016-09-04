//
//  Dalibao.cpp
//  king04
//
//  Created by mac on 14-5-18.
//
//
#include "DeepseaTool.h"
#include "Dalibao.h"
#include "Define.h"
#include "GameData.h"
#include "HubLayer.h"
#include "Hero.h"
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

Dalibao* Dalibao::create(int id)
{
    Dalibao* libao = new Dalibao();
    libao->init(id);
    libao->autorelease();
    return libao;
}

bool Dalibao::init(int idValue)
{
    this->idValue = idValue;
    switch (idValue) {
        case 0:
        {
            bg = CCSprite::create("dalibao/beijing.png");
            this->addChild(bg);
            bg->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.5));
            title = CCSprite::create("dalibao/libaobao.png");
            this->addChild(title);
            title->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.56));
            xiaocha = CCMenuItemImage::create("dalibao/x1.png", "dalibao/x2.png",this,menu_selector(Dalibao::resume));
            goumai = CCMenuItemImage::create("dalibao/goumai.png", "dalibao/goumai2.png",this,menu_selector(Dalibao::buy));
            CCMenu* menu = CCMenu::create();
            this->addChild(menu);
            menu->setPosition(0, 0);
            menu->addChild(xiaocha);
            xiaocha->setPosition(ccp(SIZE.width*0.82, SIZE.height*0.82));
            menu->addChild(goumai);
            goumai->setPosition(ccp(SIZE.width*0.50, SIZE.height*0.255));

        }
        break;
            
        case 1:
        {
            this->idValue = 1888;
            bg = CCSprite::create("dalibao/beijing.png");
            this->addChild(bg);
            bg->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.5));
            
            title = CCSprite::create("dalibao/goldwenzi.png");
            this->addChild(title);
            title->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.56));

            titleMoney = CCSprite::create("dalibao/4yuan.png");
            this->addChild(titleMoney);
            titleMoney->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.665));
            
            xiaocha = CCMenuItemImage::create("dalibao/x1.png", "dalibao/x2.png",this,menu_selector(Dalibao::resume));
            goumai = CCMenuItemImage::create("dalibao/goumai.png", "dalibao/goumai2.png",this,menu_selector(Dalibao::buy));
            CCMenu* menu = CCMenu::create();
            this->addChild(menu);
            menu->setPosition(0, 0);
            menu->addChild(xiaocha);
         
            xiaocha->setPosition(ccp(SIZE.width*0.82, SIZE.height*0.82));
            menu->addChild(goumai);
            goumai->setPosition(ccp(SIZE.width*0.50, SIZE.height*0.255));
            
            menu5888 = CCMenuItemImage::create("dalibao/5888jin.png", "dalibao/5888jin.png",this,menu_selector(Dalibao::jinbi));
            menu2888 = CCMenuItemImage::create("dalibao/2888jin.png", "dalibao/2888jin.png",this,menu_selector(Dalibao::jinbi));
            menu1888 = CCMenuItemImage::create("dalibao/1888jin.png", "dalibao/1888jin.png",this,menu_selector(Dalibao::jinbi));
            menu5888->setScale(1.2f);
            menu2888->setScale(1.2f);
            menu1888->setScale(1.2f);
            menu->addChild(menu1888);
            menu->addChild(menu2888);
            menu->addChild(menu5888);
            menu5888->setTag(2);
            menu1888->setTag(0);
            menu2888->setTag(1);
            menu1888->setPosition(SIZE.width*0.34, SIZE.height*0.52);
            menu2888->setPosition(SIZE.width*0.50, SIZE.height*0.52);
            menu5888->setPosition(SIZE.width*0.66, SIZE.height*0.52);
            xuanzekuang = CCSprite::create("dalibao/xuanzhongkuang.png");
            xuanzekuang->setPosition(ccpAdd( menu1888->getPosition(), ccp(0, 0)));
            this->addChild(xuanzekuang);
            xuanzekuang->runAction(CCRepeatForever::create(CCBlink::create(0.5, 1)));
            xuanzekuang->setScale(1.1f);
        }
            break;
        case 2:
        {
            bg = CCSprite::create("dalibao/beijing.png");
            this->addChild(bg);
            bg->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.5));
            
            title = CCSprite::create("dalibao/huodedalibao.png");
            this->addChild(title);
            title->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.56));
            
            xiaocha = CCMenuItemImage::create("dalibao/x1.png", "dalibao/x2.png",this,menu_selector(Dalibao::resume));
            goumai = CCMenuItemImage::create("dalibao/goumai.png", "dalibao/goumai2.png",this,menu_selector(Dalibao::buy));
            touming = CCSprite::create("shop/yihuode.png");
            touming2 = CCSprite::create("shop/yihuode.png");            xuanzekuang = CCSprite::create("dalibao/xuanzhongkuang.png");
            duobi = CCMenuItemImage::create("dalibao/jineng11.png", "dalibao/jineng11.png",this,menu_selector(Dalibao::duobiMenu));
            shoushen = CCMenuItemImage::create("dalibao/jineng255.png", "dalibao/jineng255.png",this,menu_selector(Dalibao::shoushenMenu));
            
            CCMenu* menu = CCMenu::create();
            this->addChild(menu,2);
            menu->setPosition(0, 0);
            menu->addChild(xiaocha);
            xiaocha->setPosition(ccp(SIZE.width*0.82, SIZE.height*0.82));
            menu->addChild(goumai);
            goumai->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.26));
            
            this->addChild(touming,1000);
            this->addChild(touming2,1000);
            touming->setScale(0.7);
            touming2->setScale(0.7);
            this->addChild(xuanzekuang);
            menu->addChild(duobi,2);
            menu->addChild(shoushen,2);
            
            duobi->setPosition(ccp(SIZE.width*0.35, SIZE.height*0.55));
            shoushen->setPosition(ccp(SIZE.width*0.65, SIZE.height*0.55));
            xuanzekuang->setPosition(ccpAdd( duobi->getPosition(), ccp(0,0)));
            xuanzekuang->runAction(CCRepeatForever::create(CCBlink::create(0.5, 1)));
 
            this->idValue = 1000;   //¶ã±Ü
            
            if (KingData->getJinjiDuobi() && KingData->getShoushen())
            {
                xuanzekuang->stopAllActions();
                xuanzekuang->setVisible(false);
                touming->setPosition(ccpAdd(shoushen->getPosition(),ccp(0,0)));
                touming2->setPosition(ccpAdd(duobi->getPosition(),ccp(0,0)));
                this->idValue = 3000;  //¶ã±Ü
            }else
            {
                if (KingData->getJinjiDuobi())
                {
                    
                    touming->setPosition(ccpAdd(duobi->getPosition(),ccp(0,0)));
                    xuanzekuang->setPosition(ccpAdd( shoushen->getPosition(), ccp(0,0)));
                    this->idValue = 2000;  //ÊÝÉí
                }else
                {
                    touming->setVisible(false);
                }
                if (KingData->getShoushen())
                {
                    touming2->setPosition(ccpAdd(shoushen->getPosition(),ccp(0,0)));
                    xuanzekuang->setPosition(ccpAdd( duobi->getPosition(), ccp(0,0)));
                    this->idValue = 1000;  //¶ã±Ü
                }else
                {
                    touming2->setVisible(false);
                }
            }
            libaoid = 1;
        }
            break;
        default:
            break;
    }
    return true;
}

void Dalibao::jinbi(CCObject* pSender)
{
    this->removeChild(titleMoney);
    CCMenuItem* item = dynamic_cast<CCMenuItem*>(pSender);
    int tag = item->getTag();
    if (tag == 0)
    {
        titleMoney = CCSprite::create("dalibao/4yuan.png");
        this->addChild(titleMoney);
        titleMoney->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.665));
        this->idValue = 1888;
        xuanzekuang->setPosition(ccpAdd( menu1888->getPosition(), ccp(0, 0)));
    }else if (tag == 1)
    {
        titleMoney = CCSprite::create("dalibao/10yuan.png");
        this->addChild(titleMoney);
        titleMoney->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.665));
        this->idValue = 2888;
        xuanzekuang->setPosition(ccpAdd( menu2888->getPosition(), ccp(0, 0)));
    }else if (tag == 2)
    {
        titleMoney = CCSprite::create("dalibao/20yuan.png");
        this->addChild(titleMoney);
        titleMoney->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.665));
        this->idValue = 5888;
        xuanzekuang->setPosition(ccpAdd( menu5888->getPosition(), ccp(0, 0)));
    }
}


void Dalibao::duobiMenu(CCObject* pSender)
{
    
    if (KingData->getJinjiDuobi() && KingData->getShoushen())
    {
        this->removeFromParent();
        showInfo(28);
        return;
    }
    if (KingData->getJinjiDuobi())
    {
        touming->setPosition(ccpAdd(shoushen->getPosition(),ccp(0,0)));
        xuanzekuang->setPosition(ccpAdd( shoushen->getPosition(), ccp(0,0)));
        this->idValue = 2000;  //ÊÝÉí
    }else
    {
        xuanzekuang->setPosition(ccpAdd( duobi->getPosition(), ccp(0,0)));
        this->idValue = 1000;  //shoushen
        touming->setVisible(false);
    }

}

void Dalibao::shoushenMenu(CCObject* pSender)
{
    if (KingData->getJinjiDuobi() && KingData->getShoushen())
    {
        this->removeFromParent();
        showInfo(28);
        return;
    }
    if (KingData->getShoushen())
    {
        touming2->setPosition(ccpAdd(duobi->getPosition(),ccp(0,0)));
        xuanzekuang->setPosition(ccpAdd( duobi->getPosition(), ccp(0,0)));
        this->idValue = 1000;  //¶ã±Ü
        return;
    }else
    {
        xuanzekuang->setPosition(ccpAdd( shoushen->getPosition(), ccp(0,0)));
         this->idValue = 2000;  //shoushen
        touming2->setVisible(false);
    }
}


CCScene* Dalibao::scene(int id)
{
    CCScene *scene = CCScene::create();
    Dalibao* layer = Dalibao::create(id);
    scene->addChild(layer,100);
    return scene;
}

void Dalibao::showInfo(int id)
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


void Dalibao::buy2(float dt)
{
    switch (this->idValue)
    {
        case 0:
            showInfo(16);
            break;
        case 1:
            showInfo(21);
            break;
        case 2:
            showInfo(22);
            break;
        case 1888:
            showInfo(25);
            break;
        case 2888:
        {
            showInfo(26);
            break;
        }
        case 5888:
        {
            showInfo(27);
            break;
        }
        case 1000:
        {
            if (KingData->getMoney() < 10000)
            {
                DeepseaTool::getInstance()->showMoneyErrorTost();
                showInfo(1);
            }else
            {
                KingData->setJinjiDuobi(true);
                KingData->alterMoney(-10000);
                CCUserDefault::sharedUserDefault()->setBoolForKey("jinjiduobi",true);
                CCUserDefault::sharedUserDefault()->flush();
                CCUserDefault::sharedUserDefault()->purgeSharedUserDefault();
                DeepseaTool::getInstance()->showBuySuccessTost();
                showInfo(29);
            }
            break;
        }
        case 2000:
        {
            if (KingData->getMoney() < 5000)
            {
                DeepseaTool::getInstance()->showMoneyErrorTost();
                showInfo(1);
            }else
            {
                KingData->setShoushen(true);
                KingData->alterMoney(-5000);
                CCUserDefault::sharedUserDefault()->setBoolForKey("shoushen",true);
                CCUserDefault::sharedUserDefault()->flush();
                CCUserDefault::sharedUserDefault()->purgeSharedUserDefault();
                DeepseaTool::getInstance()->showBuySuccessTost();
                showInfo(30);
            }
            break;
        }
        case 3000:
        {
            showInfo(28);
            break;
        }
        default:
            break;
    }
    this->removeFromParent();
}

void Dalibao::buy(CCObject* pSender)
{
    this->setVisible(false);
    this->buy2(0);
//    this->scheduleOnce(schedule_selector(Dalibao::buy2 ), 0.2f);
//    CCLayerColor* layer = CCLayerColor::create(ccc4(0, 0, 0, 255), 800, 480);
//    CCDirector::sharedDirector()->getRunningScene()->addChild(layer,10001,10001);

}

void Dalibao::resume(CCObject* pSender)
{
    PersonalAudioEngine::sharedEngine()->playEffect("music/backSound.wav");
    this->removeFromParent();
}


