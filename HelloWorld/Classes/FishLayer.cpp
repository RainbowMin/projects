//-----------------------------------------------------------------------------
/**
	�ļ����ƣ�FishLayer.cpp
	��    �ߣ�MinJie
	�������ڣ�2013/9/27
*/
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
//	Include
//-----------------------------------------------------------------------------
#include "FishLayer.h"
#include "Fish.h"
//-----------------------------------------------------------------------------
//	Defines & Const Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//	Implementation
//-----------------------------------------------------------------------------
/*
������Ϸ�д������ֵ����壬�����ӵ���һ��ʱ������ɵĹ���ȣ�ͨ��������Ϸ��ʼ֮ǰԤ�Ⱦ�����һ���ֲ��������ڴ��У�
����Ҫ�õ�������ʱ�ٽ�����ӵ������У��Ӷ���������Ϸ�����д��������ڴ�ռ���������ɲ������ĸо���
�����FinshLayer�У���������CCArray* fishArray�洢Ԥ�����ɵ��㣬
��ͨ��schedule��ʱ����ÿ��һ��ʱ�����һ��addFish��������δ���볡��������ӽ�ȥ��
*/
bool CFishLayer::init()
{
	if (!CCLayer::init())
		return false;

	int capacity = 50;
	m_FishArray = CCArray::createWithCapacity(capacity);
	CC_SAFE_RETAIN(m_FishArray);

	for (int i = 0; i < capacity; i++)
	{
		int type = CCRANDOM_0_1() * 2;
		CFish* fish = CFish::create((EFishType)type);
		m_FishArray->addObject(fish);
	}
	this->schedule(schedule_selector(CFishLayer::AddFish), 3.0);

	return true;
}

void CFishLayer::AddFish(float dt)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	int CountToAdd = CCRANDOM_0_1()*10 + 1;
	int CountHasAdded = 0;

	CCObject* iterator;
	CCARRAY_FOREACH(m_FishArray, iterator)
	{
		CFish* fish = (CFish*)iterator;
		if (fish->isRunning() == false)
		{
			this->addChild(fish);
			//todo����Ӧ����fish�������������
			int randomX = CCRANDOM_0_1() * winSize.width;
			int randomY = CCRANDOM_0_1() * winSize.height;
			fish->setPosition(CCPointMake(randomX, randomY));
			CountHasAdded++;
			if (CountToAdd == CountHasAdded)
				break;
		}
	}
}
//-----------------------------------------------------------------------------
//	FishLayer.cpp
//-----------------------------------------------------------------------------