
#include "Tools.h"



TextUtil* TextUtil::instance = NULL;
//..获取句柄
TextUtil *TextUtil::getInstance()
{
    if(instance == NULL) 
	{
        instance = new TextUtil();
        if(instance) 
		{
            instance->autorelease();
        }
        else 
		{
            CC_SAFE_DELETE(instance);
            instance = NULL;
        }
    }
	return instance;
}

//..构造
TextUtil::TextUtil():dictionary(nullptr)
{
     
}

//..析构
TextUtil::~TextUtil()
{
	deleteIfNotNull(dictionary)
}

//..获取文本
const char *TextUtil::getText(const char *key)
{
	const char *text = NULL;
	if (!dictionary)
	{
		init(__default_text_path__);
	}
	if (dictionary && key && strlen(key) > 0)
	{
		text = ((CCString *)dictionary->objectForKey(key))->getCString();	
	}
	return text;
}

//..初始化
void TextUtil::init(const char *textSource)
{
	if (!isStringNull(textSource))
	{
		dictionary = CCDictionary::createWithContentsOfFile(textSource);  
		dictionary->retain();
	}
}

