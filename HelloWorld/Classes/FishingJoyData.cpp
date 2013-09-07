#include "FishingJoyData.h"

static CFishingJoyData* _sharedFishingJoyData = NULL;
CFishingJoyData* CFishingJoyData::sharedFishingJoyData()
{
	if (_sharedFishingJoyData == NULL)
	{
		_sharedFishingJoyData = new CFishingJoyData();
		_sharedFishingJoyData->init();
	}
	return _sharedFishingJoyData;
}

CFishingJoyData::CFishingJoyData()
{

}

CFishingJoyData::~CFishingJoyData()
{

}

void CFishingJoyData::purge()
{
	CC_SAFE_RELEASE_NULL(_sharedFishingJoyData);
}

bool CFishingJoyData::init()
{
	return true;
}