
#ifndef __Handler_h__
#define __Handler_h__

#include "cocos2d.h"
USING_NS_CC;
class Message;

//..默认消息
#define __default_handler_notify__ "__default_handler_notify__"
//..默认定时器间隔（单位：ms）
#define __defalut_timer_interval__ (100)

/**
*	Handler
*/
class Handler : public CCObject
{
public:
	/**
	*	获取全局操作句柄
	*/
	static Handler*getInstance();

	/**
	*	资源清理
	*/
	static void destory();

	/**
	*	初始化
	*/
	void init();

	/**
	*	获取空消息体
	*/
	Message *emptyMessage();

	/**
	*	发送消息
	*	@parm msg:消息实体
	*	@return bool:是否发送成功
	*/
	bool sendMessage(Message *msg);

	/**
	*	发送消息
	*	@parm what:消息ID
	*	@return bool:是否发送成功
	*/
	bool sendEmptyMessage(int what);

	/**
	*	发送消息
	*	@parm msg:消息实体
	*	@parm delay:延时（单位:ms）
	*	@return bool:是否发送成功
	*/
	bool sendMessageDelayed(Message *msg, long delay);

	/**
	*	发送消息
	*	@parm what:消息ID
	*	@parm delay:延时（单位:ms）
	*	@return bool:是否发送成功
	*/
	bool sendEmptyMessageDelayed(int what, long delay);

	/**
	*	添加观察者
	*	@parm target:target
	*	@parm selector:执行函数
	*/
	void addObserver(CCObject *target, SEL_CallFuncO selector);

	/**
	*	移除观察者
	*	@parm target:target
	*/
	void removeObserver(CCObject *target);

	/**
	*	移除所有观察者
	*	@parm target:target
	*/
	void removeAllObservers(CCObject *target);

#if 0
	/**
	*	添加观察者
	*	@parm key:key
	*	@parm target:target
	*	@parm selector:执行函数
	*/
	void addObserver(const std::string& key, Ref *target, SEL_CallFuncO selector);

	/**
	*	移除观察者
	*	@parm key:key
	*	@parm target:target
	*/
	void removeObserver(const std::string& key, Ref *target);
#endif
	//..构造
	Handler();
	//..析构
	~Handler();
private:

	/**
	*	定时器接收
	*	@parm dt:时间间隔
	*/
	void handlerMessage(float dt);

	/**
	*	开启全局定时器
	*/
	void startTimer();

	/**
	*	停止全局定时器
	*/
	void stopTimer();

	//..延迟消息堆栈
	CCArray *delayStack;
};

/**
*	class:Message
*	author:Dennis
*   data:2014/09/11
*	desc:发送消息实体
*/
class Message:public CCObject{
public:
	//..消息ID
	int what;
	//..参数1
	int arg1;
	//..参数2
	int arg2;
	//..参数3
	CCObject *obj;
	//..key
	std::string key;
	//..延迟
	long delay;
	
	//..构造
	Message();
	//..构造
	Message(int what, int arg1, int arg2, CCObject *obj, std::string &key, long delay);
};

#endif