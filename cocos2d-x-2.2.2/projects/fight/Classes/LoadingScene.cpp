//
//  LoadingScene.cpp
//  GedouKing
//
//  Created by mac on 14-3-26.
//
//

#include "LoadingScene.h"
#include "Define.h"
#include  "MenuScene.h"
#include "SelectScene.h"

bool LoadingScene::init()
{
    if ( !BaseLayer::init() )
    {
        return false;
    }
    
    CCSprite* lovegame = CCSprite::create("play.cn.logo.png");
    this->addChild(lovegame,100);
    lovegame->setPosition(ccp(SIZE.width/2, SIZE.height/2));
    lovegame->runAction(CCSequence::create(CCDelayTime::create(0.9f),CCFadeOut::create(0.1f),NULL) );
    
    this->scheduleOnce(schedule_selector(LoadingScene::loadingBack), 0.92f);
    
    
    return true;
}

void LoadingScene::Loading_Over(float dt)
{
    
}

void LoadingScene::loadingBack(float dt)
{
    CCScene* scene =  CCTransitionFade::create(0.1f,MenuScene::scene());
    CCDirector::sharedDirector()->replaceScene(scene);
}
cocos2d::CCScene* LoadingScene::scene()
{
    
    CCScene *scene = CCScene::create();
    
    LoadingScene *layer = LoadingScene::create();
    
    scene->addChild(layer);
    
    return scene;
}
