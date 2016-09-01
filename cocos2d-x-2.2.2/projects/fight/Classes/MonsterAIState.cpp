//
//  MonsterAIState.cpp
//  XiYouJi
//
//  Created by mac on 14-3-23.
//
//

#include "MonsterAIState.h"
#include "Monster.h"

//------------------------------------------------------------------------
//    �����ʼ��״̬
//------------------------------------------------------------------------
static MonsterInitState* Instance();

MonsterInitState* MonsterInitState::Instance()
{
    static MonsterInitState instance;
    
    return &instance;
}
void MonsterInitState::Enter(Monster* monster)
{
     //�����ʼ��  ����ʼ������
    
}

void MonsterInitState::Execute(Monster* monster)
{
    if (monster->isToWander())
    {
        monster->move();
    }
    
    if (monster->inAIRange())
    {
        monster->GetFSM()->ChangeState(MonsterApproachState::Instance());
    }
}

void MonsterInitState::Exit(Monster* monster)
{
    
}
//------------------------------------------------------------------------
//    ���Ｄ��״̬ ֻ����һ�Ρ� ��enter�����г�ʼ������  Execute�����н���״̬8
//------------------------------------------------------------------------

MonsterActiveState* MonsterActiveState::Instance()
{
    static MonsterActiveState instance;
    
    return &instance;
}
void MonsterActiveState::Enter(Monster* monster)
{
    
 
}

void MonsterActiveState::Execute(Monster* monster)
{

}

void MonsterActiveState::Exit(Monster* monster)
{
    
}
//------------------------------------------------------------------------
//  ���ƶ�״̬
//------------------------------------------------------------------------
MonsterMoveState* MonsterMoveState::Instance()
{
    static MonsterMoveState instance;
    
    return &instance;
}
void MonsterMoveState::Enter(Monster* monster)
{

}

void MonsterMoveState::Execute(Monster* monster)
{
    monster->wander();
}

void MonsterMoveState::Exit(Monster* monster)
{
   // monster->stopAllActions();
}
//------------------------------------------------------------------------
//  �ֿ�������״̬
//------------------------------------------------------------------------
MonsterApproachState* MonsterApproachState::Instance()
{
    static MonsterApproachState instance;
    
    return &instance;
}
void MonsterApproachState::Enter(Monster* monster)
{
   
    if (monster->actionID >=5 ) {
        
    }else
    {
        monster->stand();
    }
}

void MonsterApproachState::Execute(Monster* monster)
{
    
    monster->wander();
//    if (monster->canAttack())
//    {
//        monster->attack();
//    }
    if (monster->isUnderAttack) {
        monster->GetFSM()->ChangeState(MonsterBeAttackState::Instance());
    }
}

void MonsterApproachState::Exit(Monster* monster)
{
    
}
//------------------------------------------------------------------------
//  ���ܵ�����״̬
//------------------------------------------------------------------------
MonsterAttackState* MonsterAttackState::Instance()
{
    static MonsterAttackState instance;
    return &instance;
}

void MonsterAttackState::Enter(Monster* monster)
{
     monster->attack();
}

void MonsterAttackState::Execute(Monster* monster)
{
    if(!monster->canAttack())
    {
        monster->GetFSM()->ChangeState(MonsterApproachState::Instance());
    }
    
     monster->attack();
}

void MonsterAttackState::Exit(Monster* monster)
{
    
}

//------------------------------------------------------------------------
//  ���ܵ�����״̬
//------------------------------------------------------------------------
MonsterBeAttackState* MonsterBeAttackState::Instance()
{
    static MonsterBeAttackState instance;
    return &instance;
}
void MonsterBeAttackState::Enter(Monster* monster)
{

}
void MonsterBeAttackState::Execute(Monster* monster)
{
    if (monster->isDie)
    {
        monster->GetFSM()->ChangeState(MonsterDeadState::Instance());
    }
}

void MonsterBeAttackState::Exit(Monster* monster)
{
    
}

//------------------------------------------------------------------------
//  ������״̬
//------------------------------------------------------------------------
MonsterDeadState* MonsterDeadState::Instance()
{
    static MonsterDeadState instance;
    return &instance;
}
void MonsterDeadState::Enter(Monster* monster)
{

}

void MonsterDeadState::Execute(Monster* monster)
{

}

MonserFallUpState* MonserFallUpState::Instance()
{
    static MonserFallUpState instance;
    return &instance;
}

void MonserFallUpState::Enter(Monster* monster)
{
    monster->getUp();
}

void MonserFallUpState::Execute(Monster* monster)
{
    if (monster->isDie) {
        monster->GetFSM()->ChangeState(MonsterDeadState::Instance());
    }
}

void MonserFallUpState::Exit(Monster* monster)
{
    
}
