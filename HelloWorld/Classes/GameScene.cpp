//-----------------------------------------------------------------------------
/**
	�ļ����ƣ�GameScene.cpp
	��    �ߣ�MinJie
	�������ڣ�2013/9/9
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

	//���ڲ˵�����ֻ����ͣ��ʱ��ų��֣��������ǲ���ֱ�ӽ�����ӽ������У����ǵ���retain�������䱣�������������պ���ʡ�
	m_menuLayer = CMenuLayer::create();
	CC_SAFE_RETAIN(m_menuLayer);

	return true;
}

//-----------------------------------------------------------------------------
CGameScene::~CGameScene()
{
	//��Ӧretain,�������Release����֤�ڴ治��й¶
	CC_SAFE_RELEASE(m_menuLayer);
}


//-----------------------------------------------------------------------------
//todo Ԥ������Դ��ʵ��StartScene����ɾ��
void CGameScene::preloadResources()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("fishingjoy_resource.plist");

	//���´��봴����������ͬ�Ķ���֡���У�ʹ��ʱ��ȡ����������ô��:CCAnimation* animation = CCAnimationCache::sharedAnimationCache()->animationByName(const char* name);
	int frameCount = STATIC_DATA_INT("fish_frame_count");
	for (int type = k_Fish_Type_Red; type < k_Fish_Type_Count; type++)
	{
		//���´���ᴴ��animationʧ��
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