

#ifndef __def_h__
#define __def_h__
#ifndef nullptr
#define nullptr 0
#endif
/** 判断字符串是否为空 */
#define isStringNull(value) (value && strlen(value) > 0 ?false:true)

//..异常返回
#define returnIfValue(value) \
	if (value){ \
		return; \
	} \

//..异常返回
#define returnNullIfValue(value) \
	if (value){ \
		return NULL; \
	} \

//..异常返回
#define returnfalseIfValue(value) \
	if (value){ \
		return false; \
	} \

//..continue
#define continueIfVaule(value) \
	if (value){ \
		continue; \
	} \

//..break
#define breakIfVaule(value) \
	if (value){ \
		break; \
	} \

//..get/set
#define defineSetGet(type, value) \
	type value; \
	inline void set##value(type _value){ \
		value = _value; \
	}\
	inline type get##value(){ \
		return value; \
	} \

//..static 类型 get/set
#define defineStaticSetGet(type, value) \
	static type value; \
	static void set##value(type _value){ \
		value = _value; \
	}\
	static type get##value(){ \
		return value; \
	} \

//..delete
#define deleteIfNotNull(p)\
	if (p){ \
		delete p; \
		p = nullptr; \
	} \

//..free
#define freeIfNotNull(p)\
	if (p){ \
		free(p); \
		p = nullptr; \
	} \
	
//DEBUG开启
#define __debug_on__ 1
#if __debug_on__
#define debug CCLog
#else
#define debug (0)
#endif

/* -------------- 语言文件路径------------- */
#define PATH_I18N_PUBLIC 			"i18n/public.csv"      	/* 公用语言文件 */
#define PATH_I18N_ERROR_CODE 		"i18n/errorCode.csv"      /* 错误码语言文件 */

//..默认文本文件路径
#define __default_text_path__ 		"text/text.xml"
#endif