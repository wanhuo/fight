
#ifndef __SOUND_MANAGE_H__
#define __SOUND_MANAGE_H__

/**
* ��Ƶ���ſ���
*/
#include "cocos2d.h"
USING_NS_CC;

class Audio : public CCObject
{

public:

	/** 
	 *	������Ч 
	 *	@param sound : ��Ч�ļ�·��
	 */
	void playEffect(const char *sound);


	/** ֹͣ������Ч */
	void stopAllEffects();

	/** ���ű������� */
	void playBgAudio(const char *audioSource);

	/** ��ͣ�������� */
	void pauseBgAudio();

	/** �ָ��������� */
	void resumeBgAudio();

	/** ֹͣ�������� */
	void stopBgAudio();

	/** ֹͣ���в��� */
	bool stopAll(){
		//..ֹͣ��������
		stopBgAudio();
		//..ֹͣ������Ч
		stopAllEffects();
		return true;
	} 

	/** �˳� */
	void exit();

	/** ��ȡ��� */
	static Audio *getInstance();

	Audio();
	~Audio();
private:

	static Audio *instance;
};

#endif
