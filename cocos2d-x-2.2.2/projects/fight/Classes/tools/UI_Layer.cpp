
#include "Tools.h"

//..����
UI_Layer::UI_Layer()
{
	//..Ĭ��ע��Handler
	Handler::getInstance()->addObserver(this, callfuncO_selector(UI_Layer::handlerMessage));
}
//..����
UI_Layer::~UI_Layer()
{
	//..���ٹ۲���
	Handler::getInstance()->removeAllObservers(this);
}

//..��ʼ��
bool UI_Layer::init()
{
	returnfalseIfValue(!CCLayer::init())
	return true;
}

//..��Ϣ�ص�
void UI_Layer::handlerMessage(CCObject *obj)
{
	
}

//..ע�ᴥ��
void UI_Layer::registerTouchListener()
{
	/*
	returnIfValue(_touchListener)
	//..������ע��
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
	//..����
    listener->onTouchBegan = CC_CALLBACK_2(UILayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(UILayer::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(UILayer::onTouchEnded, this);   
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	_touchListener = listener;
	*/
}

//..ע������
void UI_Layer::unregisterTouchListener()
{
	/*
	returnIfValue(!_touchListener)
	_eventDispatcher->removeEventListener(_touchListener);
	_touchListener = nullptr;
	*/
}

//..������Ϣ
void UI_Layer::registerKeyEventListener()
{
	/*
	//..����
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(UILayer::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(UILayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	*/
}
