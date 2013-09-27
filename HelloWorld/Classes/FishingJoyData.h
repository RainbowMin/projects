//-----------------------------------------------------------------------------
/**
	文件名称：FishingJoyData.h
	作    者：MinJie
	建立日期：2013/9/9
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
	void Purge();//在必要时调用，以清理不必要的内存
protected:
	CFishingJoyData();
	~CFishingJoyData();
	bool Init();

private:
	void Reset() {}
	void Flush();//用于将数据存储到外部资源去
	void SetIsBeginner(bool IsBeginner) {m_IsBeginner = IsBeginner;}
	bool GetIsBeginner() {return m_IsBeginner;}
	float GetSoundVolume() {return m_fSoundVolume;}
	float GetMusicVolume() {return m_fMusicVolume;}
	int GetGold() {return m_nGold;}

private:
	bool m_IsBeginner;
	float m_fSoundVolume;
	float m_fMusicVolume;
	int m_nGold;
};
//-----------------------------------------------------------------------------
//	FishingJoyData.h
//-----------------------------------------------------------------------------


