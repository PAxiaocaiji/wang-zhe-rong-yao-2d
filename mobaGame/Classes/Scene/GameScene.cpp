#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Size visibleSize;
Vec2 origin;

int soldiers_up_1[3] = { 201,202,203 };
int soldiers_middle_1[3] = { 211,212,213 };
int soldiers_down_1[3] = { 221,222,223 };
int soldiers_up_2[3] = { 204,205,206 };
int soldiers_middle_2[3] = { 214,215,216 };
int soldiers_down_2[3] = { 224,225,226 };
int the_soldiers[18] = { 201,202,203,204,205,206,211,212,213,214,215,216,221,222,223,224,225,226 };

int jidis[2] = { 1,2 };
int fangyuta_up_1[3] = { 1001,1002,1003 };
int fangyuta_up_2[3] = { 1004,1005,1006 };
int fangyuta_middle_1[4] = { 1011,1012,1013,1014 };
int fangyuta_middle_2[4] = { 1015,1016,1017,1018 };
int fangyuta_down_1[3] = { 1021,1022,1023 };
int fangyuta_down_2[3] = { 1024,1025,1026 };

int shuijing_1[3] = { 31,32,33 };
int shuijing_2[3] = { 34,35,36 };

int hero_1;
int hero_2;

clock_t last_born_soldier;

Vector<Soldier*> soldiers;
Vector<FangYuTa*> fangYuTas;
Vector<ShuiJing*> shuiJings;
Vector<JiDi*> jiDis;
Vector<YeGuai*>yeGuais;

// 0 for stay, 1 for up, 2 for up right, 3 for right, 4 for down right, 5 for down,
// 6 for down left, 7 for left, 8 for up left
int Visual_Change = 0;

