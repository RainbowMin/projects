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

	m_menuLayer = CMenuLayer::create();
	CC_SAFE_RETAIN(m_menuLayer);

	return true;
}

//-----------------------------------------------------------------------------
CGameScene::~CGameScene()
{
	CC_SAFE_RELEASE(m_menuLayer);
}


//-----------------------------------------------------------------------------
//todo 预载入资源，实现StartScene后将其删除
void CGameScene::preloadResources()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("fishingjoy_resource.plist");
	
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("fishingjoy_resource.plist");
}

//-----------------------------------------------------------------------------
//	GameScene.cpp
//-----------------------------------------------------------------------------