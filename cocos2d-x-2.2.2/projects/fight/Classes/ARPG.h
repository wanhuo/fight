//
//  ARPG.h
//  King
//
//  Created by mac on 14-3-26.
//
//

#ifndef __King__ARPG__
#define __King__ARPG__

enum
{
	 UP = 0,  	    /** �� */       // �ƶ������ɷ�Ϊ ��������
	 DOWN = 1,  	/** �� */
	 LEFT = 2,  	/** �� */
	 RIGHT = 3,   	/** �� */
	 HOLDER = 4   	/** ԭ�� */
};
/*��ɫ����:
 0.վ��
 1.�ƶ�
 2.�ܻ�
 3.�ϸ���
 4.����
 6.����Ԥ������
 7.�����ƶ�(����1��������Ƶ�ʼ���)
 8.��������1(�ɱ�)
 9.��������2(�ɱ�)
 10.��������3(�ɱ�)
 11 ����
 */
#define ANIMATION_STAND "stand"
#define ANIMATION_MOVE "move"
#define ANIMATION_BEATBACK "beatBack" //�ܻ�
#define ANIMATION_UPFLOAT "upfloat" //�ϸ���
#define ANIMATION_DOWNFLOAT "downfloat" //�¸���
#define ANIMATION_GETDOWN "getdown" //����
#define ANIMATION_ATTACKWARNING "attackwarning" //����Ԥ��
#define ANIMATION_MOVEFAST "movefast" ///�����ƶ�
#include "cocos2d.h"
USING_NS_CC;
#include "BloodBar.h"
#include "BeatEffect.h"

#include "cocos-ext.h"
USING_NS_CC_EXT;
typedef enum M_state
{
    s_stand,
    s_move,
    s_attack,
    s_skill,
}M_state;


class ARPG;
class PlaysDelegate
{
public:
    virtual bool actionDidAttack(ARPG* p)=0;
    virtual bool actionDidDie(ARPG* p)=0;
};

class ARPG : public CCNode
{
public:
    BeatEffect* m_beatEffect;//�ܻ�Ч��
    
    bool isUnderAttack;//��ǰ�Ƿ񱻹���
    
    bool isFirstDropBack;//�Ƿ��ڵ���
    
    string m_animationName;//��������
    
	float speedMain;       /** �ƶ��ٶ� */

	int ationState;    	/** �ܶ���״̬ */
    
	int INIT;   	/** �������� ��ʼ״̬ ���� ԭ�ز��� */
    
	int ON_ACTION;  	/** ���Բ���״̬ �Լ�����ʾ �Ͳ��ڲ��ɲ���״̬�� ���������� ������ */
    
	int ARPG_DIE; 	/** Ӣ�۵�����״̬npc����ʧ���Լ��趨�߼����� */
    
	int accord; 	/** �ɲ���״̬�·�Ϊ ����״̬ */

	int ACCORD; 	/** ����״̬ */

	int ACCORD_ ; 	/** ����ǿ��״̬ */

	int OFF_ACTION; 	/** ���ɲ���״̬һ����ָ ��ͣ�� �� ���� */
    
	int action_place;  	/** �������� */

	int orientation ; 	/** �ƶ����� */
    
	CCSprite* spMain; 	/** ��Ҫ�ƶ�������npc ����Ӣ�� */

	bool isJump;       	/** �Ƿ��Ѿ���Ծ�� */

	bool offMove;     	/** �����ƶ�״̬ ���� �ƶ�״̬ */

	int onMove;   	/** �����ƶ�״̬ ���� �ƶ�״̬ */
    
	bool isDie;   	/** �Ƿ��������״̬ */
    
    bool abDie;    /*Ӣ�۳�������*/
    
	bool is_UndoRunState ; 	/** �ñ������жϷ�����Ƿ��ɿ� */

	bool is_UndoAtkState; 	/** �ñ��������жϹ��ܼ��Ƿ��� */

    CCArmature* s;
    
    CCArmature* s2;
    
    CCArmatureAnimation* animation;
    
    PlaysDelegate* delegate;  
    
    CCPoint oldPosition;   //����ԭ����λ��
    
    void draw();
    
