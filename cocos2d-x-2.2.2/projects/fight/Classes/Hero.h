//
//  Hero.h
//  King
//
//  Created by mac on 14-3-26.
//
//

#ifndef __King__Hero__
#define __King__Hero__

#include "ARPG.h"
class Ef;
class Hero : public ARPG
{
public:
    int hasCollisionNum;
    
    void zadiShengyin(float dt);
    
    CREATE_FUNC(Hero);
    bool init();
    void update(float dt);
    void commanAttack();
    int state;
    void autoNormalAttact(); //��ǰ����ʱ��  �� �ϴι�����ʱ�� > ��ȫʱ��    coding
    void setIsARPG_Acion(int ARPG_Acion); 	/** ���ù��ܼ� �ı䵱ǰ�Ĺ��ܼ�״̬ ����Ϊ-1ȡ�����ܼ� */
    
    void move();
    
    void skill1(CCObject* pSender);
    
    void skill2(CCObject* pSender);
    
    void skill3(CCObject* pSender);
    
    void skill4(CCObject* pSender);
    
    void skill1Animation(float dt);
    
    void skill2Animation(float dt);

    void skill2Action(CCObject* pSender);
    
    void skill1Action();
    
    void skill3Action(CCObject* pSender);
    
    void skill4Action(CCObject* pSender);
    
    void jumpRise(int height,float time,CCPoint p,int jumpTimes);
   
    void jumpCallback();
    
    CCArmature* addMotion(CCAction* act,float time);
    
    void removeMotion(CCObject* pSender);
    
    void moveTo(CCNode* node,float dt ,float x);
    
    void zadi2();
    
    void zadi();
    
    void yanmu();
    
    void shandianqiou();
    
    void shandian(int skill3AnimationId);
    
    Ef* skill1end(const char* name,CCPoint p);
    
    void qianxiaqian(const char* name);
    
    void shop(CCObject* pSender);
    
public:
    bool isJinjiDuobi;
    
    bool isZudang;
    
    int qianqianNum;
    
    void qianqian(int dir);
    
    void qianqianCallback();
    
    void fuhuo();
    
    bool isCanDirect;
    
    Hero();
    
    ~Hero();
    
    bool isSkill1;
    
    bool isJiXuSkill1;
    
    bool isSkill2;
    
    bool isJiXuSkill2;
    
    bool isSkill3;
    
    bool isSkill4;
    
    int skill3Scale;
    
    bool isCommanAttack;
    
    bool startNormalAttact;
    
    int lastNormalAttactTime;
    
    int downCount; //������ڼ��ΰ�����
    
    int downAtk;  //���ܼ��ڼ��ΰ���
    
    bool isOnlyHandNow; //��ǰ�ǿ���
    
    bool isFly;  //�Ƿ񱻻��ɡ������в���
    
    int doubleHit_Type; //���ֵ�ǰ��������������
	
    bool isActionEnding; /** ���Ե�ȭͷ����֮�󲢲�æ�Ͻ��ܶ��ǲ���һ��boolan ֵ */
    
    int doubleHit_Save; //���涯������ǰ���µĹ�����ʽ
    
    int atkCount; //��ǰ���˼��£����ڲ�����������
    
    int lianjiNum;
    int lianjiTime;
    
    int skillAnimationId;
    
    int skill2AnimationId;
    
    int skill3AnimationId;
    
    int skill4AnimationId;
    
    int commanAttackIndex;
    
    void actionCallback(CCArmature *pArmature,MovementEventType eventType, const char *animationID);
    
    void setAction(int actionID,int times);
    
    void setAction(int actionID);
    
    void commanAttackResume(float dt);
    
    int commanAttackResumeNum;
    
    void die();
    
    void shanbi();
    
    bool isHaveFuhuo;
    
    bool isCollision;
    
    void daodiqishen();
    
    void daodiqishenCallback(CCObject* pSender);
    
    bool isdaodiqishen;
    
    int daodiqishenID;
    
    int daodiTime;
};

#endif /* defined(__King__Hero__) */
