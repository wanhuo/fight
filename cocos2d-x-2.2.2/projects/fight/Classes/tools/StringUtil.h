/*
    �ļ�����    StringUtil.h
    �衡����    �ַ���������
    �����ˣ�    
    �������ڣ�   2013.07.18
*/
#ifndef __STRING_UTIL_H__
#define __STRING_UTIL_H__

#include "cocos2d.h"

using namespace cocos2d;

class StringUtil : public CCObject {
public:
    static StringUtil* getInstance();

    bool init();

    /** �÷ָ����ָ��ַ����������ŵ�һ���б��У��б��еĶ���ΪCCString */
    CCArray* split(const char* srcStr, const char* sSep);

    /* ת������Ϊ�ַ��� */
    const char* transIntToStr(int iValue);
    int transStrToInt(const char* str);
private:
    static StringUtil* mStringUtil;

    /* ת������Ϊ�ַ��� */
    CCString* transIntToCCStr(int iValue);
};

#endif