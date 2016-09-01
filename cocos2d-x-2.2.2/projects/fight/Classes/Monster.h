//
//  Monster.h
//  King
//
//  Created by mac on 14-3-27.
//
//

#ifndef __King__Monster__
#define __King__Monster__

#include "ARPG.h"
#include "State.h"
#include "StateMachine.h"
#include "Prop.h"
#include "BloodBar.h"


class Monster :public ARPG
{
protected:
    StateMachine<Monster>*  m_pStateMachine;
public:
    Monster();
    
    virtual ~Monster();

    static Monster* create(int id,int mapIndex);
    
    bool init(int id,int mapIndex);
    
    bool initAttr();
    
    virtual bool initPosition();
    
    bool initBloodBar();
    
    void stand();
    
    void move();
    
    void moveCallback(CCObject* pSender);
    
    bool isToWander();   //�Ƿ�����ǻ�Ѳ�� С����д�������д
    
    virtual void attack();
    
    bool isAttack();
    
    bool inAIRange();
    
    void atkNpc(int Direction);	/** ���� */
    
    virtual void wander();
    
    virtual void WanderCallback();
    
    virtual float getNextPosx();
    
    virtual bool canAttack();
    
    bool inAttackRange();
    
    virtual void attackM1();
    
    virtual void attackM2();
    
    virtual void attackM3();
    
    virtual void SeekRole();
    
    void SeekRoleCallback(CCObject* pSender);
    
    StateMachine<Monster>*  GetFSM()const{return m_pStateMachine;} //��ȡ��ǰ��״̬��

    virtual void update(float dt);
    
    void setSpeed(const float sp);
        
    void setInit();/** ��npc������������Ϊ��ʼ״̬ */
    
    void beAttackCallFuncO(CCObject* pSender);
    
    virtual void getUp();
    
    bool isSeekRole;
public:
   
    int delayAttackTime;
    float aiRange;  //���Ｄ��ai
    float attackRange;  //���﹥����Χ

    /** �ж��Ƿ񻻹���״̬ */
	bool isChange;
    bool isChangeATK;
    
    
    /** NPC4��NPC7��ǿ���ƶ��� */
    bool isEnforceMove;
    bool isEnforceLeft;
    bool isEnforceRight;
    
    /** 2��Զ�̹�����NPC ���Ǵ������㹥������� ���ԼӸ�Զ�̹��������ƫ���� */
    float Atk_remote;
    
    // -----------------------npc�ĸ�����ֵ
	/** ��ֵһ�����ɹ�Ӣ�۴������ڵ����������ﵽһ��������ʱ����Ӣ�۵Ĺ���һ��ʱ�� */
	int atkHeroCount;
	/** ��ֵ���������������ڵ������������ﵽһ���Ĵ�����ʱ��ŭ������ ����boss�������⼼�� �޵� ,�Լ�npc�Ļ��� */
	int byAtkHeroCount;
 
    CCArray* prop;
    
	bool isDrive;
    /** �Ѿ��Լ�����ж϶��ٴ��˵��ﵽһ�������Ϳ�ʼ�����ƶ� */
	int onCount;
	/** ��������npcѪ��С��һ��������һ���������� */
	bool isRun;
    
    /** ��ǰnpc�Ƿ��ǵ�ǰnpc�еľ�Ӣ�� */
	bool isElite;
    
    /** ǿ�ƹ��� */
	bool isForce;
	/** npc�Ļ���͸���� */
	int NpcAphla ;
	/** �Ƿ񲥷�������Ч */
	bool isPlayDie;
    
    /** boss�Ƿ��������Ļ�� */
	bool isBoss;
	/** �����Ƿ������ */
	bool isShow;
	/** ��ǰboss�Ƿ���Ҫ��Ѫ�� */
	bool isShowHead;
    
    /** Զ�̹����ǿ���ƶ������﹥�����κ����һ��ʱ����ƶ��߶�״̬ */
	bool isOnMove;
    int PassTime;
    int passCount;
    
    /**��ǹ�ֵ��ص���Ӣ����ײ��Խ��Ӣ�۵�����*/
    bool isPass;
    
    /** NPC���� */
	int name;
    /** ɱ��npc�ָ�����ֵ */
	int NPCPOM;

    float getX();
    float getY();
    
    virtual void die();

public:
    int mapIndex;
    
    int modeID;

    float starttime;
    
    int canAttackTimes;
};

#endif /* defined(__King__Monster__) */
