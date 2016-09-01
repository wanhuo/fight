
#ifndef __UILayer_h__
#define __UILayer_h__

#include "cocos2d.h"
USING_NS_CC;

/**
*	layer基类
*/
class UI_Layer:public CCLayer
{
public:

	//..初始化
	virtual bool init();

	//..消息回调
	virtual void handlerMessage(CCObject *obj);

	//..注册触摸
	void registerTouchListener();
	//..注销触摸
	void unregisterTouchListener();
	//..按键消息
	void registerKeyEventListener();

	//..构造
	UI_Layer();
	//..析构
	~UI_Layer();
};

#endif