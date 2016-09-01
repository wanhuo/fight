

#include "Tools.h"

//..ȫ�־��
static Handler *instance = nullptr;

//..����
Handler::Handler()
{
	delayStack = CCArray::create();
	delayStack->retain();
}

//..����
Handler::~Handler()
{
	delayStack->removeAllObjects();
	delayStack->release();

	//..��ʱ��
	stopTimer();
}

/**
*	��ȡȫ�ֲ������
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
*	��Դ����
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
*	��ʼ��
*/
void Handler::init()
{
	//..������ʱ��
	startTimer();
}

/**
*	����ȫ�ֶ�ʱ��
*/
void Handler::startTimer()
{
	//..����ȫ�ֶ�ʱ��
	CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(Handler::handlerMessage)
		, this
		, (float)__defalut_timer_interval__ / (float)1000
		, false);
}

/**
*	ֹͣȫ�ֶ�ʱ��
*/
void Handler::stopTimer()
{
	CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(Handler::handlerMessage), this);
}

/**
*	��ȡ����Ϣ��
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
*	������Ϣ
*	@parm msg:��Ϣʵ��
*	@return bool:�Ƿ��ͳɹ�
*/
bool Handler::sendMessage(Message *msg)
{
	returnfalseIfValue(!msg)
	CCNotificationCenter::sharedNotificationCenter()->postNotification(__default_handler_notify__, msg);
	return true;
}

/**
*	������Ϣ
*	@parm what:��ϢID
*	@return bool:�Ƿ��ͳɹ�
*/
bool Handler::sendEmptyMessage(int what)
{
	Message *msg = emptyMessage();
	returnfalseIfValue(!msg)
	msg->what = what;	
	return sendMessage(msg);
}

/**
*	������Ϣ
*	@parm msg:��Ϣʵ��
*	@parm delay:��ʱ����λ:ms��
*	@return bool:�Ƿ��ͳɹ�
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
*	������Ϣ
*	@parm what:��ϢID
*	@parm delay:��ʱ����λ:ms��
*	@return bool:�Ƿ��ͳɹ�
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
*	��ӹ۲���
*	@parm target:target
*	@parm selector:ִ�к���
*/
void Handler::addObserver(CCObject *target, SEL_CallFuncO selector)
{
	returnIfValue(!target || !selector)
	CCNotificationCenter::sharedNotificationCenter()->addObserver(target, selector, __default_handler_notify__, NULL);
}

/**
*	�Ƴ��۲���
*	@parm target:target
*/
void Handler::removeObserver(CCObject *target)
{
	returnIfValue(!target);
	CCNotificationCenter::sharedNotificationCenter()->removeObserver(target, __default_handler_notify__);
}

/**
*	�Ƴ����й۲���
*	@parm target:target
*/
void Handler::removeAllObservers(CCObject *target)
{
	returnIfValue(!target);
	CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(target);
}

#if 0
/**
*	��ӹ۲���
*	@parm key:key
*	@parm target:target
*	@parm selector:ִ�к���
*/
void Handler::addObserver(const std::string& key, Ref *target, SEL_CallFuncO selector)
{
	returnIfValue(!target || !selector);
	NotificationCenter::getInstance()->addObserver(target, selector, key, nullptr);
}

/**
*	�Ƴ��۲���
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
*	��ʱ������
*	@parm dt:ʱ����
*/
void Handler::handlerMessage(float dt)
{
	returnIfValue(!delayStack)
	//..����ֹͣ��ʱ��
	stopTimer();
	CCObject* obj = nullptr;
	CCArray *deleteArray = CCArray::create();
	CCARRAY_FOREACH(delayStack, obj)
	{
		Message *msg = static_cast<Message *>(obj);
		continueIfVaule(!msg)
		//..�ӳ�ֵ�ݼ�
		msg->delay -= __defalut_timer_interval__;
		if (msg->delay <= 0)
		{
			//..ʱ�䵽�ִ��
			deleteArray->addObject(msg);
			sendMessage(msg);
		}
	}
	//..ɾ���ӳٵ������Ϣ
	delayStack->removeObjectsInArray(deleteArray);
	//..���¿�����ʱ��
	startTimer();
}

//..����
Message::Message()
{
	what = -1;
	arg1 = -1;
	arg2 = -1;
	obj = nullptr;
	//key = nullptr;
	delay = 0;
}

//..����
Message::Message(int what, int arg1, int arg2, CCObject *obj, std::string &key, long delay)
{
	this->what = what;
	this->arg1 = arg1;
	this->arg2 = arg2;
	this->obj = obj;
	this->key = key;
	this->delay = delay;
}
