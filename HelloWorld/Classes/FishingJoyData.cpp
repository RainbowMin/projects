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
//	FishingJoyData.cpp
//-----------------------------------------------------------------------------
