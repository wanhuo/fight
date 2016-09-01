//
//  AboutScene.cpp
//  King
//
//  Created by mac on 14-3-26.
//
//

#include "AboutScene.h"
#include "Define.h"
#include "MenuScene.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;

bool AboutScene::init()
{
    if ( !BaseLayer::init() )
    {
        return false;
    }
    //  CCSprite* about = CCSprite::create();
    UILabel* about = UILabel::create();
 
    //about->setText("游戏名称:街机拳皇2014怀旧版\n游戏类型:动作类\n应用类型:Android\n公司名称:北京摩丰科技有限公司\n客服电话:15390898367\n客服邮箱:service@mfplay.cn\n版本号:1.0\n免责申明:本游戏的版权归北京摩丰科技有限公司所有,游戏中的文字,图片 等内容均为游戏版权所有者的个人态度或立场,中国电信对此不承担任何法律 责任。\n");
	about->setText(I18N_STR(159));
	about->setFontName("宋体");
    about->setFontSize(20);
    about->setAnchorPoint(ccp(0.5, 0.5));
    about->setColor(ccc3(241, 191, 194));
    about->setTextAreaSize(CCSize(500,400));
    about->setTextVerticalAlignment(kCCVerticalTextAlignmentCenter);
    about->setTextHorizontalAlignment(kCCTextAlignmentCenter);
    this->addChild(about,-1);
    about->setPosition(CCPoint(SIZE.width/2,SIZE.height/2));
    CCMenu* menu = CCMenu::create();
    
    CCSprite* back = CCSprite::create();
    UILabel* backI = UILabel::create();
    //backI->setText("返回");
	backI->setText(I18N_STR(158));
    backI->setFontSize(30);
    backI->setTextHorizontalAlignment(kCCTextAlignmentCenter);
    backI->setAnchorPoint(ccp(0.5, 0.5));
    backI->setPosition(ccp(90, 25));
    
    back->addChild(backI);
    back->setContentSize(CCSize(180,50));
    CCMenuItem* beginItem = CCMenuItemSprite::create(back, back, this, menu_selector(AboutScene::Return));
    menu->addChild(beginItem,2);
    beginItem->setPosition(CCPoint(7*SIZE.width/8,SIZE.height/6));
    
    this->addChild(menu);
    menu->setPosition(ccp(0,0));
    return true;
}

void AboutScene::Return(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}

cocos2d::CCScene* AboutScene::scene()
{
    CCScene *scene = CCScene::create();
    
    AboutScene *layer = AboutScene::create();
    
    scene->addChild(layer);
    
    return scene;
}




