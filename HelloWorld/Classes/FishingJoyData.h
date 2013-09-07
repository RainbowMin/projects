#include "cocos2d.h"

// CCDirector* sharedDirector = CCDirector::sharedDirector();
// CCTextureCache* sharedTextureCache = CCTextureCache::sharedTextureCache();

class CFishingJoyData : public cocos2d::CCObject
{
public:
	static CFishingJoyData* sharedFishingJoyData();
	void purge();
protected:
	CFishingJoyData();
	~CFishingJoyData();
	bool init();
};