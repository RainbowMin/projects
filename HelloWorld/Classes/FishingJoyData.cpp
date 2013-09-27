//-----------------------------------------------------------------------------
/**
	文件名称：FishingJoyData.cpp
	作    者：MinJie
	建立日期：2013/9/9
*/
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
//	Include
//-----------------------------------------------------------------------------
#include "FishingJoyData.h"
#include "StaticData.h"
//-----------------------------------------------------------------------------
//	Defines & Const Variables
//-----------------------------------------------------------------------------
static CFishingJoyData* _sharedFishingJoyData = NULL;
//-----------------------------------------------------------------------------
//	Implementation
//-----------------------------------------------------------------------------
CFishingJoyData* CFishingJoyData::SharedFishingJoyData()
{
	if (_sharedFishingJoyData == NULL)
	{
		_sharedFishingJoyData = new CFishingJoyData();
		_sharedFishingJoyData->Init();
	}
	return _sharedFishingJoyData;
}

//-----------------------------------------------------------------------------
CFishingJoyData::CFishingJoyData()
{

}

//-----------------------------------------------------------------------------
CFishingJoyData::~CFishingJoyData()
{

}

//-----------------------------------------------------------------------------
void CFishingJoyData::Purge()
{
	CC_SAFE_RELEASE_NULL(_sharedFishingJoyData);
}

//-----------------------------------------------------------------------------
bool CFishingJoyData::Init()
{
	m_IsBeginner = cocos2d::CCUserDefault::sharedUserDefault()->getBoolForKey("beginner",true);
	if (m_IsBeginner)
	{
		this->Reset();
		this->Flush();
		this->SetIsBeginner(true);
	}
	else
	{
		m_IsBeginner = cocos2d::CCUserDefault::sharedUserDefault()->getBoolForKey("beginner");
		m_fSoundVolume = cocos2d::CCUserDefault::sharedUserDefault()->getFloatForKey("sound");
		m_fMusicVolume = cocos2d::CCUserDefault::sharedUserDefault()->getFloatForKey("music");
		cocos2d::CCUserDefault::sharedUserDefault()->purgeSharedUserDefault();
	}

	return true;
}

//-----------------------------------------------------------------------------
void CFishingJoyData::Flush()
{
	cocos2d::CCUserDefault::sharedUserDefault()->setFloatForKey("sound", this->GetSoundVolume());
	cocos2d::CCUserDefault::sharedUserDefault()->setFloatForKey("beginner", this->GetIsBeginner());
	cocos2d::CCUserDefault::sharedUserDefault()->setFloatForKey("gold", this->GetGold());
	cocos2d::CCUserDefault::sharedUserDefault()->setFloatForKey("music", this->GetMusicVolume());
	cocos2d::CCUserDefault::sharedUserDefault()->flush();
	cocos2d::CCUserDefault::sharedUserDefault()->purgeSharedUserDefault();
	//每次对CCUserDefault进行操作后，都会调用purgeSharedUserDefault()将其删除，
	//这是因为FishingJoyData和CCUserDefault中都保存着游戏的数据，
	//因此，只在与外部文件交互时，我们才打开CCUserDefault,保存数据，然后删除CCUserDefault，以避免重复占用游戏数据，而度内存造成浪费
	//还有,别忘了在程序进入后台时调用flush方法，及时保存游戏数据
}

//-----------------------------------------------------------------------------
//	FishingJoyData.cpp
//-----------------------------------------------------------------------------
