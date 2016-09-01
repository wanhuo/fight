/*
    文件名：    I18N.h
    描　述：    国际化工具
    创建人：  

    创建日期：   2012.11.22
*/

#ifndef __I18N_H__
#define __I18N_H__

#include "cocos2d.h"
#include "def.h"




using namespace cocos2d;



/////--------------I18N枚举-------------------------//////////////////
enum ENUM_I18N
{
   	 none, 
	/* 公共 */
     E_Confirm = 1,   /* 1 确定 */
	 E_Monster,		/* 2 怪物 */

	/*END*/
	 max,

};

///////////////////////////////////////////////////------宏定义接口-------////////////////////////////////////


#define I18N_STR(ENUM_I18N) I18N::getInstance()->getcStringByKey(ENUM_I18N)







//////////////////////////-----------I18N类------.///////////////////////////////////
class I18N : public CCObject {
public:
	~I18N();
    /* 获取对象 */
    static I18N* getInstance();
    
    /* 初始化 */
    virtual bool init();

    /* 根据Key值获取字符串,返回CCString对象 */
    CCString* getString(ENUM_I18N enStrKey);

    /* 根据Key值获取字符串,返回const char*对象 */
    const char* getcString(ENUM_I18N enStrKey);

	/* 根据整型的Key值获取字符串,返回const char*对象 */
	const char* getcStringByKey( int iKey );

	/* 获取错误码字符串 */
	const char* getcErrorCode(int iCode);
private:    /* 私有方法 */
    /* 从配置文件中读取字符串，保存到字典里 */
    void loadStringsFromConf(CCDictionary* dict, const char* filePath);

private:    /* 成员变量 */
    /* I18N对象 */
    static I18N* mI18N;

	/* 游戏中用到的字符串字典 */
	CCDictionary* mStringDict;

	/* 错误码的字符串字典 */
	CCDictionary* mErrorCodeDict;
};



#endif