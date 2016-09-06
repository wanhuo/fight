//
//  MenuLayer.cpp
//  King
//
//  Created by mac on 14-3-30.
//
//

#include "MenuLayer.h"
#include "GameScene.h"
#include "Define.h"
#include "MenuScene.h"
#include "GameData.h"
#include "ShopScene.h"
#include "DeepseaTool.h"
USING_NS_CC;

CCScene* MenuLayer::scene(CCRenderTexture* sqr)
{
    CCScene *scene = CCScene::create();
    MenuLayer* layer = MenuLayer::create(2);
    scene->addChild(layer,100);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite *_spr = CCSprite::createWithTexture(sqr->getSprite()->getTexture());
    _spr->setPosition(ccp(size.width / 2, size.height / 2));
    _spr->setFlipY(true);
    _spr->setColor(ccGRAY);
    scene->addChild(_spr);
    return scene;
}

CCScene* MenuLayer::scene(int id)
{
    CCScene *scene = CCScene::create();
    MenuLayer* layer = MenuLayer::create(id);
    scene->addChild(layer,100);
    return scene;
}

MenuLayer* MenuLayer::create(int id)
{
    MenuLayer* layer = new MenuLayer();
    layer->autorelease();
    layer->init(id);
    return layer;
}

bool MenuLayer::init(int id)
{
    if(CCLayer::init()){
        
        this->id = id;
        this->setTouchEnabled(true);
        bg = CCScale9Sprite::create("shop/scnl_dk1.png");
        this->addChild(bg);
        bg->setPosition(ccp(SIZE.width/2, SIZE.height/2));
        bg->setContentSize(CCSize(SIZE.width*0.9,SIZE.height*0.8));
        this->createMenu();
        return true;
    }
    return false;
}

void MenuLayer::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-129,true);
}

