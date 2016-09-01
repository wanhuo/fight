

#ifndef __def_h__
#define __def_h__
#ifndef nullptr
#define nullptr 0
#endif
/** �ж��ַ����Ƿ�Ϊ�� */
#define isStringNull(value) (value && strlen(value) > 0 ?false:true)

//..�쳣����
#define returnIfValue(value) \
	if (value){ \
		return; \
	} \

//..�쳣����
#define returnNullIfValue(value) \
	if (value){ \
		return NULL; \
	} \

//..�쳣����
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

//..static ���� get/set
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
	
//DEBUG����
#define __debug_on__ 1
#if __debug_on__
#define debug CCLog
#else
#define debug (0)
#endif

/* -------------- �����ļ�·��------------- */
#define PATH_I18N_PUBLIC 			"i18n/public.csv"      	/* ���������ļ� */
#define PATH_I18N_ERROR_CODE 		"i18n/errorCode.csv"      /* �����������ļ� */

//..Ĭ���ı��ļ�·��
#define __default_text_path__ 		"text/text.xml"
#endif