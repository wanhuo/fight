//
//  SelectScene.h
//  King
//
//  Created by mac on 14-3-26.
//
//

#ifndef __King__SelectScene__
#define __King__SelectScene__

#include "BaseLayer.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;
using namespace gui;

using namespace std;

const string title[21] =
{
"1-1.�����1",
"1-1.�����1",
"1-2.�����2",
"1-3.�����3",
"1-4.�����4",
"2-1.��������1",
"2-2.��������2",
"2-3.��������3",
"2-4.��������4",
"3-1.�����1",
"3-2.�����2",
"3-3.�����3",
"3-4.�����4",
"4-1.�����ִ��1",
"4-2.�����ִ��2",
"4-3.�����ִ��3",
"4-4.�����ִ��4",
"5-1.�Ѫ��ͷ1",
"5-2.�Ѫ��ͷ2",
"5-3.�Ѫ��ͷ3",
"5-4.�Ѫ��ͷ4"
};

const string descr[21] =
{
"��һ�ν�����Ϸ",
"����һƬ�����޷������ĵط���ֻ��һ�������ܾõ����֡�����֡�",
"������������һ������Σ�յĵط������Ǿȳ�С������Ψһ��Ŀ��",
"�����޾��ĵ��ˣ��ѵ����Ѿ�������һ���޴����ı֮��?",
"���š��๷��,���Ƕ���ֵ�Ļ�����ô��",
"�����ԭ��ֻ��һ����ڣ��ⱳ���Ȼ��������˾޴�Ķ��С�",
"���Ʋ����ķ��������������Ÿ��ַ�����ӣ���Ȼ��˾ͳͼ����ɡ�",
"��Щ�˶�������֮ͽ�����С�ģ���С�ģ�",
"���ڰ��β�ס��? �ֲ��������!",
"�ֲ�����˵С�豻ץ��������������ã�",
"�������ںڰ��е�����������ΰ��Ϊʲô�����ֵط���������á�",
"�����㷢����ʲô��һ��а����֯��",
"а�����, ���๷����֯����һ����",
"����䶼�о�Ȼ���������ĵ����棬�����ִ���������ǵ��ϳ�",
"����! ��˵�еĹ�����!��ȥ���ɣ�",
"���Ѱɣ��ҵ��ռ�����",
"��������?! ������а�����?",
"���վ�ս֮��! �Ѫ��ͷ!",
"��ƴ! ���µ�����֮Ѫ!",
"�����ڷ��һ�ΰ�",
"��Ȼ���˺�������ˣ�������������������"
};

const string moshiStr[21] =
{
    "",
	"ɱ������10������",
	"ɱ������15������",
	"��ʱһ���ӣ�����ɱ��15����",
	"ɱ��BOSS�����",
    "ɱ������30������",
    "��ʱһ���ӣ�����ɱ��20����",
    "��ǰ����600�׹���",
    "ɱ��BOSS�����",
    "��ǰ����800�׹���",
    "���2���ӹ���",
    "ɱ������40������",
    "ɱ��BOSS�����",
    "ɱ������45������",
    "���2���ӹ���",
    "��ǰ����1200�׹���",
    "ɱ��BOSS�����",
    "ɱ������60������",
    "��ǰ����1500�׹���",
    "���3���ӹ���",
    "ɱ��BOSS�����"
};

const int moshiID[21] =
{
    0,  0,0,1,  0,     2,1,  3,0,     3 ,4,0,0,     0,4,3,  0,     0,3,  4,0
};



class SelectScene : public BaseLayer
{
public:
    
    SelectScene();
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(SelectScene);
    
    void Back(CCObject* pSender);
    
    CCArray* selectGuan;

    static int xuanguan;
    
    bool jiesuo[15];
    
    void clickButtonCallback(CCObject* pSender,TouchEventType type);
    
    void shopButtonCallback(CCObject* pSender,TouchEventType type);
    
    void shopButtonCallback(CCObject* pSender);
    
    void start_game(CCObject* pSender, TouchEventType type);
    
    void onExit();
    
    void addTips();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
    
    void ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
    
    virtual void ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
    
    void registerWithTouchDispatcher();
    
    void backScene(CCObject* pSender);
    
    void fudong(CCObject* pSender);
    
    void fudong1(CCObject* pSender);
    
    void onlineLibaoMenu(CCObject* pSender);
    
    CCSprite* selectS;
    
    int current_Select;
    
    void onEnter();
    
    UILabel* font1;
    
    UILabel* font2;
    
    UILayer* ul;
    
    CCSprite* aniSprite;
    
    bool canClick;
    
    int biaozhi;
    
    CCSprite* sprite;
    
    bool drag;
    
    CCPoint beginP;
    
    CCPoint endP;
    
    CCMenu* menu;
    
    CCMenuItem* back;
    
    CCMenuItem* jiantou1;
    
    CCMenuItem* jiantou2;
    
    ImageView* new2;
    
    UIButton* curr_button ;
    
    void addTip(std::string text);
    
    void addTip2(std::string text);
    
    void resetTip();
    
    CCSprite* tip1;
    
    CCSprite* jiaoshi;
    
    UILabel* label;
    
};
#endif /* defined(__King__SelectScene__) */
