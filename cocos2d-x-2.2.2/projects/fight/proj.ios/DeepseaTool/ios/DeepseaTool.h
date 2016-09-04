//
//  DeepseaTool.hpp
//  fight
//
//  Created by caoyusheng on 1/9/16.
//
//

#ifndef DeepseaTool_hpp
#define DeepseaTool_hpp

class DeepseaTool
{
private:
    
    DeepseaTool(){}
    
public:
    
    static DeepseaTool * getInstance();
    
    void *appController;
    
    void showTost(char *text);
    
    void showBuySuccessTost();
    
    void showMoneyErrorTost();
    
    void showInterstitialAd();
    
    void showInterstitialAdSuccess();
    
    void showInterstitialAdFail();
    
    void showVedioAd();
    
    void showVedioAdSuccess();
    
    void showVedioAdFail();
};

#define AD_MONEY_REWORD 10000

#endif /* DeepseaTool_hpp */
