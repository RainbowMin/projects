//-----------------------------------------------------------------------------
/**
	文件名称：StaticData.cpp
	作    者：MinJie
	建立日期：2013/9/7
*/
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
//	Include
//-----------------------------------------------------------------------------
#include "StaticData.h"
//-----------------------------------------------------------------------------
//	Defines & Const Variables
//-----------------------------------------------------------------------------
static CStaticData* _sharedStaticData = NULL;
#define STATIC_DATA_PATH "static_data.plist"
//-----------------------------------------------------------------------------
//	Implementation
//-----------------------------------------------------------------------------
CStaticData* CStaticData::SharedStaticData()
{
	if (_sharedStaticData == NULL)
	{
		_sharedStaticData = new CStaticData();
		_sharedStaticData->Init();
	}
	return _sharedStaticData;
}

//-----------------------------------------------------------------------------
CStaticData::CStaticData()
{
	_staticDataPath = STATIC_DATA_PATH;
}

//-----------------------------------------------------------------------------
CStaticData::~CStaticData()
{
	CC_SAFE_RELEASE_NULL(m_Dictionary);
}

//-----------------------------------------------------------------------------
void CStaticData::Purge()
{
	CC_SAFE_RELEASE_NULL(_sharedStaticData);
}

//-----------------------------------------------------------------------------
bool CStaticData::Init()
{
	m_Dictionary = cocos2d::CCDictionary::createWithContentsOfFile(_staticDataPath.c_str());
	CC_SAFE_RETAIN(m_Dictionary);
	return true;
}

//-----------------------------------------------------------------------------
const char* CStaticData::StringFromKey(std::string key)
{
	return m_Dictionary->valueForKey(key)->getCString();
}

//-----------------------------------------------------------------------------
int CStaticData::IntFromKey(std::string key)
{
	return m_Dictionary->valueForKey(key)->intValue();
}

//-----------------------------------------------------------------------------
float CStaticData::FloatFromKey(std::string key)
{
	return m_Dictionary->valueForKey(key)->floatValue();
}

//-----------------------------------------------------------------------------
bool	CStaticData::BooleanFromKey(std::string key)
{
	return m_Dictionary->valueForKey(key)->boolValue();
}

//-----------------------------------------------------------------------------
cocos2d::CCPoint CStaticData::PointFromKey(std::string key)
{
	return cocos2d::CCPointFromString(m_Dictionary->valueForKey(key)->getCString());
}

//-----------------------------------------------------------------------------
cocos2d::CCRect CStaticData::RectFromKey(std::string key)
{
	return cocos2d::CCRectFromString(m_Dictionary->valueForKey(key)->getCString());
}

//-----------------------------------------------------------------------------
cocos2d::CCSize CStaticData::SizeFromKey(std::string key)
{
	return cocos2d::CCSizeFromString(m_Dictionary->valueForKey(key)->getCString());
}

//-----------------------------------------------------------------------------
//	StaticData.cpp
//-----------------------------------------------------------------------------