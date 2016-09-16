//
//  ConfigStore.cpp
//  fight
//
//  Created by caoyusheng on 16/9/16.
//
//

#include "ConfigStore.hpp"

ConfigStore *ConfigStore::instance = NULL;

ConfigStore *ConfigStore::getInstance()
{
    if(NULL == instance)
    {
        instance = new ConfigStore();
    }
    return instance;
}
