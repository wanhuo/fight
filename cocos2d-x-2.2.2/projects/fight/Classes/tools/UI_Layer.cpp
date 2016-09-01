
#include "Tools.h"

//..构造
UI_Layer::UI_Layer()
{
	//..默认注册Handler
	Handler::getInstance()->addObserver(this, callfuncO_selector(UI_Layer::handlerMessage));
}
//..析构
UI_Layer::~UI_Layer()
{
	//..销毁观察者
	Handler::getInstance()->removeAllObservers(this);
}

//..初始化
bool UI_Layer::init()
{
	returnfalseIfValue(!CCLayer::init())
	return true;
}

//..消息回调
void UI_Layer::handlerMessage(CCObject *obj)
{
	
}

//..注册触摸
void UI_Layer::registerTouchListener()
{
	/*
	returnIfValue(_touchListener)
	//..触摸屏注册
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
	//..触摸
    listener->onTouchBegan = CC_CALLBACK_2(UILayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(UILayer::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(UILayer::onTouchEnded, this);   
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	_touchListener = listener;
	*/
}

//..注销触摸
void UI_Layer::unregisterTouchListener()
{
	/*
	returnIfValue(!_touchListener)
	_eventDispatcher->removeEventListener(_touchListener);
	_touchListener = nullptr;
	*/
}

//..按键消息
void UI_Layer::registerKeyEventListener()
{
	/*
	//..按键
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(UILayer::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(UILayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	*/
}
