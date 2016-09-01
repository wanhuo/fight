/*
    �ļ�����    JavaTransUtil.h
    �衡����    Jin����ת������
    �����ˣ�    

    �������ڣ�   2013.07.02
*/
#ifndef JavaTransUtil_H
#define JavaTransUtil_H

#include "cocos2d.h"
USING_NS_CC;

//ʹ��Ԥ���룬�Ե�ǰƽ̨ΪAndroidʱ�Żᵼ������ͷ�ļ�
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#endif

class JavaTransUtil : public CCObject {
public:
    static JavaTransUtil* sharedJavaTransUtil();
    virtual bool init();


#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    jstring str2jstring(JNIEnv* env,const char* pat);
    std::string jstring2str(JNIEnv* env, jstring jstr);
#endif
private:
    static JavaTransUtil* m_javaTransUtil;

};

#endif