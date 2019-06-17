#include"EndScene.h"

Scene* EndLayer::createScene()
{

	Scene* scene = Scene::create();
	EndLayer* endlayer = EndLayer::create();

	scene->addChild(endlayer);
	return scene;
}

bool EndLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto label = LabelTTF::create("GAME OVER", "Arial", 64);
	label->setPosition(480, 200);
	this->addChild(label, 1);

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

void EndLayer::onEnter()
{
	Layer::onEnter();
}

void EndLayer::onExit()
{
	Layer::onExit();
}

void EndLayer::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/bg2.mp3", true);
	bgMusic_is_paused = false;
}

void EndLayer::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
}

void EndLayer::cleanup()
{
	Layer::cleanup();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/bg1.mp3");
}