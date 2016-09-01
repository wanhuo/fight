/*
    文件名：    JavaTransUtil.h
    描　述：    Jin类型转换工具
    创建人：    

    创建日期：   2013.07.02
*/
#ifndef JavaTransUtil_H
#define JavaTransUtil_H

#include "cocos2d.h"
USING_NS_CC;

//使用预编译，对当前平台为Android时才会导入如下头文件
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