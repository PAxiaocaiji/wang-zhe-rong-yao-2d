#include"ChoosingScene.h"



void Choose::onEnter()
{
	Layer::onEnter();
}

void Choose::onExit()
{
	Layer::onExit();
}

void Choose::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/bg2.mp3", true);
}

void Choose::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
}

void Choose::cleanup()
{
	Layer::cleanup();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/bg1.mp3");
}

Scene* Choose::createScene()
{

	Scene* scene = Scene::create();
	Choose* choose = Choose::create();

	scene->addChild(choose);
	return scene;
}

bool Choose::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto bgSprite = Sprite::create("background.2.jpg");
	bgSprite->setPosition(vsable.width / 2, vsable.height / 2);
	this->addChild(bgSprite);

	auto StartItem1 = MenuItemSprite::create(
		Sprite::create("animation/hero1/hero1.png"),
		Sprite::create("animation/hero1/hero12.png"),
		[&](Ref*ref) {
		auto scene = Scene::create();
		HelloWorld* nextScene = HelloWorld::create();
		scene->addChild(nextScene);
		nextScene->hero_choice = SABER;
		Director::getInstance()->replaceScene(TransitionFade::create(SABER,scene));
	}
	);

	auto StartItem2 = MenuItemSprite::create(
		Sprite::create("animation/hero2/hero2.png"),
		Sprite::create("animation/hero2/hero22.png"),
		[&](Ref*ref) {
		auto scene = Scene::create();
		HelloWorld* nextScene = HelloWorld::create();
		scene->addChild(nextScene);
		nextScene->hero_choice = ARCHER;
		Director::getInstance()->replaceScene(TransitionFade::create(ARCHER, scene));
	}
	);

	auto StartItem3 = MenuItemSprite::create(
		Sprite::create("animation/hero3/hero3.png"),
		Sprite::create("animation/hero3/hero32.png"),
		[&](Ref*ref) {
		auto scene = Scene::create();
		HelloWorld* nextScene = HelloWorld::create();
		scene->addChild(nextScene);
		nextScene->hero_choice = WIZARD;
		Director::getInstance()->replaceScene(TransitionFade::create(WIZARD, scene));
	}
	);

	StartItem1->setPosition(160, 215);
	StartItem2->setPosition(480, 215);
	StartItem3->setPosition(800, 215);

	auto menu1 = Menu::create(StartItem1, NULL);
	menu1->setPosition(Point::ZERO);
	this->addChild(menu1);

	auto menu2 = Menu::create(StartItem2, NULL);
	menu2->setPosition(Point::ZERO);
	this->addChild(menu2);

	auto menu3 = Menu::create(StartItem3, NULL);
	menu3->setPosition(Point::ZERO);
	this->addChild(menu3);
	return true;
}