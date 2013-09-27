//-----------------------------------------------------------------------------
/**
	�ļ����ƣ�BackgroundLayer.cpp
	��    �ߣ�MinJie
	�������ڣ�2013/9/27
*/
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
//	Include
//-----------------------------------------------------------------------------
#include "BackgroundLayer.h"
#include "StaticData.h"
USING_NS_CC;
//-----------------------------------------------------------------------------
//	Defines & Const Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//	Implementation
//-----------------------------------------------------------------------------
bool CBackgroundLayer::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSprite* background = CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("background"));
	background->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.5));
	this->addChild(background);

	return true;
}

//-----------------------------------------------------------------------------
//	BackgroundLayer.cpp
//-----------------------------------------------------------------------------