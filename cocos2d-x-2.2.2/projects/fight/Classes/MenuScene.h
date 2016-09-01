//
//  MenuScene.h
//  King
//
//  Created by mac on 14-3-26.
//
//

#ifndef __King__MenuScene__
#define __King__MenuScene__

#include "BaseLayer.h"

class MenuScene : public BaseLayer
{
public:
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    void loadingBack(CCObject* pSender);
    
    CREATE_FUNC(MenuScene);
    
    void StartGame(CCObject* pSender);
    
    void AboutGame(CCObject* pSender);
    
    void onEnter();
    
    void onExit();
    
    void onEnterTransitionDidFinish();
    
    void begingame();
    
    void brate();
    
    void screenShake(int frameNum,int yValue);
    
    void resumeShake(CCObject* pSender);
    
    void MoreGame(CCObject* pSender);
    
    void openAWebsite(std::string url);
    
    CCMenuItem* beginItem;
    
    CCMenuItem* moreGame;
    
    CCMenuItemToggle* music;
    
    CCMenuItem* about;
    
    void musicOn(CCObject* pSender);
    
    int IsmusicOn;
};

#endif /* defined(__King__MenuScene__) */
