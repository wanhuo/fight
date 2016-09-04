//
//  GameScene.h
//  King
//
//  Created by mac on 14-3-26.
//
//

#ifndef __King__GameScene__
#define __King__GameScene__

#include "cocos2d.h"
USING_NS_CC;
#include "BaseLayer.h"
#include "Monster.h"
#include "ARPG.h"
#include "MenuLayer.h"
#include "TipStory.h"
#include "cocos-ext.h"
#include "HeroBoss.h"

typedef enum{
    k_Operate_Pause = 0,
    k_Operate_Resume
}OperateFlag;

class Map : public CCLayer
{
public:
    CCSprite* s1;
    static Map* create(int id);
    bool init(int id);
    CCSize getContentSize();
};

class Hero;
class Wave;
class GameScene : public BaseLayer,public PlaysDelegate
{
public:    
    GameScene();
    
    ~GameScene();
    
    void initHero();
    
    void addCache();
    
    static GameScene* create(int index,int modeId = 0);
    
    static CCScene* scene(int index,int modeId = 0);
    
    bool init(int index,int modeId = 0);
    
    void update(float dt);
    
    void updatePosition(float dt);
    
    void setViewpointCenter(CCPoint P,bool instant = true);
    
    void commanAttack();

    void addWaves();
    
    void addMonster();
    
    void addBoss();
    
    void gameLogic(float dt);
    
    void juqingLogic(float dt);
    
    void juqingMap(float dt);
    
    Wave* getCurrentWave();
    
    virtual bool actionDidAttack(ARPG* p);
    
    virtual bool actionDidDie(ARPG* p);
    
    bool collisionBetweenAttacker(ARPG* attacker,ARPG* target,CCPoint position);
  
    bool isGameover();
    
    void Gameover(float dt);
    
    void GameoverCallback();
    
    void onEnterTransitionDidFinish();
    
    void onEnter();
    
    void onExit();
    
    void alertData();
    
    void Tipstory();
    
    void hitEffect(CCPoint p);
    
    void remove(CCNode* pSender);
    
    void shop(CCObject* pSender);
    
    void shop2();
    
    void jihuo();
    
    void shop(int index=0);
    
    void pause(CCObject* pSender);
    
    void resume();
    
    void sound();
    
    void music();
    
    void operateAllSchedulerAndActions(cocos2d::CCNode* node, OperateFlag flag);
    
    void checkCollisionWithProps();
    
    void screenShake(int frameNum,int yValue);
    
    void resumeShake();
    
    void protect(ARPG* arpg);  //��ֹ����

    long millisecondNow(){
		cocos2d::cc_timeval now;
		cocos2d::CCTime::gettimeofdayCocos2d(&now, NULL);
		return (now.tv_sec * 1000 + now.tv_usec / 1000);
	}
    
    void removeProp();
    
    void next(CCObject* pSender);

    void lazyInit(float dt);
    
    void tech(float dt);
    
    CCLayerColor* black;
    
    void readyGo(float dt);
    
    void goReady();
    
    void goReadyCall();

    void tishiNuqi();
    
    void tipsPause();
    
    void tipsResume();
    
    void addTips();
    
    void removeTips();
    
    void registerWithTouchDispatcher();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
   
    void addTips2();
    
    void mapThreeLogic();

    void JuqingHeroDie(float dt);
    
    void juqingThreeEnd();
    
    void juqingThreeEndCallback();
    
    void resumeJiangzhi();
    
    bool isHav_RemainTime();
    
    void pause1();
    
    void resume1();
    
    void operateAllSchedulerAndActions2(cocos2d::CCNode* node, OperateFlag flag);
    
    void addCard(int id);
    
public:
    Monster* heroBoss;
    CCSprite* tishiNuqiSprite;
    bool failture;
    MenuLayer* _menuLayer;
    Map* bg1;
    Map* bg2;
    Hero* hero;
	CCArray* npc;
    CCArray* waves;
    CCArray* props;
    CCArray* bullets;
	Monster* boss;
    int npcCount;
    int id;
    int waveID;
    int monsterNum;
    int oldmonsterNum;
    int monsterTypes;
    bool isGameOver;
    CCSprite* r;
    CCSprite* e;
    CCSprite* a;
    CCSprite* d;
    CCSprite* y;
    CCSprite* g;
    CCSprite* o;
    CCArray* readyGoArr;
    bool isGameStart;
    bool isAddMonster;
    CCSprite* tip1;
    CCSprite* tip01;
    CCSprite* tip2;
    CCSprite* tip3;
    CCMenuItemSprite* item;
    CCMenu* menu;
    cocos2d::gui::UILabel* label;
    cocos2d::gui::UILabel* label1;
    cocos2d::gui::UILabel* label2;
    bool tipsTouch;
    bool mapThreeJuqing;
    int juqingThreeIndex;
    bool first;
    bool isJuqingFour;
    
    bool canSay;
    
    CCSprite* hunhuntouxiang;
    CCSprite* bosstouxiang;
    CCSprite* roletouxiang;
    CCSprite* nvroletouxiang;
    
    void addTip01(int index ,int monsterID);
    void addTip1(int index , int roleid);
    void setText();
    void setText1();
    void setText2();
    
    
    CC_SYNTHESIZE(int,maxLianji , MaxLianji);//���������
    CC_SYNTHESIZE(int, remainTime, RemainTime); //��ǰ��ͼʣ���ʱ��
    CC_SYNTHESIZE(bool, isPause, IsPause);
    bool isTeach;
    CCArmature* jiaodiTishi;
    int modeID;
    int killMonsterNum;
    int kilometer;
    int mapsHasGoneNum;
    int targetKilometer;
    bool isNuqiTishi;
    bool hasOver;
    
    void removeNpc(float dt);
};

#endif /* defined(__King__GameScene__) */
