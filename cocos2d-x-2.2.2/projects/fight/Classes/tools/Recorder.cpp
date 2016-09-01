
#include "Tools.h"

//Get Recorder value by key, if the key doesn't exist, a default value will return. 
bool Recorder::getBoolForKey (const char *pKey, bool defaultValue){
	return CCUserDefault::sharedUserDefault()->getBoolForKey(pKey, defaultValue);
}

//Get integer value by key, if the key doesn't exist, a default value will return. 
int Recorder::getIntegerForKey (const char *pKey, int defaultValue) {
	return CCUserDefault::sharedUserDefault()->getIntegerForKey(pKey, defaultValue);
}

//Get float value by key, if the key doesn't exist, a default value will return. 
float Recorder::getFloatForKey (const char *pKey, float defaultValue){
	return CCUserDefault::sharedUserDefault()->getFloatForKey(pKey, defaultValue);
}

//Get double value by key, if the key doesn't exist, a default value will return. 
double Recorder::getDoubleForKey (const char *pKey, double defaultValue){
	return CCUserDefault::sharedUserDefault()->getDoubleForKey(pKey, defaultValue);
}

//Get string value by key, if the key doesn't exist, a default value will return. 
std::string Recorder::getStringForKey (const char *pKey, const std::string &defaultValue){
	return CCUserDefault::sharedUserDefault()->getStringForKey(pKey, defaultValue);
}

//Set bool value by key. 
void Recorder::setBoolForKey (const char *pKey, bool value){

	if (!isStringNull(pKey)){
		CCUserDefault::sharedUserDefault()->setBoolForKey(pKey, value);
		Recorder::flush();
	}
}

//Set integer value by key. 
void Recorder::setIntegerForKey (const char *pKey, int value){

	if (!isStringNull(pKey)){
		CCUserDefault::sharedUserDefault()->setIntegerForKey(pKey, value);
		Recorder::flush();
	}
}

//Set float value by key. 
void Recorder::setFloatForKey (const char *pKey, float value){

	if (!isStringNull(pKey)){
		CCUserDefault::sharedUserDefault()->setFloatForKey(pKey, value);
		Recorder::flush();
	}
}

//Set double value by key. 
void Recorder::setDoubleForKey (const char *pKey, double value){

	if (!isStringNull(pKey)){
		CCUserDefault::sharedUserDefault()->setDoubleForKey(pKey, value);
		Recorder::flush();
	}
}

//Set string value by key. 
void Recorder::setStringForKey (const char *pKey, const std::string &value){

	if (!isStringNull(pKey)){
		CCUserDefault::sharedUserDefault()->setStringForKey(pKey, value);
		Recorder::flush();
	}
}

//Save content to xml file. 
void Recorder::flush (){
	CCUserDefault::sharedUserDefault()->flush();
}
