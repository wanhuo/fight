/*******************************
I18N.cpp



		ʹ��
		1.���ô�����ͷ�ļ�
			#include "tools/tools.h"
		2.����
			I18N_STR(1)-�����ַ���

******************************/

#include "I18N.h"
#include "CsvUtil.h"


/* ��ʼ������ */
I18N* I18N::mI18N = NULL;

I18N* I18N::getInstance() {
    if(mI18N == NULL) {
        mI18N = new I18N();
        if(mI18N && mI18N->init()) {
            mI18N->autorelease();
        }
        else {
            CC_SAFE_DELETE(mI18N);
            mI18N = NULL;
        }
    }

    return mI18N;
}

I18N::~I18N() {
	CC_SAFE_RELEASE(mStringDict);
	CC_SAFE_RELEASE(mErrorCodeDict);
}


bool I18N::init() {

    /* ��ʼ���ֵ� */
    mStringDict = CCDictionary::create();
    mStringDict->retain();

	mErrorCodeDict = CCDictionary::create();
	mErrorCodeDict->retain();

    /* ��ȡ�����ļ����ַ��� */
    loadStringsFromConf(mStringDict, PATH_I18N_PUBLIC);
    loadStringsFromConf(mErrorCodeDict, PATH_I18N_ERROR_CODE);
    return true;
}

CCString* I18N::getString( ENUM_I18N enStrKey ) {
    CCObject* obj = mStringDict->objectForKey(enStrKey);

    /* ����Ҳ����ַ������򷵻ؿհ��ַ��� */
    if(obj == NULL) {
        obj = CCString::create("");
    }
    return (CCString *)obj;
}


const char* I18N::getcString( ENUM_I18N enStrKey ) {
	CCString* pStr = getString(enStrKey);

	/* ����Ҳ����ַ������򷵻ؿհ��ַ��� */
	if(pStr == NULL) {
		return "";
	}

	return pStr->getCString();
}

const char* I18N::getcStringByKey( int iKey ) {
	CCObject* obj = mStringDict->objectForKey(iKey);

	/* ����Ҳ����ַ������򷵻ؿհ��ַ��� */
	if(obj == NULL) {
		obj = CCString::create("");
	}
	return ((CCString *)obj)->getCString();
}

const char* I18N::getcErrorCode( int iCode ) {
	CCObject* obj = mErrorCodeDict->objectForKey(iCode);

	/* ����Ҳ����ַ������򷵻ؿհ��ַ��� */
	if(obj == NULL) {
		obj = CCString::create("");
	}
	return ((CCString *)obj)->getCString();
}

/* ---------------- ˽�з��� ----------------- */

void I18N::loadStringsFromConf(CCDictionary* dict, const char* filePath) {
    CsvUtil::getInstance()->loadFile(filePath);

    CCSize size = CsvUtil::getInstance()->getFileRowColNum(filePath);

    int iRowNum = size.width;
    int iColNum = size.height;

    /* �������С��2����ʾ�����ļ������� */
    if(iColNum < 2) {
        return;
    }

    /* �������ļ��������ַ�����ŵ��ֵ��У����Ե�һ�У� */
    CCString* keyStr = CCString::create("");
    CCString* valueStr = NULL;
    for(int i = 1; i < iRowNum; i++) {
        valueStr = CCString::create("");

        keyStr->m_sString	= CsvUtil::getInstance()->get(i, 0, filePath);
        valueStr->m_sString = CsvUtil::getInstance()->get(i, 1, filePath);

        int iKey = 0;
        sscanf(keyStr->getCString(), "%d", &iKey);
        dict->setObject(valueStr, iKey);
    }

}




