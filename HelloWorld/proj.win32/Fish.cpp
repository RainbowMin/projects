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
CFish* CFish::create(EFishType type)
{
	CFish* fish = new CFish();
	fish->init(type);
	fish->autorelease();
	return fish;
}

//-----------------------------------------------------------------------------
bool CFish::init(EFishType type)
{
	//CCAnimation只是用于存放动画，真正让动画播放起来的是动作类CCAnimate
	//CCAnimate只能由CCSprite及其子类播放

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