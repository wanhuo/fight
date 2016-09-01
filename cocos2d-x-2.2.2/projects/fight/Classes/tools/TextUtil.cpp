
#include "Tools.h"



TextUtil* TextUtil::instance = NULL;
//..��ȡ���
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

//..����
TextUtil::TextUtil():dictionary(nullptr)
{
     
}

//..����
TextUtil::~TextUtil()
{
	deleteIfNotNull(dictionary)
}

//..��ȡ�ı�
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

//..��ʼ��
void TextUtil::init(const char *textSource)
{
	if (!isStringNull(textSource))
	{
		dictionary = CCDictionary::createWithContentsOfFile(textSource);  
		dictionary->retain();
	}
}

