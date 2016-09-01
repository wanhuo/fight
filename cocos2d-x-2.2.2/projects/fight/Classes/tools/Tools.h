#ifndef __TOOLS_H__
#define __TOOLS_H__

#include "cocos2d.h"

//..定义
#include "def.h"

//..Handler
#include "Handler.h"

//..Layer
#include "UI_Layer.h"

//i18n
#include "I18N.h"
//..audio
#include "Audio.h"
//..screen
#include "Screen.h"
//..text
#include "TextUtil.h"
//..recorder
#include "Recorder.h"

//..系统配置
#include "SysConfig.h"

#include "CsvUtil.h"
#include "StringUtil.h"
#include "FileLoadUtil.h"

USING_NS_CC;



class Tools : public CCObject
{

public:

	
	void   tool_safe_retain();    
	void   tool_safe_release();    
	/** 获取句柄 */
	static Tools *getInstance();

	Tools();
	~Tools();
private:

	static Tools *instance;
};
#endif
