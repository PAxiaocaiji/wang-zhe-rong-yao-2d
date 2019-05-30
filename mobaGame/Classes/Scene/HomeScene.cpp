#include"HomeScene.h"
#include<extensions/cocos-ext.h>
#include<SimpleAudioEngine.h>
#include"Setting.h"

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

	auto bgSprite = Sprite::create("background.1.jpg");
	bgSprite->setPosition(vsable.width / 2, vsable.height / 2);
	this->addChild(bgSprite);

	auto StartItem1=MenuItemSprite::create(
		Sprite::create("start.png"),
		Sprite::create("start1.png"),
		[&](Ref*ref) {
		//Director::getInstance()->replaceScene();
	}
	);

	auto StartItem2 = MenuItemSprite::create(
		Sprite::create("setting.png"),
		Sprite::create("setting1.png"),
		[&](Ref*ref) {
		Director::getInstance()->replaceScene(AudioControlLayer::createScene());
	}
	);

	StartItem1->setPosition(480, 215);
	StartItem2->setPosition(480, 135);

	auto menu1 = Menu::create(StartItem1, NULL);
	menu1->setPosition(Point::ZERO);
	this->addChild(menu1);
	
	auto menu2 = Menu::create(StartItem2, NULL);
	menu2->setPosition(Point::ZERO);
	this->addChild(menu2);

	auto musicOnMenuItem = MenuItemImage::create(
		"music1.png", "music1.png"
	);
	auto musicOffMenuItem = MenuItemImage::create(
		"music.png", "music.png"
	);

	auto musicToggleMenuItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(HomeLayer::menuMusicToggleCallback, this),
		musicOnMenuItem,
		musicOffMenuItem,
		NULL);

	musicToggleMenuItem->setPosition(900, 480);

	auto quitMenuItem = MenuItemSprite::create(
		Sprite::create("quit.png"),
		Sprite::create("quit1.png"),
		[&](Ref*ref) {
		Director::getInstance()->end();
	}
	);

	quitMenuItem->setPosition(480, 90);

	auto menu3 = Menu::create(musicToggleMenuItem, NULL);
	menu3->setPosition(Point::ZERO);
	this->addChild(menu3);

	auto menu4 = Menu::create(quitMenuItem, NULL);
	menu4->setPosition(Point::ZERO);
	this->addChild(menu4);

	return true;
}

void HomeLayer::menuMusicToggleCallback(Ref* pSender)
{
	if (bgMusic_is_paused == false)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		bgMusic_is_paused = true;
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		bgMusic_is_paused = false;
	}
}

void HomeLayer::onEnter()
{
	Layer::onEnter();
}

void HomeLayer::onExit()
{
	Layer::onExit();
}

void HomeLayer::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/bg1.mp3",true);
	bgMusic_is_paused = false;
}

void HomeLayer::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
}

void HomeLayer::cleanup()
{
	Layer::cleanup();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/bg1.mp3");
}