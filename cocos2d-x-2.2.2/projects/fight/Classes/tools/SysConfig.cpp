
#include "Tools.h"

/**
*	��Ч�Ƿ���
*/
bool SysConfig::isEnableAudioEffect()
{
	return Recorder::getBoolForKey("isEnableAudioEffect", true);
}

/**
*	������Ч�Ƿ���
*/
void SysConfig::setEnableAudioEffect(bool value)
{
	Recorder::setBoolForKey("isEnableAudioEffect", value);
}

/**
*	���������Ƿ���
*/
bool SysConfig::isEnableAudioBackGround()
{
	return Recorder::getBoolForKey("isEnableAudioBackGround", true);
}

/**
*	���ñ��������Ƿ���
*/
void SysConfig::setEnableAudioBackGround(bool value)
{
	Recorder::setBoolForKey("isEnableAudioBackGround", value);
}

