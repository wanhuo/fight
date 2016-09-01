/*
    文件名：    StringUtil.cpp
    描　述：    字符串处理工具
    创建人：    
    创建日期：   2013.07.18
*/

#include "StringUtil.h"

StringUtil* StringUtil::mStringUtil = NULL;

StringUtil* StringUtil::getInstance()
{
    if(mStringUtil == NULL) 
	{
        mStringUtil = new StringUtil();
        if(mStringUtil && mStringUtil->init()) 
		{
            mStringUtil->autorelease();
        }
        else 
		{
            CC_SAFE_DELETE(mStringUtil);
            mStringUtil = NULL;
        }
    }

    return mStringUtil;
}

bool StringUtil::init()
{

    return true;
}
/*
*     字符串拆分-
*	srcStr - 源字符串
*	sSep  - 拆分关键字符
	m_sString 为STD对象
*/
CCArray* StringUtil::split( const char* srcStr, const char* sSep ){
    CCArray* stringList = CCArray::create();

    int size = strlen(srcStr);

    /* 将数据转换为字符串对象 */
    CCString* str = CCString::create(srcStr);

    int startIndex = 0;
    int endIndex = 0;
    endIndex = str->m_sString.find(sSep);

    CCString* lineStr = NULL;

    /* 根据换行符拆分字符串，并添加到列表中 */
    while(endIndex > 0) {
        lineStr = CCString::create("");

        /* 截取一行字符串 */
        lineStr->m_sString = str->m_sString.substr(startIndex, endIndex);

        /* 添加到列表 */
        stringList->addObject(lineStr);

        /* 截取剩下的字符串 */
        str->m_sString = str->m_sString.substr(endIndex + 1, size);

        endIndex = str->m_sString.find(sSep);
    }

    /* 剩下的字符串也添加进列表 */
    if(str->m_sString.compare("") != 0) {
        stringList->addObject(CCString::create(str->m_sString));
    }

    return stringList;
}

const char* StringUtil::transIntToStr( int iValue ) {
    return transIntToCCStr(iValue)->getCString();
}

/*
	字符转换最终干活的函数
*/
CCString* StringUtil::transIntToCCStr( int iValue ) {
    char chValue[8];

    sprintf(chValue, "%d", iValue);

    return CCString::createWithFormat(chValue);
}
int StringUtil::transStrToInt( const char* str ) {
    int num = 0;
    sscanf(str, "%d", &num);

    return num;
}
