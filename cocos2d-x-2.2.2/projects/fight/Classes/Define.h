//
//  Define.h
//  King
//
//  Created by mac on 14-3-26.
//
//

#ifndef King_Define_h
#define King_Define_h

#ifndef SIZE
#define SIZE CCDirector::sharedDirector()->getWinSize()
#endif

#ifndef Role_Height
#define Role_Height SIZE.height/4
#endif


#include "Game.h"

#define random_range(low,high) ((arc4random()%(high-low+1))+low)

#ifndef DHERO_RIGHT
#define DHERO_RIGHT 1 // �����泯���� ��
#endif

#ifndef DHERO_LEFT
#define DHERO_LEFT -1 // �����泯���� ��
#endif

#ifndef dirOfani
#define dirOfani "res"
#endif

#ifndef Role
#define Role Game::instance()->getHero()
#endif

#ifndef ShopRole
#define ShopRole Game::instance()->getShopRole()
#endif


#ifndef gameLayer
#define gameLayer Game::instance()->getGameLayer()
#endif

#ifndef HUB
#define HUB Game::instance()->getHubLayer()
#endif

#ifndef MENU
#define MENU Game::instance()->getMenuLayer()
#endif

#ifndef SHOP
#define SHOP Game::instance()->getShopLayer()
#endif


#ifndef KingData
#define KingData GameData::sharedGameData()
#endif

static const float AttackFrame = 0.032f;

static int shengmingLevelMoney[10] =
{
    200, 240,250,300,400,340,340,340,340,340
};

static int gongjiLevelMoney[10] =
{
    200, 240,250,300,400,340,340,340,340,340
};
static int fangyuLevelMoney[10] =
{
    200, 240,250,300,400,340,340,340,340,340
};

static int nuqiLevelMoney[10] =
{
    200, 240,250,300,400,340,340,340,340,340
};

#ifndef NA_SLEEP_TIME
#define NA_SLEEP_TIME 80
#endif

#ifndef SAFE_TIME
#define SAFE_TIME 4
#endif
inline long millisecondNow()
{
    struct cc_timeval now;
    CCTime::gettimeofdayCocos2d(&now,NULL);
    return (now.tv_sec *1000 + now.tv_usec /1000);
}

enum
{
    WanderTag = 99,
    SeekRoleTag =100,
    JumpTag = 101
};

enum
{
    tituiEffectTag = 1001,
    zadiEffectTag = 1002,
    yanmuEffectTag = 1003,
    shandianEffectTag = 1004,
    shandianqiuEffectTag = 1004,
    qianxiaqianEffectTag = 1005,
    juqiEffectTag = 1006,
    blackTag = 100007,
    techTag = 100008,
    duobiEffectTag = 100009,
    readygoTagZorder = 999999999
};

static std::string juqingMapTitle[21] =
{
  "",
  "",
  "��",
  "���",
  "���",
  "���",
  "Ů���",
  "��",
  "�������",
  "��",
  "��",
  "а�����",
  "а�����",
  "��",
  "��",
  "��",
  "��",
  "��",
  "��",
  "��",
  "��",
};

static std::string juqingMapText[21] =
{
    "",
	"",
	" ���˷�ʱ����,����һ���ϰ�!ɱ���������һ�Ҫ��·��!",
	"�����׷���������Ҹ�������", 
	"��֯��Ϊ�ұ���ģ�����",
	" �ֵ����ϰ�!��ľ�Ȼ��׷�����",
	"��˧��! ���������������һ�����~!",
	"�������������С�軹���ң�",
	"û�뵽�����ߵ�������ǣ�Ҳ�͵���Ϊֹ�ˣ����վ�����������ˡ�",
	"���Ҳ�������?����ֱ�ӳ������ǰɣ�",
	"����˭?! ��������ô?! ",
	"����Щ��֪�������������",
	"��������������ʥ����֯��������ˡ��",
	"��������֮Ѫ�̳��ߣ�ȥ��������ǻ����Ұ�!",
	"�����һ�ж��վ��Ļ�, ���͸ɾ���ô?",
	"�ҵ�������ʱ����ȫ�ͷ��ˡ�",
	"�㻹û�б��ɵ���?",
	"����������ܲ�? ��ſ�ô? ������!",
	"�ް�,�а�,Ȼ�������! ����Ϊֹ��!",
	"��������������˭Ҳ�޷��赲��",
	"���ǳɹ���Ϊ���Լ��ں��˷�Ĺ��������������һ�С�"
};

static std::string loadingTips[] =
{
    "С��ʾ: ����̫ǿ�򲻹����������ǿ�����ԡ�",
    "С��ʾ: ŭ�������ÿ�ȥ�̵깺��ŭ�����ɡ�",
    "С��ʾ: ���ʹ�ñ�ɱ��ŰɱBOSS�ɡ�",
    "С��ʾ: ��֪��ô�����̵���Թ���������ǿ�����ؼ��ܡ�",
    "С��ʾ: �����������һ��Ҫ���ջ��ᣬ�´ξͲ��������ˡ�"
};


#endif
