//
//  Flower.cpp
//  King
//
//  Created by mac on 14-3-29.
//
//

#include "Flower.h"
#include  "Define.h"
bool Flower::init()
{
    
    this->schedule(schedule_selector(Flower::onTime), 1);
    return true;
}

void Flower::onTime(float dt)
{

    int xe = CCRANDOM_MINUS1_1() * SIZE.width/2;     //����Ǹ�ͼƬ�ƶ����������x���
    int sp = CCRANDOM_0_1()*10 +5;     //������ٶ�
    pic = CCSprite::create("smallUI/huaban.png");
    this->addChild(pic);
    CCMoveTo *move=CCMoveTo::create(sp, ccp(xe,-SIZE.height -10));
    CCFadeOut* fadout=CCFadeOut::create(sp);
    CCCallFunc* call=CCCallFunc::create(pic, callfunc_selector(Flower::remove));
    CCSequence* sequence=CCSequence::create(move,fadout,call,NULL);
    pic->runAction(sequence);
}

void Flower::remove()
{
    
}






