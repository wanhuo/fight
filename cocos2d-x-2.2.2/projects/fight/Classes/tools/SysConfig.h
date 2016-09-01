
#ifndef __SysConfig_h__
#define __SysConfig_h__

#include "cocos2d.h"

/**
*	系统配置
*/
class SysConfig
{
public:
	/**
	*	音效是否开启
	*/
	static bool isEnableAudioEffect();

	/**
	*	设置音效是否开启
	*/
	static void setEnableAudioEffect(bool value);

	/**
	*	背景音乐是否开启
	*/
	static bool isEnableAudioBackGround();

	/**
	*	设置背景音乐是否开启
	*/
	static void setEnableAudioBackGround(bool value);
};

#endif