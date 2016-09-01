/*
    文件名：    FileLoadUtil.c
    描　述：    文本文件读取工具
    创建人：   

    创建日期：   2013.07.18
*/


#include "FileLoadUtil.h"
#include "StringUtil.h"

FileLoadUtil* FileLoadUtil::mFileLoadUtil = NULL;

/*
* 创建一个文件读取单例
*/
FileLoadUtil* FileLoadUtil::getInstance()
{
    if(mFileLoadUtil == NULL) 
	{
        mFileLoadUtil = new FileLoadUtil();
        if(mFileLoadUtil && mFileLoadUtil->init()) 
		{
            mFileLoadUtil->autorelease();
        }
        else 
		{
            CC_SAFE_DELETE(mFileLoadUtil);
            mFileLoadUtil = NULL;
        }
    }

    return mFileLoadUtil;
}

bool FileLoadUtil::init()
{

    return true;
}

/*
从文件中取一行数据

sFilePath--文件名

*/
CCArray* FileLoadUtil::getDataLines( const char* sFilePath )
{
    CCArray* linesList = CCArray::create();

    unsigned long pSize = 0;
    unsigned char* chDatas = CCFileUtils::sharedFileUtils()->getFileData(sFilePath, "r", &pSize);

    /* 将数据转换为字符串对象 */
    CCString* str = CCString::createWithData(chDatas, pSize);

	//把数据每一行都进行分割-分割符为'\n'(换行符)
    linesList = StringUtil::getInstance()->split(str->getCString(), "\n");
    
	free(chDatas);

    return linesList;
}
