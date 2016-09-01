

#include "Tools.h"

//..全局句柄
static Handler *instance = nullptr;

//..构造
Handler::Handler()
{
	delayStack = CCArray::create();
	delayStack->retain();
}

//..析构
Handler::~Handler()
{
	delayStack->removeAllObjects();
	delayStack->release();

	//..定时器
	stopTimer();
}

/**
*	获取全局操作句柄
*/
Handler* Handler::getInstance()
{
	if (!instance){
		instance = new Handler();
		instance->retain();
		instance->init();
	}
	return instance;
}

/**
*	资源清理
*/
void Handler::destory()
{
	if (instance)
	{
		instance->release();
		instance = nullptr;
	}
}

/**
*	初始化
*/
void Handler::init()
{
	//..开启定时器
	startTimer();
}

/**
*	开启全局定时器
*/
void Handler::startTimer()
{
	//..开启全局定时器
	CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(Handler::handlerMessage)
		, this
		, (float)__defalut_timer_interval__ / (float)1000
		, false);
}

/**
*	停止全局定时器
*/
void Handler::stopTimer()
{
	CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(Handler::handlerMessage), this);
}

/**
*	获取空消息体
*/
Message *Handler::emptyMessage()
{
	Message *msg = new Message();
	if (msg)
	{
		msg->retain();
		msg->autorelease();
		return msg;
	}
	return nullptr;
}

/**
*	发送消息
*	@parm msg:消息实体
*	@return bool:是否发送成功
*/
bool Handler::sendMessage(Message *msg)
{
	returnfalseIfValue(!msg)
	CCNotificationCenter::sharedNotificationCenter()->postNotification(__default_handler_notify__, msg);
	return true;
}

/**
*	发送消息
*	@parm what:消息ID
*	@return bool:是否发送成功
*/
bool Handler::sendEmptyMessage(int what)
{
	Message *msg = emptyMessage();
	returnfalseIfValue(!msg)
	msg->what = what;	
	return sendMessage(msg);
}

/**
*	发送消息
*	@parm msg:消息实体
*	@parm delay:延时（单位:ms）
*	@return bool:是否发送成功
*/
bool Handler::sendMessageDelayed(Message *msg, long delay)
{
	returnfalseIfValue(!msg)
	if (delay == 0){
		return sendMessage(msg);
	}else{
		if (delayStack)
		{
			CCObject* obj = nullptr;
			CCARRAY_FOREACH(delayStack, obj)
			{
				Message *tmp = static_cast<Message *>(obj);
				continueIfVaule(!tmp)
				if (msg == tmp){
					return false;
				}
			}
			delayStack->addObject(msg);
		}
	}
	return true;
}

/**
*	发送消息
*	@parm what:消息ID
*	@parm delay:延时（单位:ms）
*	@return bool:是否发送成功
*/
bool Handler::sendEmptyMessageDelayed(int what, long delay)
{
	Message *msg = emptyMessage();
	returnfalseIfValue(!msg)
	msg->what = what;
	msg->delay = delay;
	if (delay == 0){
		return sendMessage(msg);
	}else{
		sendMessageDelayed(msg, delay);
	}
	return true;
}

/**
*	添加观察者
*	@parm target:target
*	@parm selector:执行函数
*/
void Handler::addObserver(CCObject *target, SEL_CallFuncO selector)
{
	returnIfValue(!target || !selector)
	CCNotificationCenter::sharedNotificationCenter()->addObserver(target, selector, __default_handler_notify__, NULL);
}

/**
*	移除观察者
*	@parm target:target
*/
void Handler::removeObserver(CCObject *target)
{
	returnIfValue(!target);
	CCNotificationCenter::sharedNotificationCenter()->removeObserver(target, __default_handler_notify__);
}

/**
*	移除所有观察者
*	@parm target:target
*/
void Handler::removeAllObservers(CCObject *target)
{
	returnIfValue(!target);
	CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(target);
}

#if 0
/**
*	添加观察者
*	@parm key:key
*	@parm target:target
*	@parm selector:执行函数
*/
void Handler::addObserver(const std::string& key, Ref *target, SEL_CallFuncO selector)
{
	returnIfValue(!target || !selector);
	NotificationCenter::getInstance()->addObserver(target, selector, key, nullptr);
}

/**
*	移除观察者
*	@parm key:key
*	@parm target:target
*/
void Handler::removeObserver(const std::string& key, Ref *target)
{
	returnIfValue(!target);
	NotificationCenter::getInstance()->removeObserver(target, key);
}
#endif

/**
*	定时器接收
*	@parm dt:时间间隔
*/
void Handler::handlerMessage(float dt)
{
	returnIfValue(!delayStack)
	//..首先停止定时器
	stopTimer();
	CCObject* obj = nullptr;
	CCArray *deleteArray = CCArray::create();
	CCARRAY_FOREACH(delayStack, obj)
	{
		Message *msg = static_cast<Message *>(obj);
		continueIfVaule(!msg)
		//..延迟值递减
		msg->delay -= __defalut_timer_interval__;
		if (msg->delay <= 0)
		{
			//..时间到达，执行
			deleteArray->addObject(msg);
			sendMessage(msg);
		}
	}
	//..删除延迟到达的消息
	delayStack->removeObjectsInArray(deleteArray);
	//..重新开启定时器
	startTimer();
}

//..构造
Message::Message()
{
	what = -1;
	arg1 = -1;
	arg2 = -1;
	obj = nullptr;
	//key = nullptr;
	delay = 0;
}

//..构造
Message::Message(int what, int arg1, int arg2, CCObject *obj, std::string &key, long delay)
{
	this->what = what;
	this->arg1 = arg1;
	this->arg2 = arg2;
	this->obj = obj;
	this->key = key;
	this->delay = delay;
}
