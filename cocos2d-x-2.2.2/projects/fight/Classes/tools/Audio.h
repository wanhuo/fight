
#ifndef __SOUND_MANAGE_H__
#define __SOUND_MANAGE_H__

/**
* 音频播放控制
*/
#include "cocos2d.h"
USING_NS_CC;

class Audio : public CCObject
{

public:

	/** 
	 *	播放音效 
	 *	@param sound : 音效文件路径
	 */
	void playEffect(const char *sound);


	/** 停止所有音效 */
	void stopAllEffects();

	/** 播放背景音乐 */
	void playBgAudio(const char *audioSource);

	/** 暂停背景音乐 */
	void pauseBgAudio();

	/** 恢复背景音乐 */
	void resumeBgAudio();

	/** 停止背景音乐 */
	void stopBgAudio();

	/** 停止所有播放 */
	bool stopAll(){
		//..停止背景播放
		stopBgAudio();
		//..停止所有音效
		stopAllEffects();
		return true;
	} 

	/** 退出 */
	void exit();

	/** 获取句柄 */
	static Audio *getInstance();

	Audio();
	~Audio();
private:

	static Audio *instance;
};

#endif
