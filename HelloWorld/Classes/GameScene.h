//-----------------------------------------------------------------------------
/**
	�ļ����ƣ�GameScene.h
	��    �ߣ�MinJie
	�������ڣ�2013/9/9
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

	//�˵�ҳ����صĺ���
	void pause();
	void resume();
	void sound();
	void music();
	void reset();
	void transToMainMenu();

private:
	//todo Ԥ������Դ��ʵ��StartScene����ɾ��
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