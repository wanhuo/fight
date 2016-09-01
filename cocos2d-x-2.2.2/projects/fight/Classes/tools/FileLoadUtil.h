/*
    文件名：    FileLoadUtil.h
    描　述：    文本文件读取工具
    创建人：   

    创建日期：   2013.07.18
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

    /* 获取文件每一行的数据，按行存放到列表中 */
    CCArray * getDataLines(const char* sFilePath);

private:
    static FileLoadUtil* mFileLoadUtil;
};

#endif
