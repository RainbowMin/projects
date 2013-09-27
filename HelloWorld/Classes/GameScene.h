//-----------------------------------------------------------------------------
/**
	文件名称：GameScene.h
	作    者：MinJie
	建立日期：2013/9/9
*/
//-----------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------
//	Include
//-----------------------------------------------------------------------------
#include "cocos2d.h"
//-----------------------------------------------------------------------------
//	Defines & Const Variables
//-----------------------------------------------------------------------------
class CBackgroundLayer;
class CCannonLayer;
class CFishLayer;
class CPanelLayer;
class CMenuLayer;
//-----------------------------------------------------------------------------
//	Declaration
//-----------------------------------------------------------------------------
class CGameScene : public cocos2d::CCScene
{
public:
	//CREATE_FUNC(CGameScene);
	static cocos2d::CCScene* scene();
	bool init();
	~CGameScene();

	//菜单页面相关的函数
	void pause();
	void resume();
	void sound();
	void music();
	void reset();
	void transToMainMenu();

private:
	//todo 预载入资源，实现StartScene后将其删除
	void preloadResources();

protected:
	CBackgroundLayer*	m_backgroundLayer;
	CCannonLayer*			m_cannonLayer;
	CFishLayer*				m_fishLayer;
	CPanelLayer*			m_panelLayer;
	CMenuLayer*			m_menuLayer;
};
//-----------------------------------------------------------------------------
//	GameScene.h
//-----------------------------------------------------------------------------