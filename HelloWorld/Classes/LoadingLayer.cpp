#include "LoadingLayer.h"
#include "HelloWorldScene.h"

CLoadingLayer::CLoadingLayer()
{
	m_LoadingNum=0;
	m_TotalNum = 100;
}

bool CLoadingLayer::init()
{
	CCLayer::init();
// 	// ���ý������ı���ͼƬ ���ǰ����ŵ���Ļ�·���1/5��	
// 	CCSprite* pLoadingBgSprite = CCSprite::create("loading_bg.png");
// 	pLoadingBgSprite->setPosition(ccp(getWinSize().width/2+getWinOrigin().x, getWinSize().height/5 + getWinOrigin().y));
// 	this->addChild(pLoadingBgSprite, 1);
// 
// 	// ��ӽ�����  
// 	CCSprite* pLoadingSprite = CCSprite::create("loading.png");
// 	CCProgressTimer* pt = CCProgressTimer::create(pLoadingSprite);  
// 	pt->setType(CCProgressTimerType::kCCProgressTimerTypeBar);//���óɺ���� 
// 	pt->setMidpoint(ccp(0,0));//���Կ����ǰ�������ʾЧ���Ľ���������
// 	pt->setBarChangeRate(ccp(1,0));//�����趨����������ǰ���ķ���������һ��Ǵ�������  
// 	float PosX= getWinSize().width/2 + getWinOrigin().x;
// 	float PosY = getWinSize().height/5 + getWinOrigin().y-5;
// 	pt->setPercentage(0);
// 	pt->setPosition(PosX,PosY);
// 	this->addChild(pt, 2, 1);
// 
// 	CCTextureCache::sharedTextureCache()->addImageAsync("loading.png", this, callfuncO_selector(CLoadingLayer::Load_Callback));

	return true;
}

CCScene* CLoadingLayer::scene()
{
	CCScene* scene = CCScene::create();
	CLoadingLayer* layer = CLoadingLayer::create();
	scene->addChild(layer);
	return scene;
}

void CLoadingLayer::Load_Callback(CCObject* pObject)
{
	CCLOG("Load_Callback");
	m_LoadingNum++;
	CCProgressTimer* pt = (CCProgressTimer*)this->getChildByTag(1);
	float CurPercent = pt->getPercentage();
	pt->setPercentage(100 / m_TotalNum + CurPercent);
	if (m_LoadingNum < m_TotalNum)
	{
	}
	else
	{
		// �������ʱ����ת����Ӧ�Ľ���
		CCLOG("loading over");
// 		CCScene *pScene = HelloWorld::scene();
// 		CCDirector::sharedDirector()->replaceScene(pScene);
	}
}