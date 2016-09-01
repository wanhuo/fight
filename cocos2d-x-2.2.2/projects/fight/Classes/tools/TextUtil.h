
#ifndef __TextUtil_h__
#define __TextUtil_h__

#include "cocos2d.h"
//..xml解析
#include "support/tinyxml2/tinyxml2.h"  
USING_NS_CC;

//..文本
class TextUtil : public CCObject 
{
public:
	//..获取句柄
	static TextUtil *getInstance();
	//..获取文本
	const char *getText(const char *key);

	//..构造
	TextUtil();
	//..析构
	~TextUtil();
private:
	//..初始化
	void init(const char *textSource);
	//..句柄
	static TextUtil *instance;
	//..dictionary
	CCDictionary* dictionary;
};

#endif