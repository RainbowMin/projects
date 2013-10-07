//-----------------------------------------------------------------------------
/**
	文件名称：GameScene.cpp
	作    者：MinJie
	建立日期：2013/9/9
*/
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
//	Include
//-----------------------------------------------------------------------------
#include "GameScene.h"
#include "FishLayer.h"
#include "PanelLayer.h"
#include "MenuLayer.h"
#include "BackgroundLayer.h"
#include "CannonLayer.h"
#include "StaticData.h"
#include "FishingJoyData.h"
//-----------------------------------------------------------------------------
//	Defines & Const Variables
//-----------------------------------------------------------------------------
USING_NS_CC;
//-----------------------------------------------------------------------------
//	Implementation
//-----------------------------------------------------------------------------
CCScene* CGameScene::scene()
{
	CGameScene* pScene = new CGameScene();
	if (pScene && pScene->init())
	{
		pScene->autorelease();
		return pScene;
	}
	else
	{
		delete pScene;
		pScene = NULL;
		return NULL;
	}
}

//-----------------------------------------------------------------------------
bool CGameScene::init()
{
	preloadResources();

	if (!CCScene::init())
		return false;

	m_backgroundLayer = CBackgroundLayer::create();
	this->addChild(m_backgroundLayer);

	m_fishLayer = CFishLayer::create();
	this->addChild(m_fishLayer);

	m_cannonLayer = CCannonLayer::create();
	this->addChild(m_cannonLayer);

	m_panelLayer = CPanelLayer::create();
	this->addChild(m_panelLayer);

	//由于菜单界面只在暂停的时候才出现，所以我们并不直接将其添加进场景中，而是调用retain方法将其保留下来，方便日后访问。
	m_menuLayer = CMenuLayer::create();
	CC_SAFE_RETAIN(m_menuLayer);

	return true;
}

//-----------------------------------------------------------------------------
CGameScene::~CGameScene()
{
	//对应retain,这里调用Release，保证内存不会泄露
	CC_SAFE_RELEASE(m_menuLayer);
}


//-----------------------------------------------------------------------------
//todo 预载入资源，实现StartScene后将其删除
void CGameScene::preloadResources()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("fishingjoy_resource.plist");

	//以下代码创建了两个不同的动画帧序列，使用时获取动画可以这么做:CCAnimation* animation = CCAnimationCache::sharedAnimationCache()->animationByName(const char* name);
	int frameCount = STATIC_DATA_INT("fish_frame_count");
	for (int type = k_Fish_Type_Red; type < k_Fish_Type_Count; type++)
	{
		//以下代码会创建animation失败
// 		CCAnimation* fishAnimation = CCAnimation::create();
// 		for (int i = 0; i < frameCount; i++)
// 		{
// 			fishAnimation->addSpriteFrameWithFileName(
// 				CCString::createWithFormat(STATIC_DATA_STRING("fish_frame_name_format"), type, i)->getCString());
// 		}

		CCArray* spriteFramesArray = CCArray::createWithCapacity(frameCount);
		for (int i = 0; i < frameCount; i++)
		{
			CCString* fileName = CCString::createWithFormat(STATIC_DATA_STRING("fish_frame_name_format"), type, i);
			CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fileName->getCString());
			spriteFramesArray->addObject(spriteFrame);
		}
		CCAnimation* fishAnimation = CCAnimation::createWithSpriteFrames(spriteFramesArray);
		fishAnimation->setDelayPerUnit(STATIC_DATA_FLOAT("fish_frame_delay"));		
		CCString* animationName = CCString::createWithFormat(STATIC_DATA_STRING("fish_animation"),type);
		CCAnimationCache::sharedAnimationCache()->addAnimation(fishAnimation, animationName->getCString());
	}

	
}

//-----------------------------------------------------------------------------
//	GameScene.cpp
//-----------------------------------------------------------------------------