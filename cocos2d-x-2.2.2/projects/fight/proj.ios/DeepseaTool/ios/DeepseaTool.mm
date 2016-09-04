//
//  DeepseaTool.cpp
//  fight
//
//  Created by caoyusheng on 1/9/16.
//
//

#import "DeepseaTool.h"
#import "AdTool.h"
#import "AppController.h"
#import "GameData.h"
#import "Define.h"

static DeepseaTool* sInstance = NULL;

DeepseaTool* DeepseaTool::getInstance()
{
    if(sInstance == NULL)
    {
        sInstance = new DeepseaTool();
    }
    return sInstance;
}

void DeepseaTool::showTost(char *text)
{
    NSString *str = [NSString stringWithCString:text encoding:NSUTF8StringEncoding];
    [(AppController *)appController showTost: str];
}

void DeepseaTool::showBuySuccessTost()
{
    [(AppController *)appController showTost: @"恭喜，购买成功"];
}

void DeepseaTool::showMoneyErrorTost()
{
    [(AppController *)appController showTost: @"金币不足"];
}

void DeepseaTool::showInterstitialAd()
{
    [[AdTool alloc] showInterstitialAd];
}

void DeepseaTool::showInterstitialAdSuccess()
{
    
}

void DeepseaTool::showInterstitialAdFail()
{
    
}

void DeepseaTool::showVedioAd()
{
    [[AdTool alloc] showVedioAd];
}

void DeepseaTool::showVedioAdSuccess()
{
    KingData->alterMoney(AD_MONEY_REWORD);
    [(AppController *)appController showTost: [NSString stringWithFormat:@"获得%d金币", AD_MONEY_REWORD]];
//    CCUserDefault::sharedUserDefault()->flush();
//    CCUserDefault::sharedUserDefault()->purgeSharedUserDefault();
}

void DeepseaTool::showVedioAdFail()
{
    
}