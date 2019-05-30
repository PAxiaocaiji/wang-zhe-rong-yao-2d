#include"Setting.h"
#include<ui/CocosGUI.h>
#include<SimpleAudioEngine.h>

USING_NS_CC;
using namespace ui;

Scene* AudioControlLayer::createScene() {
	auto scene = Scene::create();
	auto audioControlLayer = AudioControlLayer::create();
	
	scene->addChild(audioControlLayer);
	return scene;
}

 bool AudioControlLayer::init() {
	if (!Layer::create())
	{
		return false;
	}
	
	auto bgSprite = Sprite::create("background.2.jpg");
	bgSprite->setPosition(vsable.width / 2, vsable.height / 2);
	this->addChild(bgSprite);

	auto quitMenuItem = MenuItemSprite::create(
		Sprite::create("back.png"),
		Sprite::create("back1.png"),
		[&](Ref*ref) {
		Director::getInstance()->replaceScene(HomeLayer::createScene());
	}
	);

	quitMenuItem->setPosition(480, 90);

	auto menu4 = Menu::create(quitMenuItem, NULL);
	menu4->setPosition(Point::ZERO);
	this->addChild(menu4);

	return true;
}