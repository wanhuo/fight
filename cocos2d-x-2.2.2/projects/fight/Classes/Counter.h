//
//  Counter.h
//  King
//
//  Created by mac on 14-4-20.
//
//

#ifndef __King__Counter__
#define __King__Counter__

#include "cocos2d.h"
USING_NS_CC;
class Counter : public CCNode
{
public:
    Counter();
    /**
     *	@brief
     *
     *	@param 	presenters 	0-9��10�����ֶ�Ӧ�Ľڵ������
     *	@param 	digit 	Ĭ�ϵ���ֵ
     *
     *	@return
     */
    static Counter* create(cocos2d::CCArray* presenters, int digit = 0);
    bool init(cocos2d::CCArray* presenters, int digit = 0);
    
    CC_PROPERTY(int, _digit, Digit);
  //  CC_PROPERTY(int, _digit, Digit2);

    void setDigit2(int digit);
protected:
    void visit();
    //���0-9���ֶ�Ӧ�Ľڵ�
    cocos2d::CCNode* _presenters;
    //�ı�����ʱ���Ź�������
    void animation(int digit);
    void animation2(int digit);
};


#endif /* defined(__King__Counter__) */
