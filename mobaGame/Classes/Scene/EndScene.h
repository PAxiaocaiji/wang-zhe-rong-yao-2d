#pragma once
#include<cocos2d.h>
#include<SimpleAudioEngine.h>
#include"HomeScene.h"

USING_NS_CC;

using namespace CocosDenshion;

class EndLayer :public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(EndLayer);
	void menuMusicToggleCallback(Ref* pSender);
	virtual void onExit();
	virtual void onEnter();
	virtual void cleanup();
	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();

	bool bgMusic_is_paused = true;

private:

	Size vsable = Size(960, 540);
};