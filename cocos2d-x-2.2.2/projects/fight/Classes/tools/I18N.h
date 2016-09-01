/*
    �ļ�����    I18N.h
    �衡����    ���ʻ�����
    �����ˣ�  

    �������ڣ�   2012.11.22
*/

#ifndef __I18N_H__
#define __I18N_H__

#include "cocos2d.h"
#include "def.h"




using namespace cocos2d;



/////--------------I18Nö��-------------------------//////////////////
enum ENUM_I18N
{
   	 none, 
	/* ���� */
     E_Confirm = 1,   /* 1 ȷ�� */
	 E_Monster,		/* 2 ���� */

	/*END*/
	 max,

};

///////////////////////////////////////////////////------�궨��ӿ�-------////////////////////////////////////


#define I18N_STR(ENUM_I18N) I18N::getInstance()->getcStringByKey(ENUM_I18N)







//////////////////////////-----------I18N��------.///////////////////////////////////
class I18N : public CCObject {
public:
	~I18N();
    /* ��ȡ���� */
    static I18N* getInstance();
    
    /* ��ʼ�� */
    virtual bool init();

    /* ����Keyֵ��ȡ�ַ���,����CCString���� */
    CCString* getString(ENUM_I18N enStrKey);

    /* ����Keyֵ��ȡ�ַ���,����const char*���� */
    const char* getcString(ENUM_I18N enStrKey);

	/* �������͵�Keyֵ��ȡ�ַ���,����const char*���� */
	const char* getcStringByKey( int iKey );

	/* ��ȡ�������ַ��� */
	const char* getcErrorCode(int iCode);
private:    /* ˽�з��� */
    /* �������ļ��ж�ȡ�ַ��������浽�ֵ��� */
    void loadStringsFromConf(CCDictionary* dict, const char* filePath);

private:    /* ��Ա���� */
    /* I18N���� */
    static I18N* mI18N;

	/* ��Ϸ���õ����ַ����ֵ� */
	CCDictionary* mStringDict;

	/* ��������ַ����ֵ� */
	CCDictionary* mErrorCodeDict;
};



#endif