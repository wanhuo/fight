
#ifndef __SysConfig_h__
#define __SysConfig_h__

#include "cocos2d.h"

/**
*	ϵͳ����
*/
class SysConfig
{
public:
	/**
	*	��Ч�Ƿ���
	*/
	static bool isEnableAudioEffect();

	/**
	*	������Ч�Ƿ���
	*/
	static void setEnableAudioEffect(bool value);

	/**
	*	���������Ƿ���
	*/
	static bool isEnableAudioBackGround();

	/**
	*	���ñ��������Ƿ���
	*/
	static void setEnableAudioBackGround(bool value);
};

#endif