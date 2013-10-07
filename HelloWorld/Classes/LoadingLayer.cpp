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
// 	// 设置进度条的背景图片 我们把他放到屏幕下方的1/5处	
// 	CCSprite* pLoadingBgSprite = CCSprite::create("loading_bg.png");
// 	pLoadingBgSprite->setPosition(ccp(getWinSize().width/2+getWinOrigin().x, getWinSize().height/5 + getWinOrigin().y));
// 	this->addChild(pLoadingBgSprite, 1);
// 
// 	// 添加进度条  
// 	CCSprite* pLoadingSprite = CCSprite::create("loading.png");
// 	CCProgressTimer* pt = CCProgressTimer::create(pLoadingSprite);  
// 	pt->setType(CCProgressTimerType::kCCProgressTimerTypeBar);//设置成横向的 
// 	pt->setMidpoint(ccp(0,0));//可以看作是按矩形显示效果的进度条类型
// 	pt->setBarChangeRate(ccp(1,0));//用来设定进度条横向前进的方向从左向右或是从右向左  
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
		// 加载完的时候跳转到响应的界面
		CCLOG("loading over");
// 		CCScene *pScene = HelloWorld::scene();
// 		CCDirector::sharedDirector()->replaceScene(pScene);
	}
}