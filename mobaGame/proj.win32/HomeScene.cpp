#include"HomeScene.h"
#include<extensions/cocos-ext.h>

USING_NS_CC;
USING_NS_CC_EXT;

Scene* HomeLayer::createScene() 
{

	Scene* scene = Scene::create();
	HomeLayer* homeLayer = HomeLayer::create();

	scene->addChild(homeLayer);
	return scene;
}

bool HomeLayer::init() 
{

	if (!Layer::init())
	{
		return false;
	}

	auto bgSprite = Sprite::create();

























}


