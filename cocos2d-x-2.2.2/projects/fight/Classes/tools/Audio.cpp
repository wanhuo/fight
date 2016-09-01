
#include "Tools.h"
#include "SimpleAudioEngine.h"

/**
* ��Ƶ���ſ���
* Author
*	Dennis
*/

USING_NS_CC;
using namespace CocosDenshion;

Audio* Audio::instance = NULL;

Audio::Audio(){
	//debug("Audio");
}

Audio::~Audio(){
	//debug("~Audio");
}

/** ��ȡ���ſ�������� */
Audio *Audio::getInstance(){

    if(instance == NULL) 
	{
        instance = new Audio();
        if(instance) 
		{
            instance->autorelease();
        }
        else 
		{
            CC_SAFE_DELETE(instance);
            instance = NULL;
        }
    }
	return instance;
}

/** ������Ч */
void Audio::playEffect(const char *effectSource){

	if (!isStringNull(effectSource) && SysConfig::isEnableAudioEffect())
	{
		SimpleAudioEngine::sharedEngine()->playEffect(effectSource);
	}
}

/** ֹͣ������Ч */
void Audio::stopAllEffects()
{
	SimpleAudioEngine::sharedEngine()->stopAllEffects();
}

/** ���ű������� */
void Audio::playBgAudio(const char *audioSource)
{

	if (!isStringNull(audioSource)
		&& !SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()
		&& SysConfig::isEnableAudioBackGround())
	{
		//..���ű�������
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(audioSource, true);		
	}
}

/** ��ͣ�������� */
void Audio::pauseBgAudio()
{
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

/** �ָ��������� */
void Audio::resumeBgAudio()
{

	if (SysConfig::isEnableAudioBackGround())
	{
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();	
	}
}

/** ֹͣ�������� */
void Audio::stopBgAudio()
{
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

/** �˳� */
void Audio::exit()
{
	SimpleAudioEngine::sharedEngine()->end();
}