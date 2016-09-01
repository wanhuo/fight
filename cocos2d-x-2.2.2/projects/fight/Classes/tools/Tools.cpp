/**
Tools.cpp

工具类封装入口

使用--
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

/** 获取播放控制器句柄 */
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


*内存保持---单例类
AppDelegate::AppDelegate() 中调用 --(必须)
*/
void Tools::tool_safe_retain()
{    
	CC_SAFE_RETAIN(CsvUtil::getInstance());
	CC_SAFE_RETAIN(I18N::getInstance());
	
}	

/*

	
* 内存释放--
AppDelegate::~AppDelegate() 中调用 --(必须)
*/
void Tools::tool_safe_release()
{    
	CC_SAFE_RELEASE(CsvUtil::getInstance());
	CC_SAFE_RELEASE(I18N::getInstance());
	
}