//
//  LoadingLayer.cpp
//  king04
//
//  Created by mac on 14-5-15.
//
//
#include "GameScene.h"
#include "LoadingLayer.h"
#include "Define.h"
bool LoadingLayer::init(int current_Select, int modeid)
{
    if ( !BaseLayer::init() )
    {
        return false;
    }
    this->current_Select = current_Select;
    this->modeid = modeid;
    char json[50] = {0};
    sprintf( json, "%s/%s.ExportJson","meinvdazhan","meinvdazhan");
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(json);
    meinv = CCArmature::create("meinvdazhan");
    meinv->getAnimation()->playWithIndex(0);
    this->addChild(meinv);
    meinv->setPosition(ccp(SIZE.width/2, SIZE.height*0.53));
    meinv->setAnchorPoint(ccp(0.5, 0.5));
    label = UILabel::create();
    label->setFontName("ËÎÌו");
    label->setFontSize(16);
    label->setPosition(ccp(SIZE.width/2, SIZE.height*0.35));
    label->setAnchorPoint(ccp(0.5, 1));
    label->setColor(ccc3(0xee, 0xee, 0xee));
    int ran = CCRANDOM_0_1()*5;

	int a[] = {13,14,15,16,17};

    //label->setText(loadingTips[ran]);
    CCLog("LoadingLayer::init---%s,%d",I18N_STR(a[ran]),ran);
    label->setText(I18N_STR(a[ran]));
    this->addChild(label);
    this->scheduleOnce(schedule_selector(LoadingLayer::Loading_Over), 3.0f);
    return true;
}

CCScene* LoadingLayer::scene(int current_Select, int modeid)
{
    CCScene *scene = CCScene::create();
    LoadingLayer *layer = LoadingLayer::create(current_Select,modeid);
    scene->addChild(layer);
    return scene;
}

LoadingLayer* LoadingLayer::create(int current_Select, int modeid)
{
    LoadingLayer* LAYER = new LoadingLayer();
    LAYER->init(current_Select, modeid);
    LAYER->autorelease();
    return LAYER;
}

void LoadingLayer::loadingBack(CCObject* pSender)
{
    
}

void LoadingLayer::Loading_Over(float dt)
{
    CCDirector::sharedDirector()->replaceScene(GameScene::scene(current_Select,modeid));
}


