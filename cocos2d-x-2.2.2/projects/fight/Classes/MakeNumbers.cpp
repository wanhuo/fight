//
//  MakeNumbers.cpp
//  xiyou
//
//  Created by mac on 14-3-16.
//
//

#include "MakeNumbers.h"
#include <string>
using namespace std;
/*
 �������Ҫ����ʾ����Զ���ͼƬ���͵��˺���ֵ��
 */
MakeNumbers::MakeNumbers(int attckmun)
{
	//������ֵת��Ϊ2�и�ʽ�ַ���string��CCString��
	char char_attckmun[100] = {0};
    sprintf(char_attckmun, "%d",attckmun);
    
	//�����Ҫ��;������Ϊ�ַ���int֮����໥ת��
	CCString* numberstr = CCString::create(char_attckmun);
	//���������ȡ�ַ�
	string str = numberstr->getCString();
	//��ȡ�����ز�ͼƬ��ͼƬ����Ϊ-0123456789��
	CCSprite* number_all = CCSprite::create("UI/shuzixiao.png");
	//��ȡ����ͼƬ����
	float allwight= number_all->getContentSize().width;
    float allhigth= number_all->getContentSize().height;
	//��ȡ����ͼƬ����
   	float onewight = allwight/10;
	float onehigth = allhigth;
	//��ȡ��һ�����ſ�Ѫ-��Ϊ����ͼƬ�ĵ�ͼ
	CCRect imgrect_moren = CCRect(0,0,onewight,onehigth);
	numbers = CCSprite::create();
    numbers->setContentSize(imgrect_moren.size);
    CCSprite* num = CCSprite::create("UI/shuzixiao.png",imgrect_moren);
	//ѭ����������-�����źź���ľ�����ֵ�˺�
	for (int i = 0; i < numberstr->length(); i++)
	{
		//���ν���ÿ����ֵ��С
		string nownumber =  str.substr(0+i,1);
		CCString* cc_nownumber = CCString::create(nownumber);
		//��������ֵȥѰ��ͼƬ
        CCRect imgrect_moren = CCRect(onewight*cc_nownumber->intValue(),0,onewight,onehigth);
        CCSprite* numbers_now = CCSprite::create("UI/shuzixiao.png",imgrect_moren);
		//���õ���ͼƬ����β׷�ڡ�-��ͼƬ�ú���
        numbers_now->setPosition(ccp( num->getContentSize().width*0.8*i ,num->getContentSize().height/2));
        numbers->addChild(numbers_now,2,10+i);
	}
    
}

MakeNumbers::MakeNumbers(int attckmun,const char* name)
{
    //������ֵת��Ϊ2�и�ʽ�ַ���string��CCString��
	char char_attckmun[100] = {0};
    sprintf(char_attckmun, "%d",attckmun);
    
	//�����Ҫ��;������Ϊ�ַ���int֮����໥ת��
	CCString* numberstr = CCString::create(char_attckmun);
	//���������ȡ�ַ�
	string str = numberstr->getCString();
	//��ȡ�����ز�ͼƬ��ͼƬ����Ϊ-0123456789��
	CCSprite* number_all = CCSprite::create(name);
	//��ȡ����ͼƬ����
	float allwight= number_all->getContentSize().width;
    float allhigth= number_all->getContentSize().height;
	//��ȡ����ͼƬ����
   	float onewight = allwight/10;
	float onehigth = allhigth;
	//��ȡ��һ�����ſ�Ѫ-��Ϊ����ͼƬ�ĵ�ͼ
	CCRect imgrect_moren = CCRect(0,0,onewight,onehigth);
	numbers = CCSprite::create();
    numbers->setContentSize(imgrect_moren.size);
    CCSprite* num = CCSprite::create(name,imgrect_moren);
	//ѭ����������-�����źź���ľ�����ֵ�˺�
	for (int i = 0; i < numberstr->length(); i++)
	{
		//���ν���ÿ����ֵ��С
		string nownumber =  str.substr(0+i,1);
		CCString* cc_nownumber = CCString::create(nownumber);
		//��������ֵȥѰ��ͼƬ
        CCRect imgrect_moren = CCRect(onewight*cc_nownumber->intValue(),0,onewight,onehigth);
        CCSprite* numbers_now = CCSprite::create(name,imgrect_moren);
		//���õ���ͼƬ����β׷�ڡ�-��ͼƬ�ú���
        numbers_now->setPosition(ccp( num->getContentSize().width*0.8*i ,num->getContentSize().height/2));
        numbers->addChild(numbers_now,2,10+i);
	}
}



MakeNumbers::~MakeNumbers(void)
{
}