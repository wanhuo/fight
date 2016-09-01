/*
    �ļ�����    FileLoadUtil.h
    �衡����    �ı��ļ���ȡ����
    �����ˣ�   

    �������ڣ�   2013.07.18
*/
#ifndef __FILE_LOAD_UTIL_H__
#define __FILE_LOAD_UTIL_H__

#include "cocos2d.h"

using namespace cocos2d;

class FileLoadUtil : public CCObject 
{
public:
    static FileLoadUtil* getInstance();

    bool init();

    /* ��ȡ�ļ�ÿһ�е����ݣ����д�ŵ��б��� */
    CCArray * getDataLines(const char* sFilePath);

private:
    static FileLoadUtil* mFileLoadUtil;
};

#endif
