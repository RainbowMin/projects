//-----------------------------------------------------------------------------
/**
	文件名称：StaticData.h
	作    者：MinJie
	建立日期：2013/9/7
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
	//统一使用shared*接口访问唯一的实例，并在该接口中使用延迟初始化，在需要时才创建实例
	static CStaticData* SharedStaticData();
	
	//在必要时调用，以清理不必要的内存
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