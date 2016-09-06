//
//  ShopScene.cpp
//  king04
//
//  Created by mac on 14-5-15.
//
//

#include "ShopScene.h"
#include "HubShop.h"
#include "Game.h"
#include "SelectScene.h"
#include "Dalibao.h"
#include "DeepseaTool.h"


CCScene* ShopScene::scene()
{
    CCScene* scene = CCScene::create();
    ShopScene* layer = ShopScene::create();
    scene->addChild(layer);
    return scene;
}

bool ShopScene::init()
{
    if (!BaseLayer::init())
    {
        return false;
    }
    goumaiweizhi = 0;
    bg = CCSprite::create("shopsc/ditu.png");
    this->addChild(bg);
    bg->setPosition(ccp(SIZE.width/2, SIZE.height/2));
    
    nvrole = CCSprite::create("shopsc/nvrole.png");
    this->addChild(nvrole);
    nvrole->setPosition(ccp(SIZE.width*0.28, SIZE.height*0.28));
    nvrole->setAnchorPoint(ccp(0.5, 0));
   
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("shopsc/112121/112121.ExportJson");
    duboji = CCArmature::create("112121");
    this->addChild(duboji);
    duboji->setPosition(ccp(SIZE.width*0.2, SIZE.height*0.28));
    duboji->setAnchorPoint(ccp(0.5, 0));
    duboji->getAnimation()->playWithIndex(0);
    duboji->setScale(1.3f);
    
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("shopsc/baoxiang/baoxiang.ExportJson");
    baoxiang = CCArmature::create("baoxiang");
    this->addChild(baoxiang);
    baoxiang->setPosition(ccp(SIZE.width*0.65, SIZE.height*0.32));
    baoxiang->setAnchorPoint(ccp(0.5, 0));
    baoxiang->getAnimation()->playWithIndex(0);
    baoxiang->setScale(1.3f);
    
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("shopsc/texiao1/texiao1.ExportJson");
    texiao = CCArmature::create("texiao1");
    this->addChild(texiao);
    texiao->setPosition(ccp(SIZE.width*0.85, SIZE.height*0.12));
    texiao->setAnchorPoint(ccp(0.5, 0));
    texiao->getAnimation()->playWithIndex(0);
    texiao->setScale(1.3f);
    
    jinbi = CCSprite::create("shopsc/4321.png");
    jinbi->setPosition(ccp(SIZE.width*0.43, SIZE.height*0.32));
    jinbi->setAnchorPoint(ccp(0.5, 0));
    this->addChild(jinbi);
    jinbi->setScale(1.3f);
    
    jiantou = CCSprite::create("shopsc/5432.png");
    this->addChild(jiantou);
    jiantou->runAction(CCRepeatForever::create(CCSequence::create(CCMoveBy::create(0.5f, ccp(0, 20)),CCMoveBy::create(0.5f, ccp(0, -20)),NULL)) );
    
    jiantou->setPosition(ccpAdd( jinbi->getPosition() , ccp(0,jinbi->getContentSize().height + 25)));
    
    hero = Hero::create();
    this->addChild(hero, 101, 101);
    Game::instance()->setShopRole(hero);
    hero->setPosition(ccp(SIZE.width*0.5, SIZE.height*0.15));
    hero->setAnchorPoint(ccp(0.5, 0));
    hero->shadow2 = CCSprite::create("res/yingzi.png");
    this->addChild(hero->shadow2);
    
    
    HubShop* hub = HubShop::create();
    this->addChild(hub,102,102);
    this->scheduleUpdate();
    
//    DeepseaTool::getInstance()->showInterstitialAd();
    
    return true;
}

void ShopScene::update(float dt)
{
    updatePosition(dt);
}

void ShopScene::updatePosition(float dt)
{
    bool canRight = true;
    bool canLeft = true;
    
    if (hero->getPositionX() < SIZE.width*0.34)
    {
        goumaiweizhi = 0;
       
        
    }else if (hero->getPositionX() > SIZE.width*0.34 && hero->getPositionX() < SIZE.width*0.55)
    {
        goumaiweizhi = 1;
      
        
    }else if (hero->getPositionX() > SIZE.width*0.55)
    {
        goumaiweizhi = 2;
    }
    
    if (goumaiweizhi != oldgoumaiweizhi)
    {
        oldgoumaiweizhi = goumaiweizhi;
        
        if (goumaiweizhi == 0)
        {
            jiantou->setTexture(CCTextureCache::sharedTextureCache()->addImage("shopsc/shangcheng_shop.png"));
            jiantou->setPosition(ccpAdd( duboji->getPosition() , ccp(0,duboji->getContentSize().height*1.3 + 30)));
            
        }else if (goumaiweizhi == 1)
        {
            jiantou->setTexture(CCTextureCache::sharedTextureCache()->addImage("shopsc/5432.png"));
            jiantou->setPosition(ccpAdd( jinbi->getPosition() , ccp(0,jinbi->getContentSize().height*1.3 + 25)));
            
        }else if (goumaiweizhi == 2)
        {
            jiantou->setTexture(CCTextureCache::sharedTextureCache()->addImage("shopsc/jineng_shop.png"));
            jiantou->setPosition(ccpAdd( baoxiang->getPosition() , ccp(0,baoxiang->getContentSize().height*1.2 + 15)));
        }
    }
    
    if (hero->getPositionX()<100)
    {
        canLeft = false;
    }else if (hero->getPositionX() > SIZE.width - 100)
    {
        canRight = false;
    }
    
    int x = 0;
    int speed = hero->speedMain;
    switch (hero->orientation) {
        case  HOLDER:
            x = hero->getPositionX();
            if(!hero->oldPosition.equals(ccp(0,0))){
                
            }
            if (!canLeft)
            {
                x = hero->getPositionX();
            }else if (!canRight)
            {
                
            }else
            {
                
            }
            break;
            
        case LEFT:
            
            if (canLeft  /*&& Role->isBeAttack == false*/)
            {
                x = hero->getPositionX() - dt*speed;
                hero->move();
            }else{
                x = hero->getPositionX();
            }
            break;
        case RIGHT:
            if (canRight /*&& Role->isBeAttack == false*/)
            {
                x = hero->getPositionX() + dt*speed;
                hero->move();
            }else{
                x = hero->getPositionX();
            }
            break;
        default:
            break;
    }
    hero->setPositionX(x);
    if (hero->getBondingBox2().intersectsRect(texiao->boundingBox())  && hero->getPositionX() >texiao->getPositionX() + 10 )
    {
        this->unscheduleAllSelectors();
        CCDirector::sharedDirector()->replaceScene(SelectScene::scene());
    }
}

void ShopScene::dalibao()
{
    if (this->getChildByTag(dalibaotag)!=NULL)
    {
        return;
    }
    Dalibao* dalibao =  Dalibao::create(goumaiweizhi);
    dalibao->setPosition(ccp(0 , SIZE.height*1));
    dalibao->runAction(CCEaseIn::create(CCMoveTo::create(0.5f,ccp(0, 0) ) , 2) );
    this->addChild(dalibao,dalibaozorder,dalibaotag);
}


