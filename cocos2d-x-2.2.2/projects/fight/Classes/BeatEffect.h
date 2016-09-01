//
//  BeatEffect.h
//  King
//
//  Created by mac on 14-3-29.
//
//

#ifndef __King__BeatEffect__
#define __King__BeatEffect__

#include "cocos2d.h"
#include <stdio.h>
USING_NS_CC;
using namespace std;

#define REDUCESPEEDSPACE 5 //���ٵ�
#define BOUNCEHIGHT 10 //�����ص��߶�
#define MINFRAMESPACE 0.08f //��С�Ĳ���֡���
#define MINFLOAT 0.00001 //���Ե�0�������С����ֵ
enum
{
    kAttack_None,
    kAttack_beHitBack,//����
    kAttack_beHitFloat, //����
    kAttack_beHitDaoDiChuo, //���ش�
    kAttack_beHitFloatScrollDown, //������ת����
    kAttack_beHitDown, //������
    kAttack_beHitScrollDown, //������
    kAttack_beHitSkyDown, //������
    kAttack_beHitForceHit //�Ʒ�����
};//�ܻ�����

enum{
    kAnimation_tag_Jump,
};//������tag

class BeatEffect:public CCNode
{
    CCNode* m_delegate;
    
    float m_beAttackDelay;//�ܻ���ֱʱ��
    
    int m_intGroundH;//�ܻ������ֵ
    
    int m_addedGroundH;//��ǰ���ֵ���ڱ䶯
    
    int m_attackType;//��ǰ���ܻ�����
    
    int m_distanceX;//�ܻ�ʱˮƽ���˾���
    
    CCPoint m_origiPos;//��ǰdelegate �����λ��
    
    CCPoint m_newNodePos;//m_delegate ��Node�����λ��
    
    float incrementY;//y���������
    
    float m_reduceSpeed;//����
    
public:
    int direction;//�ܻ�����
    
    BeatEffect();
    
    virtual ~BeatEffect();
    
    static BeatEffect* create(CCNode* delegate);
    
    static BeatEffect* create(CCNode* delegate,int attackID,int sufferDir);
    
    void executeAnimationAndAction(int attackID);
    
    void setAttackDirection(int dir)
    {
        this->direction = dir;
    };
    
    void doShakeLeftAndRight(CCObject* pSender);//������,@param ��ֱʱ��
    
    /*//�����ˣ�dis ���˾��룬backTime �������˹��̵ĸ�ʱ�䣬stdTimeSpa ������վ�� ��sufferdelay �𶯽�ֱʱ��*/
    void beHitBack(CCCallFuncO* callback,int dis,float backTime,float stdTimeSpa,int sufferDelay = 1,bool reduce = true);
    
    /*��������, groundH ���ֵ��dis ˮƽ��λ�ƣ�secDis ��ػص�ˮƽλ��, firTime ��һ�θ���ʱ�䣬secTime �ص�ʱ�䣬stdspace ������վ����
     redtime �ٶȼ����ٱ���sufferdelay �𶯽�ֱʱ��*/
    void beHitFloatSky(CCCallFuncO* callback,int groundH,int dis,int secDis,float firTime,float secTime,float stdSpace,float redTime,float sufferDelay = 1.0);
    
    /*//���������ش� groundH ���ֵ��dis ˮƽ��λ�ƣ�secDis ��ػص�ˮƽλ��, firTime ��һ�θ���ʱ�䣬secTime �ص�ʱ�䣬thtime �������ش���ʱ�䣬stdspace ������վ����
     redtime �ٶȼ����ٱ���sufferdelay �𶯽�ֱʱ��*/
    void beHitDwonAndMove(CCCallFuncO* callback,int groundH,int dis,int secDis,float firtime,float sectime,float thtime,float stdspace,float redtime,int sufferDelay = 1);
    
    /*//������ dis ˮƽ��λ�ƣ�firTime ��һ�θ���ʱ�䣬secTime �ص�ʱ�䣬stdspace ������վ����sufferdelay �𶯽�ֱʱ��*/
    void beHitScrollDwon(CCCallFuncO* callback,int dis,float firtime,float sectime,float stdtime,int sufferDelay = 1);
    
    /*//������ת groundH ���ֵ��dis ˮƽ��λ�ƣ�secDis ��ػص�ˮƽλ��, firTime ��һ�θ���ʱ�䣬secTime �ص�ʱ��,stdspace ������վ����
     redtime �ٶȼ����ٱ���sufferdelay �𶯽�ֱʱ��*/
    void beHitFloatScrollDwon(CCCallFuncO* callback,int groundH,int dis,int secdis,float firtime,float sectime,float stdspace,float redtime,int sufferDelay = 1);
    
    /*/������ dis ˮƽ��λ�ƣ�secDis ��ػص�ˮƽλ��, firTime ���򵽵��ϵ�ʱ�䣬secTime �ص�ʱ��,stdspace ������վ����sufferdelay �𶯽�ֱʱ��*/
    void beHitSkyHitDwon(CCCallFuncO* callback,int dis,int secdis,float firtime,float sectime,float stdspace,float sufferDelay = 1);
    
    void beHitDown(CCCallFuncO* callback,int sufferDelay = 1);//���� sufferDelay �ܻ���ֱʱ��
    
    /*//�Ʒ����� groundH ���ֵ��dis ˮƽ��λ�ƣ�secDis ��ػص�ˮƽλ��, firTime ��һ�θ���ʱ�䣬secTime �ص�ʱ��,stdspace ������վ����sufferdelay �𶯽�ֱʱ��*/
    void beHitPowerful(CCCallFuncO* callback,int groundH,int dis,int secdis,float firtime,float sectime,float stdspace,int sufferDelay = 10);
    
    void updateAnimation(float dt);//���µ�ǰ���ŵĶ���
    
    void cleanMemenbers();//�����Ա����
    
    void beFallDown();
};
#endif /* defined(__King__BeatEffect__) */
