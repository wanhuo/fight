
#ifndef __UILayer_h__
#define __UILayer_h__

#include "cocos2d.h"
USING_NS_CC;

/**
*	layer����
*/
class UI_Layer:public CCLayer
{
public:

	//..��ʼ��
	virtual bool init();

	//..��Ϣ�ص�
	virtual void handlerMessage(CCObject *obj);

	//..ע�ᴥ��
	void registerTouchListener();
	//..ע������
	void unregisterTouchListener();
	//..������Ϣ
	void registerKeyEventListener();

	//..����
	UI_Layer();
	//..����
	~UI_Layer();
};

#endif