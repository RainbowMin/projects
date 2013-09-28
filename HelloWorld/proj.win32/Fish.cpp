//-----------------------------------------------------------------------------
/**
	文件名称：Fish.cpp
	作    者：MinJie
	建立日期：2013/9/28
*/
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
//	Include
//-----------------------------------------------------------------------------
#include "Fish.h"
#include "StaticData.h"
//-----------------------------------------------------------------------------
//	Defines & Const Variables
//-----------------------------------------------------------------------------
USING_NS_CC;
enum
{
	k_Action_Animate = 0,
};
//-----------------------------------------------------------------------------
//	Implementation
//-----------------------------------------------------------------------------
CFish* CFish::create(FishType type)
{
	CFish* fish = new CFish();
	fish->init(type);
	fish->autorelease();
	return fish;
}

//-----------------------------------------------------------------------------
bool CFish::init(FishType type)
{
	m_type = type;
	CCString* animationName = CCString::createWithFormat(STATIC_DATA_STRING("fish_animation"), m_type);
	CCAnimation* fishAnimation = CCAnimationCache::sharedAnimationCache()->animationByName(animationName->getCString());
	CCAnimate* fishAnimate = CCAnimate::create(fishAnimation);
	fishAnimate->setTag(k_Action_Animate);
	m_fishSprite = CCSprite::create();
	this->addChild(m_fishSprite);
	m_fishSprite->runAction(CCRepeatForever::create(fishAnimate));
	return true;
}

//-----------------------------------------------------------------------------
//	Fish.cpp
//-----------------------------------------------------------------------------