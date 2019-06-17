#pragma once
#include<cocos2d.h>
#include"GameData.h"
#include<time.h>
#include<string>
#define CHENGZHANGSHUXING1 5
#define CHENGZHANGSHUXING2 100

USING_NS_CC;

struct Buff
{
	float boost;
	int boost_type;
	int theTime;
};

struct Skill
{
	char key;
	int type;
	Buff buff;
	Buff enemy_debuff;
	int effect_fw;
	int caste_fw;
	int cd;
	int damage;
	clock_t lasttime;
};


struct int_Sprite
{
	int type;
	int targetTag;
};

struct BaseData
{
	int Tag;
	int ShengMingZhi;
	int FaLiZhi;
	int GongJiLi;
	int FangYuLi;
	float GongSu;
	float YiSu;
	int Level;
	int ZhenWangQ;
	int ZhenWangJ;
	int Team = 0;
	int ChiYouQ;
	int ChiYouJ;
	float GongJiFW;
	float JingJieFW;
	bool can_be_break;
	std::string file_name;
	int direction;
	int status;
	int dqShengMZ;
	int type;
	int is_dead = 0;
	Vec2 destination;
	bool arrive = true;
	int_Sprite dq_target = {0,0};
};

class BaseSprite :public Sprite
{
public:
	BaseData basedata;
	virtual void underAttack(BaseSprite* enemy);
	virtual bool dead(BaseSprite* enemy);
	static BaseSprite* create(BaseSprite* baseSprite, const std::string filename);
	void Play_Animation();
	void setTarget(BaseSprite* target);
	void updateVertextZ();
	bool arrived();
};

class Soldier :public Sprite
{
	int the_type;
public:
	BaseData basedata;
	int the_lu;
	static Soldier* create(const std::string filename, int team, int type, int tag);
	void setSoldierProperty(int team, int type, int tag);
	virtual void update(int heros, int soldiers, int buildings, int building_type);
	void underJNAttack();
	void move();
	void attack(int target_tag, int tar_type);
	void updateVertextZ();
	void setTarget(int target_tag, int tar_type);
	void Play_Animation();
	bool dead(int enemy_tag, int ene_type);
	void underAttack(int enemy_tag, int ene_type);
	void level_up();
};

class FangYuTa :public Sprite
{
public:
	BaseData basedata;
	int the_lu;
	static FangYuTa* create(std::string filename, int team, int tag);
	void setFangYuTaProperty(int team, int tag);
	void attack(int target_tag, int tar_type);
	virtual void update(int heros, int soldiers);
	void updateVertextZ();
	void setTarget(int target_tag, int tar_type);
	void Play_Animation();
	bool dead(int enemy_tag, int ene_type);
	void underAttack(int enemy_tag, int ene_type);
};

class ShuiJing :public Sprite
{
public:
	BaseData basedata;
	int the_lu;
	static ShuiJing* create(const std::string filename, int team, int lu, int tag);
	void setShuiJingProperty(int team, int lu, int tag);
	void Play_Animation();
	bool dead(int enemy_tag, int ene_type);
	void underAttack(int enemy_tag, int ene_type);
};

class JiDi :public Sprite
{
	bool boost_lu[3] = { 0,0,0 };
public:
	static JiDi* create(const std::string filename);
	BaseData basedata;
	void setJiDiProperty(int team, int tag);
	void boost(ShuiJing* shuijing);
	bool whetherBoost(int lu);
	void Play_Animation();
	bool dead(int enemy_tag, int ene_type);
	void underAttack(int enemy_tag, int ene_type);
};

class YeGuai :public Sprite
{
	bool is_active;
public:
	BaseData basedata;
	static YeGuai* create(const std::string filename, int tag, int the_type);
	void setYeGuaiProperty(int tag, int the_type);
	void move();
	bool arrived();
	void setTarget(int target_tag, int tar_type);
	void Play_Animation();
	bool dead(int enemy_tag, int ene_type);
	void underAttack(int enemy_tag, int ene_type);
	void level_up();
};

class Heroes : public Sprite
{
public:
	BaseData basedata;
	int heroType;
	int kill = 0;
	int death = 0;
	Buff skillBuff;
	clock_t gotTime;
	void returnNormal();
	void gotBuff();
	bool is_buff = false;
	static Heroes* create(const std::string filename, int team, int hero_type, int tag);
	void follow();
	void attack(int target_tag, int tar_type);
	void setHeroProperty(int team, int hero_type, int tag);
	void set_destination(Vec2 des);
	bool arrived();
	void updateVertextZ();
	void update();
	void setTarget(int target_tag, int tar_type);
	void Play_Animation();
	bool dead(int enemy_tag, int ene_type);
	void underAttack(int enemy_tag, int ene_type);
	void level_up();
};

class SkillsManager
{
private:
	int id;
	Skill skill1;
	Skill skill2;
	Skill skill3;
public:
	SkillsManager(int id);
	bool check_cd(char key);
	void makeBuffSkill(char key, Heroes* caster);
	~SkillsManager() {};
};

