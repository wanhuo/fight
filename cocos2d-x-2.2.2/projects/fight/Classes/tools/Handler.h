
#ifndef __Handler_h__
#define __Handler_h__

#include "cocos2d.h"
USING_NS_CC;
class Message;

//..Ĭ����Ϣ
#define __default_handler_notify__ "__default_handler_notify__"
//..Ĭ�϶�ʱ���������λ��ms��
#define __defalut_timer_interval__ (100)

/**
*	Handler
*/
class Handler : public CCObject
{
public:
	/**
	*	��ȡȫ�ֲ������
	*/
	static Handler*getInstance();

	/**
	*	��Դ����
	*/
	static void destory();

	/**
	*	��ʼ��
	*/
	void init();

	/**
	*	��ȡ����Ϣ��
	*/
	Message *emptyMessage();

	/**
	*	������Ϣ
	*	@parm msg:��Ϣʵ��
	*	@return bool:�Ƿ��ͳɹ�
	*/
	bool sendMessage(Message *msg);

	/**
	*	������Ϣ
	*	@parm what:��ϢID
	*	@return bool:�Ƿ��ͳɹ�
	*/
	bool sendEmptyMessage(int what);

	/**
	*	������Ϣ
	*	@parm msg:��Ϣʵ��
	*	@parm delay:��ʱ����λ:ms��
	*	@return bool:�Ƿ��ͳɹ�
	*/
	bool sendMessageDelayed(Message *msg, long delay);

	/**
	*	������Ϣ
	*	@parm what:��ϢID
	*	@parm delay:��ʱ����λ:ms��
	*	@return bool:�Ƿ��ͳɹ�
	*/
	bool sendEmptyMessageDelayed(int what, long delay);

	/**
	*	��ӹ۲���
	*	@parm target:target
	*	@parm selector:ִ�к���
	*/
	void addObserver(CCObject *target, SEL_CallFuncO selector);

	/**
	*	�Ƴ��۲���
	*	@parm target:target
	*/
	void removeObserver(CCObject *target);

	/**
	*	�Ƴ����й۲���
	*	@parm target:target
	*/
	void removeAllObservers(CCObject *target);

#if 0
	/**
	*	��ӹ۲���
	*	@parm key:key
	*	@parm target:target
	*	@parm selector:ִ�к���
	*/
	void addObserver(const std::string& key, Ref *target, SEL_CallFuncO selector);

	/**
	*	�Ƴ��۲���
	*	@parm key:key
	*	@parm target:target
	*/
	void removeObserver(const std::string& key, Ref *target);
#endif
	//..����
	Handler();
	//..����
	~Handler();
private:

	/**
	*	��ʱ������
	*	@parm dt:ʱ����
	*/
	void handlerMessage(float dt);

	/**
	*	����ȫ�ֶ�ʱ��
	*/
	void startTimer();

	/**
	*	ֹͣȫ�ֶ�ʱ��
	*/
	void stopTimer();

	//..�ӳ���Ϣ��ջ
	CCArray *delayStack;
};

/**
*	class:Message
*	author:Dennis
*   data:2014/09/11
*	desc:������Ϣʵ��
*/
class Message:public CCObject{
public:
	//..��ϢID
	int what;
	//..����1
	int arg1;
	//..����2
	int arg2;
	//..����3
	CCObject *obj;
	//..key
	std::string key;
	//..�ӳ�
	long delay;
	
	//..����
	Message();
	//..����
	Message(int what, int arg1, int arg2, CCObject *obj, std::string &key, long delay);
};

#endif