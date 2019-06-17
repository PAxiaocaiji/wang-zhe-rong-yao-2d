#pragma once
#include "cocos2d.h"
#include "myu/myu.h"
#include"myu/GameData.h"

class HelloWorld : public cocos2d::Layer
{
public:
	int hero_choice;
	static Scene* createScene();
	virtual void onExit();
	virtual void onEnter();
	virtual void cleanup();
	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();
	virtual bool init();
	void update(float dt);
	void onMouseDown(cocos2d::Event *event);
	void onMouseMove(cocos2d::Event *event);
	void changeVisual();
	void adjust_ZOrder();
	void soldier_born(float dt);
	void skill_damage_wizard_1(int team, int tag, Vec2 position);
	void skill_damage_archer_2(int team, int tag, Vec2 position);
	void skill_damage_wizard_2(int team, Heroes* targ);
	void skill_damage_wizard_3(int team, Heroes* targ);
	void skill_damage_saber_1(int team, int tag, Vec2 position);
	void skill_effect_archer_3(Vec2 position);
	CREATE_FUNC(HelloWorld);
};

