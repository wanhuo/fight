/*******************************
I18N.cpp



		使用
		1.调用处包含头文件
			#include "tools/tools.h"
		2.调用
			I18N_STR(1)-返回字符串

******************************/

#include "I18N.h"
#include "CsvUtil.h"


/* 初始化变量 */
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

    /* 初始化字典 */
    mStringDict = CCDictionary::create();
    mStringDict->retain();

	mErrorCodeDict = CCDictionary::create();
	mErrorCodeDict->retain();

    /* 读取配置文件的字符串 */
    loadStringsFromConf(mStringDict, PATH_I18N_PUBLIC);
    loadStringsFromConf(mErrorCodeDict, PATH_I18N_ERROR_CODE);
    return true;
}

CCString* I18N::getString( ENUM_I18N enStrKey ) {
    CCObject* obj = mStringDict->objectForKey(enStrKey);

    /* 如果找不到字符串，则返回空白字符串 */
    if(obj == NULL) {
        obj = CCString::create("");
    }
    return (CCString *)obj;
}


const char* I18N::getcString( ENUM_I18N enStrKey ) {
	CCString* pStr = getString(enStrKey);

	/* 如果找不到字符串，则返回空白字符串 */
	if(pStr == NULL) {
		return "";
	}

	return pStr->getCString();
}

const char* I18N::getcStringByKey( int iKey ) {
	CCObject* obj = mStringDict->objectForKey(iKey);

	/* 如果找不到字符串，则返回空白字符串 */
	if(obj == NULL) {
		obj = CCString::create("");
	}
	return ((CCString *)obj)->getCString();
}

const char* I18N::getcErrorCode( int iCode ) {
	CCObject* obj = mErrorCodeDict->objectForKey(iCode);

	/* 如果找不到字符串，则返回空白字符串 */
	if(obj == NULL) {
		obj = CCString::create("");
	}
	return ((CCString *)obj)->getCString();
}

/* ---------------- 私有方法 ----------------- */

void I18N::loadStringsFromConf(CCDictionary* dict, const char* filePath) {
    CsvUtil::getInstance()->loadFile(filePath);

    CCSize size = CsvUtil::getInstance()->getFileRowColNum(filePath);

    int iRowNum = size.width;
    int iColNum = size.height;

    /* 如果列数小于2，表示配置文件有问题 */
    if(iColNum < 2) {
        return;
    }

    /* 将配置文件的所有字符串存放到字典中（忽略第一行） */
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




