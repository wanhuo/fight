#include "AppDelegate.h"
#include "MenuScene.h"
#include "GameData.h"
#include "GameScene.h"
#include "SelectScene.h"
#include "SimpleAudioEngine.h"
#include "TipStory2.h"
#include "TipStory3.h"
#include "LoadingScene.h"
#include "XMLData.h"
#include "Game.h"

using namespace CocosDenshion;
USING_NS_CC;

AppDelegate::AppDelegate() {
	

	Tools::getInstance()->tool_safe_retain();	
	CC_SAFE_RETAIN(XMLData::sharedXMLData());
	
}

AppDelegate::~AppDelegate() 
{
	Tools::getInstance()->tool_safe_release();
	CC_SAFE_RELEASE(XMLData::sharedXMLData());
}

bool AppDelegate::applicationDidFinishLaunching() {

    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
  
    pDirector->setOpenGLView(pEGLView);
    pEGLView->setDesignResolutionSize(800, 480, kResolutionExactFit);

    pDirector->setDisplayStats(false);
    CCScene *pScene = LoadingScene::scene();

    pDirector->runWithScene(pScene);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();
    
    GameData::sharedGameData()->flush();   //±£´æÊý¾Ý

    // if you use SimpleAudioEngine, it must be pause
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
     SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
