#pragma once
#include<cocos2d.h>
#include<SimpleAudioEngine.h>
#include"HomeScene.h"

USING_NS_CC;

class AudioControlLayer : public Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(AudioControlLayer);

 
private:

	Size vsable = Size(960, 540);
};
