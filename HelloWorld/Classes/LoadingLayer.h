#include "cocos2d.h"
using namespace cocos2d	;
class CLoadingLayer : public CCLayer
{
public:
	virtual bool init();
	CREATE_FUNC(CLoadingLayer);
	static cocos2d::CCScene* scene();
	void Load_Callback(CCObject* pObject);
	CLoadingLayer();

	CCSize getWinSize()
	{
		return	CCDirector::sharedDirector()->getVisibleSize();
	}

	CCPoint getWinOrigin()
	{
		return CCDirector::sharedDirector()->getVisibleOrigin();
	}
private:
	int m_LoadingNum;//用来记录当前的加载图片的数量
	int m_TotalNum;//一共要加载的图片数量
	//bool
};