/*
    �ļ�����    FileLoadUtil.c
    �衡����    �ı��ļ���ȡ����
    �����ˣ�   

    �������ڣ�   2013.07.18
*/


#include "FileLoadUtil.h"
#include "StringUtil.h"

FileLoadUtil* FileLoadUtil::mFileLoadUtil = NULL;

/*
* ����һ���ļ���ȡ����
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
���ļ���ȡһ������

sFilePath--�ļ���

*/
CCArray* FileLoadUtil::getDataLines( const char* sFilePath )
{
    CCArray* linesList = CCArray::create();

    unsigned long pSize = 0;
    unsigned char* chDatas = CCFileUtils::sharedFileUtils()->getFileData(sFilePath, "r", &pSize);

    /* ������ת��Ϊ�ַ������� */
    CCString* str = CCString::createWithData(chDatas, pSize);

	//������ÿһ�ж����зָ�-�ָ��Ϊ'\n'(���з�)
    linesList = StringUtil::getInstance()->split(str->getCString(), "\n");
    
	free(chDatas);

    return linesList;
}
