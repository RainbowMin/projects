//-----------------------------------------------------------------------------
/**
	�ļ����ƣ�StaticData.h
	��    �ߣ�MinJie
	�������ڣ�2013/9/7
*/
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
//	Include
//-----------------------------------------------------------------------------
#include "cocos2d.h"
#include <string>
//-----------------------------------------------------------------------------
//	Defines & Const Variables
//-----------------------------------------------------------------------------
#define STATIC_DATA_STRING(key)		CStaticData::SharedStaticData()->StringFromKey(key)
#define STATIC_DATA_INT(key)				CStaticData::SharedStaticData()->IntFromKey(key)
#define STATIC_DATA_FLOAT(key)		CStaticData::SharedStaticData()->FloatFromKey(key)
#define STATIC_DATA_BOOL(key)			CStaticData::SharedStaticData()->BooleanFromKey(key)
#define STATIC_DATA_POINT(key)		CStaticData::SharedStaticData()->PointFromKey(key)
#define STATIC_DATA_RECT(key)			CStaticData::SharedStaticData()->RectFromKey(key)
#define STATIC_DATA_SIZE(key)			CStaticData::SharedStaticData()->SizeFromKey(key)
//-----------------------------------------------------------------------------
//	Declaration
//-----------------------------------------------------------------------------
class CStaticData : public cocos2d::CCObject
{
public:
	//ͳһʹ��shared*�ӿڷ���Ψһ��ʵ�������ڸýӿ���ʹ���ӳٳ�ʼ��������Ҫʱ�Ŵ���ʵ��
	static CStaticData* SharedStaticData();
	
	//�ڱ�Ҫʱ���ã���������Ҫ���ڴ�
	void Purge();
protected:
	CStaticData();
	~CStaticData();
	bool Init();

public:
	const char*			StringFromKey(std::string key);
	int						IntFromKey(std::string key);
	float						FloatFromKey(std::string key);
	bool						BooleanFromKey(std::string key);
	cocos2d::CCPoint  PointFromKey(std::string key);
	cocos2d::CCRect   RectFromKey(std::string key);
	cocos2d::CCSize	SizeFromKey(std::string key);

private:
	cocos2d::CCDictionary* m_Dictionary;
};
//-----------------------------------------------------------------------------
//	StaticData.h
//-----------------------------------------------------------------------------