bool MenuLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
 
    if(this->isVisible())
    {
        if(sound_music->boundingBox().containsPoint(pTouch->getLocation()));
        {
            return false;
        }
        return true;
    }else
    {
        return false;
    }
}
void MenuLayer::createBackground()
{
    CCLayerColor* colorBackground = CCLayerColor::create(ccc4(0, 0, 0, 128));
    this->addChild(colorBackground);
}
void MenuLayer::createMenu()
{
   

    CCSprite* pause = CCSprite::create("pause/yxzt.png");
    this->addChild(pause);
    pause->setPosition(ccp(SIZE.width/2,SIZE.height*0.75));
    
    CCSprite* pause_lb = CCSprite::create("pause/yxzt_lb.png");
    this->addChild(pause_lb);
    pause_lb->setPosition(ccp(SIZE.width/2,SIZE.height*0.6));
    pause_lb->setScale(1.5f);
    
    CCSprite* pause_yy = CCSprite::create("pause/yxzt_yy.png");
    this->addChild(pause_yy);
    pause_yy->setPosition(ccp(SIZE.width/2,SIZE.height*0.4));
    pause_yy->setScale(1.5f);
    
    CCMenu* menu = CCMenu::create();
    duihao = CCMenuItemImage::create("pause/yxzt_dh.png","pause/yxzt_dh.png");
    cuohao = CCMenuItemImage::create("pause/yxzt_xh.png", "pause/yxzt_xh.png");
    
    bool flag = KingData->getSoundVolume()>0;
    if (flag) {
         sound_music = CCMenuItemToggle::createWithTarget(this,  menu_selector(MenuLayer::sound),duihao,  cuohao,NULL);
    }else
    {
         sound_music = CCMenuItemToggle::createWithTarget(this,  menu_selector(MenuLayer::sound),cuohao,  duihao,NULL);
    }
    
    menu->addChild(sound_music);
    sound_music->setPosition(ccp( 100+SIZE.width/2,SIZE.height*0.6));
    duihao->setScale(1.5f);
    cuohao->setScale(1.5f);
    
    duihao1 = CCMenuItemImage::create("pause/yxzt_dh.png","pause/yxzt_dh.png");
    cuohao1 = CCMenuItemImage::create("pause/yxzt_xh.png", "pause/yxzt_xh.png");
    
    bool flag2 = KingData->getMusicVolume() > 0;
    if (flag2) {
         music_sound = CCMenuItemToggle::createWithTarget(this,  menu_selector(MenuLayer::music), duihao1,cuohao1,NULL);
    }else
    {
         music_sound = CCMenuItemToggle::createWithTarget(this,  menu_selector(MenuLayer::music), cuohao1,duihao1,NULL);
    }
    
    menu->addChild(music_sound);
    music_sound->setPosition(ccp( 100+SIZE.width/2,SIZE.height*0.4));
    duihao1->setScale(1.5f);
    cuohao1->setScale(1.5f);
    
    if (id == 1) {
        jixu = CCMenuItemImage::create("gameover/ggjm_jx.png", "gameover/ggjm_jxdown.png", this, menu_selector(MenuLayer::resume));
        jixu->setPosition(ccp(SIZE.width*0.40,SIZE.height*0.2));
        menu->addChild(jixu);
        zhucaidan = CCMenuItemImage::create("pause/yxzt_fhzcd.png", "pause/yxzt_fhzcd_down.png", this, menu_selector(MenuLayer::back));
        menu->addChild(zhucaidan);
        zhucaidan->setPosition(ccp(SIZE.width*0.60,SIZE.height*0.2));

    }else if (id == 2)
    {
        congxin =  CCMenuItemImage::create("wenzi/chongxinkaishi1.png", "wenzi/chongxinkaishi2.png", this, menu_selector(MenuLayer::congxinCall));
        menu->addChild(congxin);
        congxin->setPosition(ccp(SIZE.width*0.70,SIZE.height*0.2));
        fanhuijidi =  CCMenuItemImage::create("wenzi/fanhuijidi1.png", "wenzi/fanhuijidi2.png", this, menu_selector(MenuLayer::fanhuijidiCall));
        menu->addChild(fanhuijidi);
        fanhuijidi->setPosition(ccp(SIZE.width*0.30,SIZE.height*0.2));
        qianghuashuxing  =  CCMenuItemImage::create("wenzi/qianghuashuxing1.png", "wenzi/qianghuashuxing2.png", this, menu_selector(MenuLayer::qianghuashuxingCall));
        menu->addChild(qianghuashuxing);
        qianghuashuxing->setPosition(ccp(SIZE.width*0.50,SIZE.height*0.2));
    }
    
    CCMenuItemImage* xiaocha = CCMenuItemImage::create("shop/scnl_gb.png", "shop/scnl_gb_down.png", this,  menu_selector(MenuLayer::resume));
    menu->addChild(xiaocha);
    
    xiaocha->setPosition(ccp(SIZE.width*0.915,SIZE.height*0.845));
    this->addChild(menu);
    menu->setPosition(ccp(0,0));
}

void MenuLayer::back(CCObject* pSender)
{
    PersonalAudioEngine::sharedEngine()->playEffect("music/backSound.wav");
    if (gameLayer != NULL)
    {
        gameLayer->resume();
        gameLayer->unscheduleAllSelectors();
    }
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f,  MenuScene::scene()) );
}

void MenuLayer::shop()
{
    this->resume(NULL);
    if (gameLayer != NULL)
    {
       gameLayer->shop();
    }else
    {
        CCDirector::sharedDirector()->replaceScene( ShopBuy::scene() );
    }
}

void MenuLayer::resume(CCObject* pSender)
{
    CCDirector::sharedDirector()->popScene();
}
void MenuLayer::congxinCall(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(GameScene::scene(gameLayer->id,gameLayer->modeID));
}

void MenuLayer::fanhuijidiCall(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(ShopScene::scene());
}

void MenuLayer::qianghuashuxingCall(CCObject* pSender)
{
    gameLayer->shop(100);
}

void MenuLayer::sound(CCObject* pSender)
{
    PersonalAudioEngine::sharedEngine()->playEffect("music/confirm.wav");
    GameScene* gameScene = (GameScene*)this->getParent();
    gameScene->sound();
}
void MenuLayer::music(CCObject* pSender)
{
    PersonalAudioEngine::sharedEngine()->playEffect("music/confirm.wav");
    GameScene* gameScene = (GameScene*)this->getParent();
    gameScene->music();
}

void MenuLayer::setSoundAndMusicVolume(float soundVolume, float musicVolume)
{
    bool soundFlag = soundVolume>0;
    bool musicFlag = musicVolume>0;
    _sound->setSelectedIndex(soundFlag);
    _music->setSelectedIndex(musicFlag);
}
