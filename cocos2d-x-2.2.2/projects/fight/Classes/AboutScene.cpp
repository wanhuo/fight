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
 
    //about->setText("��Ϸ����:�ֻ�ȭ��2014���ɰ�\n��Ϸ����:������\nӦ������:Android\n��˾����:����Ħ��Ƽ����޹�˾\n�ͷ��绰:15390898367\n�ͷ�����:service@mfplay.cn\n�汾��:1.0\n��������:����Ϸ�İ�Ȩ�鱱��Ħ��Ƽ����޹�˾����,��Ϸ�е�����,ͼƬ �����ݾ�Ϊ��Ϸ��Ȩ�����ߵĸ���̬�Ȼ�����,�й����ŶԴ˲��е��κη��� ���Ρ�\n");
	about->setText(I18N_STR(159));
	about->setFontName("����");
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
    //backI->setText("����");
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




