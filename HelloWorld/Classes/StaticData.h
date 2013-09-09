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
	float						FloatFrom(std::string key);
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