
#include "Tools.h"

/**
*	音效是否开启
*/
bool SysConfig::isEnableAudioEffect()
{
	return Recorder::getBoolForKey("isEnableAudioEffect", true);
}

/**
*	设置音效是否开启
*/
void SysConfig::setEnableAudioEffect(bool value)
{
	Recorder::setBoolForKey("isEnableAudioEffect", value);
}

/**
*	背景音乐是否开启
*/
bool SysConfig::isEnableAudioBackGround()
{
	return Recorder::getBoolForKey("isEnableAudioBackGround", true);
}

/**
*	设置背景音乐是否开启
*/
void SysConfig::setEnableAudioBackGround(bool value)
{
	Recorder::setBoolForKey("isEnableAudioBackGround", value);
}