    CC_SYNTHESIZE(int, type, Type); //1��Ӣ��  2�ǵ���
    
    CCArray* beatEffects;
    
    
    int safe_time;  //�ܻ�����ʱ��
    
    CC_SYNTHESIZE(int,attackP , AttackP); //���鹥����
    
    CC_SYNTHESIZE(int,attackPP , AttackPP); //���鹥����
    
    CC_SYNTHESIZE(int, hp, HP); //����Ѫ��
    
    CC_SYNTHESIZE(int, maxHp, MaxHp);
    
    CC_SYNTHESIZE(int, dp, DP);
    
    bool isInvincible;  //���Ŵ����޵���
    
    bool wudi;
    
    CCArmature* shadow;
    
    CCSprite* shadow2;
    
    BloodBar* bloodbar;
    
    CCRect attackRect;    //�������Σ�
    
    float getHPPercent()
    {
         return 100*hp/maxHp;
    };
    
    float getNuqiPercent()
    {
         return 100*nuqi/maxNuqi;
    };
    
    CC_SYNTHESIZE(int, attackType, AttackType);
    CC_SYNTHESIZE(int, beAttackType, BeAttackType);
    
    int arpg_sPositionX;
    
    int nuqi;
    
    bool isqianqian;
    
    int maxNuqi;
    
    bool isScrolling;
    
    CC_SYNTHESIZE(int, nengliangdou, Nengliangdou);
    
    int maxNengliangdou;
    
    int buyNengliangdou;
    
    int bottomH;    //�±�Ե�ĸ߶�
    
    int topH;   //�ϱ�Ե�ĸ߶�
    
    bool isBeAttack;
    
    int id;

    int actionID;
    
    M_state m_state;
    
    bool has_hitARPG;
    
    bool hasBati;
    
public:
     void dropProp();
    
     void updateTopAndBottom(float dt);   //�������±�Ե
    
     void collison( CCBone * bone , const char * evt, int originFrameIndex, int currentFrameIndex);
    
     virtual void removeTo();
    
     virtual void removeCallback();
    
     void updateAttackRect(float dt);
    
     void stand();
    
     void flipDir();
    
     virtual void move();
    
     ARPG();
    
     CREATE_FUNC(ARPG);
    
     CCRect getBondingBox();
    
     CCRect getBondingBox2();
    
     CCRect getZuDangBox();
    
     CCRect getAttackBox();
    
     bool isFight(ARPG* p);
    
     void delHp(int hp);   //�����Ѫ�߼�
    
     virtual void die();
    
     void suffer(ARPG* attcker,int attackType);  //1�����ߣ�2��������
 
     virtual void doActionsByTag(CCObject* pSender);//����m_tag���Ŷ���
    
     virtual void setAction(int actID);
    
     virtual void setAction(int actionID,int times);
    
     virtual void actionCallback(CCArmature *pArmature, MovementEventType eventType, const char *animationID);
    
     void initAni(const char* rs);
    
     void update(float dt);
    
     virtual void beAttackCallFuncO(CCObject* pSender);
    
     virtual void beAttackCallFuncO1(CCObject* pSender);
    
     virtual void beAttackFlyCallFuncO(CCObject* pSender);
    
     virtual void doScrollByVertical(CCObject* pSender);//��Y��Ϊ������ת
    
     virtual void stopScrollByVertical(CCObject* pSender);//ֹͣ��Y����ת

     virtual void doUpdateScroll(float dt);//������ת����
    
     void attackJiangzhi();
    
     void resumeJiangzhi(CCObject* pSender);
    
     virtual void hitEffect();
    
     void attackEffect(CCPoint p);
    
     void skillEffect(CCPoint p,int index);
    
     void stopScrollByVertical2();
    
     bool hasScheduled;//�Ƿ��Ѿ�����ʱ�����
    
     CCPoint origiAnchor;//�����ê��
    
     int scheduleCount;//���ȼ���
    
     float origiScale;//�����scale����
    
     CCRect effectRect;
    
     CCRect bodyRect;

     CC_SYNTHESIZE(bool, isEffectAttack, IsEffectAttack);
    
     float wudiTime;
    
    
};

#endif /* defined(__King__ARPG__) */
