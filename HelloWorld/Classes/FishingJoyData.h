//-----------------------------------------------------------------------------
/**
	�ļ����ƣ�FishingJoyData.h
	��    �ߣ�MinJie
	�������ڣ�2013/9/9
*/
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
//	Include
//-----------------------------------------------------------------------------
#include "cocos2d.h"
//-----------------------------------------------------------------------------
//	Defines & Const Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//	Declaration
//-----------------------------------------------------------------------------
// CCDirector* sharedDirector = CCDirector::sharedDirector();
// CCTextureCache* sharedTextureCache = CCTextureCache::sharedTextureCache();

class CFishingJoyData : public cocos2d::CCObject
{
public:
	static CFishingJoyData* SharedFishingJoyData();
	void Purge();
protected:
	CFishingJoyData();
	~CFishingJoyData();
	bool Init();

private:
	void Reset() {}
	void Flush() {}
	void SetIsBeginner(bool IsBeginner) {}

private:
	bool m_IsBeginner;
	float m_fSoundVolume;
	float m_fMusicVolume;
	int m_nGold;
};
//-----------------------------------------------------------------------------
//	FishingJoyData.h
//-----------------------------------------------------------------------------


