
#include "Tools.h"
#include "SimpleAudioEngine.h"

/**
* ÒôÆµ²¥·Å¿ØÖÆ
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

/** »ñÈ¡²¥·Å¿ØÖÆÆ÷¾ä±ú */
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

/** ²¥·ÅÒôĞ§ */
void Audio::playEffect(const char *effectSource){

	if (!isStringNull(effectSource) && SysConfig::isEnableAudioEffect())
	{
		SimpleAudioEngine::sharedEngine()->playEffect(effectSource);
	}
}

/** Í£Ö¹ËùÓĞÒôĞ§ */
void Audio::stopAllEffects()
{
	SimpleAudioEngine::sharedEngine()->stopAllEffects();
}

/** ²¥·Å±³¾°ÒôÀÖ */
void Audio::playBgAudio(const char *audioSource)
{

	if (!isStringNull(audioSource)
		&& !SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()
		&& SysConfig::isEnableAudioBackGround())
	{
		//..²¥·Å±³¾°ÒôÀÖ
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(audioSource, true);		
	}
}

/** ÔİÍ£±³¾°ÒôÀÖ */
void Audio::pauseBgAudio()
{
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

/** »Ö¸´±³¾°ÒôÀÖ */
void Audio::resumeBgAudio()
{

	if (SysConfig::isEnableAudioBackGround())
	{
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();	
	}
}

/** Í£Ö¹±³¾°ÒôÀÖ */
void Audio::stopBgAudio()
{
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

/** ÍË³ö */
void Audio::exit()
{
	SimpleAudioEngine::sharedEngine()->end();
}