Scene* HelloWorld::createScene()
{

	Scene* scene = Scene::create();
	HelloWorld* helloWorld = HelloWorld::create();

	scene->addChild(helloWorld);
	return scene;
}
bool HelloWorld::init()
{

	if (!Layer::init())
	{
		return false;
	}

	last_born_soldier = clock();
	soldiers.reserve(20);

	auto StartItem1 = MenuItemSprite::create(
		Sprite::create("healthbuff.png"),
		Sprite::create("healthbuff.png"),
		[&](Ref*ref) {
		if ()
			-= 20;
	}
	);

	auto StartItem2 = MenuItemSprite::create(
		Sprite::create("attackbuff.png"),
		Sprite::create("attackbuff.png"),
		[&](Ref*ref) {
		if()
			-=20
	}
	);

	auto StartItem3 = MenuItemSprite::create(
		Sprite::create("speedbuff.png"),
		Sprite::create("speedbuff.png"),
		[&](Ref*ref) {

	}
	);

	StartItem1->setPosition(360, 270);
	StartItem2->setPosition(480, 135);
	StartItem3->setPosition(600, 270);

	auto menu1 = Menu::create(StartItem1, NULL);
	menu1->setPosition(Point::ZERO);
	this->addChild(menu1);

	auto menu2 = Menu::create(StartItem2, NULL);
	menu2->setPosition(Point::ZERO);
	this->addChild(menu2);

	auto menu3 = Menu::create(StartItem3, NULL);
	menu3->setPosition(Point::ZERO);
	this->addChild(menu3);

	menu1->setVisible(false);
	menu2->setVisible(false);
	menu3->setVisible(false);

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	auto _mouseListener = EventListenerMouse::create();
	_mouseListener->onMouseDown = CC_CALLBACK_1(HelloWorld::onMouseDown, this);
	_mouseListener->onMouseMove = CC_CALLBACK_1(HelloWorld::onMouseMove, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);

	soldiers.pushBack(Soldier::create("swordsman", 1, 1, soldiers_up_1[0]));
	soldiers.pushBack(Soldier::create("catapult", 1, 2, soldiers_up_1[1]));
	soldiers.pushBack(Soldier::create("archer", 1, 3, soldiers_up_1[2]));
	soldiers.pushBack(Soldier::create("skeleton_soldier", 2, 1, soldiers_up_2[0]));
	soldiers.pushBack(Soldier::create("skeleton_thrower", 2, 2, soldiers_up_2[1]));
	soldiers.pushBack(Soldier::create("skeleton_shooter", 2, 3, soldiers_up_2[2]));

	soldiers.pushBack(Soldier::create("swordsman", 1, 1, soldiers_middle_1[0]));
	soldiers.pushBack(Soldier::create("catapult", 1, 2, soldiers_middle_1[1]));
	soldiers.pushBack(Soldier::create("archer", 1, 3, soldiers_middle_1[2]));
	soldiers.pushBack(Soldier::create("skeleton_soldier", 2, 1, soldiers_middle_2[0]));
	soldiers.pushBack(Soldier::create("skeleton_thrower", 2, 2, soldiers_middle_2[1]));
	soldiers.pushBack(Soldier::create("skeleton_shooter", 2, 3, soldiers_middle_2[2]));

	soldiers.pushBack(Soldier::create("swordsman", 1, 1, soldiers_down_1[0]));
	soldiers.pushBack(Soldier::create("catapult", 1, 2, soldiers_down_1[1]));
	soldiers.pushBack(Soldier::create("archer", 1, 3, soldiers_down_1[2]));
	soldiers.pushBack(Soldier::create("skeleton_soldier", 2, 1, soldiers_down_2[0]));
	soldiers.pushBack(Soldier::create("skeleton_thrower", 2, 2, soldiers_down_2[1]));
	soldiers.pushBack(Soldier::create("skeleton_shooter", 2, 3, soldiers_down_2[2]));

	soldiers.at(0)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (15 - 105), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (15 + 105));
	soldiers.at(1)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (15 - 105), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (15 + 105));
	soldiers.at(2)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (15 - 105), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (15 + 105));
	soldiers.at(3)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (105 - 15), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (105 + 15));
	soldiers.at(4)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (105 - 15), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (105 + 15));
	soldiers.at(5)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (105 - 15), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (105 + 15));
	soldiers.at(6)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (38 - 105), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (38 + 105));
	soldiers.at(7)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (38 - 105), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (38 + 105));
	soldiers.at(8)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (38 - 105), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (38 + 105));
	soldiers.at(9)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (105 - 38), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (38 + 105));
	soldiers.at(10)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (105 - 38), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (38 + 105));
	soldiers.at(11)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (105 - 38), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (38 + 105));
	soldiers.at(12)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (39 - 134), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (39 + 134));
	soldiers.at(13)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (39 - 134), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (39 + 134));
	soldiers.at(14)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (39 - 134), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (39 + 134));
	soldiers.at(15)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (134 - 39), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (39 + 134));
	soldiers.at(16)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (134 - 39), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (39 + 134));
	soldiers.at(17)->setPosition(origin.x + visibleSize.height / 2 + 150 * 16.0 + 32 * (134 - 39), origin.y + visibleSize.height / 2 + 150 * 16.0 - 16 * (39 + 134));
	
	for (int i = 0;i < 3;i++)
	{
		addChild(soldiers.at(i), 0, soldiers_up_1[i]);
	}

	for (int i = 0;i < 3;i++)
	{
		addChild(soldiers.at(i+3), 0, soldiers_up_1[i]);
	}

	for (int i = 0;i < 3;i++)
	{
		addChild(soldiers.at(i+6), 0, soldiers_up_1[i]);
	}

	for (int i = 0;i < 3;i++)
	{
		addChild(soldiers.at(i+9), 0, soldiers_up_1[i]);
	}

	for (int i = 0;i < 3;i++)
	{
		addChild(soldiers.at(i+12), 0, soldiers_up_1[i]);
	}

	for (int i = 0;i < 3;i++)
	{
		addChild(soldiers.at(i + 15), 0, soldiers_up_1[i]);
	}

	for (size_t i = 0;i < 18;i++)
	{
		soldiers.at(i)->setVisible(false);
	}

	auto tilemap = TMXTiledMap::create("maps/map1.tmx");
	tilemap->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	tilemap->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(tilemap, -10, 99);

	this->schedule(schedule_selector(HelloWorld::soldier_born));

	this->scheduleUpdate();
	return true;
}

bool soldier_all_die()
{
	for (int i = 0;i < 18;i++)
	{
		if (!soldiers.at(i)->isVisible())
			return false;
	}
	return true;
}

void HelloWorld::soldier_born(float dt)
{
	if ((clock() - last_born_soldier) / CLOCKS_PER_SEC >= 30 && soldier_all_die)
	{
		for (int i = 0;i < 18;i++)
		{
			soldiers.at(i)->setVisible(true);
		}
		for (int i = 0;i < 3;i++)
		{
			soldiers.at(i)->update(hero_2, 204, 1004, TA);
		}
		for (int i = 0;i < 3;i++)
		{
			soldiers.at(i+3)->update(hero_1, 201, 1001, TA);
		}
		for (int i = 0;i < 3;i++)
		{
			soldiers.at(i+6)->update(hero_2, 214, 1015, TA);
		}
		for (int i = 0;i < 3;i++)
		{
			soldiers.at(i+9)->update(hero_1, 211, 1011, TA);
		}
		for (int i = 0;i < 3;i++)
		{
			soldiers.at(i+12)->update(hero_2, 224, 1024, TA);
		}
		for (int i = 0;i < 3;i++)
		{
			soldiers.at(i+15)->update(hero_1, 221, 1021, TA);
		}
	}
}

