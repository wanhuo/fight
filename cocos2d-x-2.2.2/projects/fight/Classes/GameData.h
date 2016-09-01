//
//  GameData.h
//  King
//
//  Created by mac on 14-3-28.
//
//

#ifndef __King__GameData__
#define __King__GameData__

#include "cocos2d.h"
USING_NS_CC;

class GameData : public CCObject
{
public:
    static GameData* sharedGameData();
   
    CC_SYNTHESIZE(int, money, Money);   //Ӣ�۵Ľ�Ǯ
    
    CC_SYNTHESIZE(int, mapIndex, MapIndex); //�洢��ǰ�Ĺؿ���
   
    CC_SYNTHESIZE(bool, isBeginer, Isbeginer);
    
    CC_SYNTHESIZE(float, _soundVolume, SoundVolume);
    
    CC_SYNTHESIZE(float, _musicVolume, MusicVolume);
    
    CC_SYNTHESIZE(CCDictionary*, chengjiu,ChengJiu);
    
    CC_SYNTHESIZE(int, shengmingLevel, ShengmingLevel);
    
    CC_SYNTHESIZE(int, gongjiLevel, GongjiLevel);
    
    CC_SYNTHESIZE(int, fangyuLevel, FangyuLevel);
    
    CC_SYNTHESIZE(int, nuqiLevel, NuqiLevel);
    
    CC_SYNTHESIZE(bool, jinjiDuobi, JinjiDuobi);
    
    CC_SYNTHESIZE(bool, shoushen, Shoushen);
    
    CC_SYNTHESIZE(bool, fuhuo,Fuhuo);
    
    CC_SYNTHESIZE(bool, nuqibao, Nuqibao);
    
    CC_SYNTHESIZE(bool, firstTishiShuxing, FirstTishiShuxing);
    
    CC_SYNTHESIZE(bool, firstTishiNuqi, FirstTishiNuqi);
    
    CC_SYNTHESIZE(bool, isJihuo, IsJihuo);
    
    CC_SYNTHESIZE(bool, isShenmi, IsShenmi);
    
    CC_SYNTHESIZE(int, lastNuqi, LastNuqi);
    
    CC_SYNTHESIZE(bool, bazhinv, Bazhinv);
    
    CC_SYNTHESIZE(bool, bajiubei, Bajiubei);
    
    CCDictionary*  descriptions;
    
    void alterShengMingLevel();
    
    void alterGongJiLevel();
    
    void alterFangyuLevel();
    
    void alterNuqiLevel();
    
    void alterMoney(int delta);

    void alertMapIndex(int delta = 1);
    
    void alterHEROATK();
    
    void alterHEROHP();
    
    void alterHERODEFINE();
    
    void alterHERONUQI();
    
    void reset();
    
    void flush();   //�����ݱ��浽�ⲿ�ļ���

    void buyHeroATK(int heroATK);  //����Ӣ�۹�����
    
    void buyHeroHp(int incHp);   //����Ӣ��Ѫ��
    
    void buyHeroDefine(int incD); //����Ӣ�۷�����
    
    void buyHeroNuqi(int incN);  //����Ӣ��ŭ��
    
    void buyHeroShanbi();   //��������
    
    void buyHeroShoushen();  //��������
    
    int extraNuqi;
    
    int getExtraNuqi();
    
    void setExtraNuqi(int nuqi);
    
	static int HEROATK;  	//����������

	static int HEROHP;     	//���Ѫ��

	static int HEROPOM;    	//��ɱ������

	static int HEROUPPOM; 	//��ɱ������

	static int HEROBOM;    	//Ӣ�۱�����
	
    static int HeroDefine;  //Ӣ�۷�����
    
    static int HeroNuqi;    //Ӣ��ŭ��
    
    static bool HeroCanShanbi;  //Ӣ���Ƿ��������
    
    static bool HeroCanShoushen;  //Ӣ���Ƿ��������
    
    bool getJuqing(int index);
    
public:
    GameData();
    
    ~GameData();
    
    bool init();
};

#endif /* defined(__King__GameData__) */
