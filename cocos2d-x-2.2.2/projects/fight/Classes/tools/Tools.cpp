/**
Tools.cpp

�������װ���

ʹ��--
AppDelegate::AppDelegate() {
	

	CC_SAFE_RETAIN(Tools::getInstance()->tool_safe_retain());
	

}

AppDelegate::~AppDelegate() 
{
	CC_SAFE_RELEASE(Tools::getInstance()->tool_safe_release());

}

**/

#include "Tools.h"


Tools* Tools::instance = NULL;

Tools::Tools(){
	//debug("Tools");
}

Tools::~Tools(){
	//debug("~Tools");
}

/** ��ȡ���ſ�������� */
Tools *Tools::getInstance(){

    if(instance == NULL) 
	{
        instance = new Tools();
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
/*


*�ڴ汣��---������
AppDelegate::AppDelegate() �е��� --(����)
*/
void Tools::tool_safe_retain()
{    
	CC_SAFE_RETAIN(CsvUtil::getInstance());
	CC_SAFE_RETAIN(I18N::getInstance());
	
}	

/*

	
* �ڴ��ͷ�--
AppDelegate::~AppDelegate() �е��� --(����)
*/
void Tools::tool_safe_release()
{    
	CC_SAFE_RELEASE(CsvUtil::getInstance());
	CC_SAFE_RELEASE(I18N::getInstance());
	
}