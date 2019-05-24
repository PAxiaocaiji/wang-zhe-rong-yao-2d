#pragma once
#include<cocos2d.h>
#include<extensions/cocos-ext.h>

USING_NS_CC;
USING_NS_CC_EXT;

class HomeLayer :public Layer
{
public:

	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HomeLayer);

private:

	Size vsable = Size(960,540);

};