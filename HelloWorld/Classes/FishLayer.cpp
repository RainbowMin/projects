//-----------------------------------------------------------------------------
/**
	文件名称：FishLayer.cpp
	作    者：MinJie
	建立日期：2013/9/27
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
对于游戏中大量出现的物体，例如子弹、一定时间后生成的怪物等，通常会在游戏开始之前预先就生成一部分并保留在内存中，
在需要用到该物体时再将其添加到场景中，从而避免在游戏过程中大量申请内存空间而给玩家造成不流畅的感觉。
因此在FinshLayer中，我们先用CCArray* fishArray存储预先生成的鱼，
并通过schedule计时器，每隔一段时间调用一次addFish方法，将未载入场景的鱼添加进去。
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
			//todo后期应重设fish产生的随机坐标
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