//
//  ConfigStore.hpp
//  fight
//
//  Created by caoyusheng on 16/9/16.
//
//

#ifndef ConfigStore_hpp
#define ConfigStore_hpp

#include <stdio.h>
#include "cocos2d.h"

class ConfigStore : public cocos2d::CCObject
{
public:
    static ConfigStore *getInstance();
    
    int configVersion;
    
    bool isReplyLater;
    
private:
    static ConfigStore *instance;
};

#endif /* ConfigStore_hpp */
