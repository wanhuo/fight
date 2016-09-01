
#ifndef __Record_h__
#define __Record_h__

#include "cocos2d.h"
USING_NS_CC;

/** ¼ÇÂ¼ */
class Recorder
{
public:
	//Get bool value by key, if the key doesn't exist, a default value will return. 
	static bool getBoolForKey (const char *pKey, bool defaultValue=false);
    //Get integer value by key, if the key doesn't exist, a default value will return. 
	static int getIntegerForKey (const char *pKey, int defaultValue=0) ;
    //Get float value by key, if the key doesn't exist, a default value will return. 
	static float getFloatForKey (const char *pKey, float defaultValue=0.0f) ;
    //Get double value by key, if the key doesn't exist, a default value will return. 
	static double getDoubleForKey (const char *pKey, double defaultValue=0.0) ;
    //Get string value by key, if the key doesn't exist, a default value will return. 
	static std::string getStringForKey (const char *pKey, const std::string &defaultValue="") ;
    //Set bool value by key. 
	static void setBoolForKey (const char *pKey, bool value) ;
    //Set integer value by key. 
	static void setIntegerForKey (const char *pKey, int value) ;
    //Set float value by key. 
	static void setFloatForKey (const char *pKey, float value) ;
    //Set double value by key. 
	static void setDoubleForKey (const char *pKey, double value) ;
    //Set string value by key. 
	static void setStringForKey (const char *pKey, const std::string &value) ;
    //Save content to xml file. 
	static void flush ();
};

#endif