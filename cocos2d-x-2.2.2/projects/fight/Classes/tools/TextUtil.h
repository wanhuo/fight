
#ifndef __TextUtil_h__
#define __TextUtil_h__

#include "cocos2d.h"
//..xml����
#include "support/tinyxml2/tinyxml2.h"  
USING_NS_CC;

//..�ı�
class TextUtil : public CCObject 
{
public:
	//..��ȡ���
	static TextUtil *getInstance();
	//..��ȡ�ı�
	const char *getText(const char *key);

	//..����
	TextUtil();
	//..����
	~TextUtil();
private:
	//..��ʼ��
	void init(const char *textSource);
	//..���
	static TextUtil *instance;
	//..dictionary
	CCDictionary* dictionary;
};

#endif