void HelloWorld::adjust_ZOrder()
{
	for (int i = 0;i < 18;i++)
	{
		
	}

	Heroes* hero = (Heroes*)this->getChildByTag(0);
	Heroes* enemy = (Heroes*)this->getChildByTag(1);
	if (hero->getPosition().y >= enemy->getPosition().y)
	{
		hero->setZOrder(-2);
		enemy->setZOrder(-1);
	}
	else
	{
		hero->setZOrder(-1);
		enemy->setZOrder(-2);
	}
}

void HelloWorld::changeVisual()
{
	switch (Visual_Change)
	{
	case 1: this->setPosition(Vec2(getPosition().x, getPosition().y - 5.0f)); break;
	case 2: this->setPosition(Vec2(getPosition().x - 5.0f, getPosition().y - 5.0f)); break;
	case 3: this->setPosition(Vec2(getPosition().x - 5.0f, getPosition().y)); break;
	case 4: this->setPosition(Vec2(getPosition().x - 5.0f, getPosition().y + 5.0f)); break;
	case 5: this->setPosition(Vec2(getPosition().x, getPosition().y + 5.0f)); break;
	case 6: this->setPosition(Vec2(getPosition().x + 5.0f, getPosition().y + 5.0f)); break;
	case 7: this->setPosition(Vec2(getPosition().x + 5.0f, getPosition().y)); break;
	case 8: this->setPosition(Vec2(getPosition().x + 5.0f, getPosition().y - 5.0f)); break;
	}
}

void HelloWorld::update(float dt)
{
	/*
	Heroes* hero = (Heroes*)this->getChildByTag(0);
	Heroes* enemy = (Heroes*)this->getChildByTag(1);
	auto sprite = this->getChildByTag(10);
	Vec2 vec;
	if (enemy->getPosition() == Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 4 + origin.y))
		enemy->set_destination(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 3 / 4 + origin.y));
	if (enemy->getPosition() == Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 3 / 4 + origin.y))
		enemy->set_destination(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 4 + origin.y));
	adjust_ZOrder();
	
	hero->updateVertextZ();
	enemy->updateVertextZ();
	hero->arrived();
	hero->follow();
	*/changeVisual();
}

void HelloWorld::onMouseDown(Event *event)
{
	/*
	EventMouse* e = (EventMouse*)event;
	Heroes* hero = (Heroes*)this->getChildByTag(0);
	Heroes* enemy = (Heroes*)this->getChildByTag(1);
	float delta_x = getPosition().x - origin.x;
	float delta_y = getPosition().y - origin.y;
	float x = e->getCursorX() - delta_x;
	float y = e->getCursorY() - delta_y;
	if (-50.0 < x - enemy->getPosition().x && x - enemy->getPosition().x < 50.0
		&& -50.0 < y - enemy->getPosition().y && y - enemy->getPosition().y < 50.0)
	{
		hero->setTarget(1,1);
	}
	else
	{
		Vec2 des;
		des.x = x;
		des.y = y;
		hero->set_destination(des);
	}
	*/
}

void HelloWorld::onMouseMove(Event *event)
{
	EventMouse* e = (EventMouse*)event;
	if (e->getCursorY() >= visibleSize.height + origin.y)
	{
		if (e->getCursorX() >= visibleSize.width + origin.x)
			Visual_Change = 2;
		else if (e->getCursorX() <= origin.x)
			Visual_Change = 8;
		else
			Visual_Change = 1;
	}
	else if (e->getCursorY() <= origin.y)
	{
		if (e->getCursorX() >= visibleSize.width + origin.x)
			Visual_Change = 4;
		else if (e->getCursorX() <= origin.x)
			Visual_Change = 6;
		else
			Visual_Change = 5;
	}
	else
	{
		if (e->getCursorX() >= visibleSize.width + origin.x)
			Visual_Change = 3;
		else if (e->getCursorX() <= origin.x)
			Visual_Change = 7;
		else
			Visual_Change = 0;
	}
}

void skill_damage_wizard_1(int team,int tag,int type,Vec2 position)
{
	
}

void skill_damage_archer_2(int team,int tag,Vec2 position)
{

}

void skill_damage_wizard_2(int team, Heroes* targ)
{

}

void skill_damage_wizard_3(int team, Heroes* targ)
{

}

void skill_damage_saber_3(int team,int tag,int type,Vec2 position)
{

}

void HelloWorld::skill_effect_archer_3(Vec2 position)
{

}

void HelloWorld::onEnter()
{
	Layer::onEnter();
}

void HelloWorld::onExit()
{
	Layer::onExit();
}

void HelloWorld::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/bg2.mp3", true);
}

void HelloWorld::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
}

void HelloWorld::cleanup()
{
	Layer::cleanup();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/bg1.mp3");
}


