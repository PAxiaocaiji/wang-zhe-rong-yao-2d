#pragma once
#include<cocos2d.h>
#include<SimpleAudioEngine.h>
#include"ChoosingScene.h"

USING_NS_CC;

using namespace CocosDenshion;

class HomeLayer :public Layer
{
public:

	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HomeLayer);
	void menuMusicToggleCallback(Ref* pSender);
	virtual void onExit();
	virtual void onEnter();
	virtual void cleanup();
	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();

	bool bgMusic_is_paused=true;

private:

	Size vsable = Size(960, 540);

};