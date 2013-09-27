//-----------------------------------------------------------------------------
/**
	�ļ����ƣ�FishingJoyData.cpp
	��    �ߣ�MinJie
	�������ڣ�2013/9/9
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
	//ÿ�ζ�CCUserDefault���в����󣬶������purgeSharedUserDefault()����ɾ����
	//������ΪFishingJoyData��CCUserDefault�ж���������Ϸ�����ݣ�
	//��ˣ�ֻ�����ⲿ�ļ�����ʱ�����ǲŴ�CCUserDefault,�������ݣ�Ȼ��ɾ��CCUserDefault���Ա����ظ�ռ����Ϸ���ݣ������ڴ�����˷�
	//����,�������ڳ�������̨ʱ����flush��������ʱ������Ϸ����
}

//-----------------------------------------------------------------------------
//	FishingJoyData.cpp
//-----------------------------------------------------------------------------
