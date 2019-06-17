#pragma once
#include<cocos2d.h>
#include"GameScene.h"
#include"myu/myu.h"
#include<cocos2d.h>
#include<SimpleAudioEngine.h>

USING_NS_CC;

using namespace CocosDenshion;

class Choose :public Layer
{
	Size vsable = Size(960, 540);
public:
	static Scene* createScene();
	virtual bool init();
	virtual void onExit();
	virtual void onEnter();
	virtual void cleanup();
	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();
	CREATE_FUNC(Choose);
};