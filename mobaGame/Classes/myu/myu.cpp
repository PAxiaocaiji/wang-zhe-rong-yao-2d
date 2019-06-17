#include"myu.h"


FangYuTa* FangYuTa::create(const std::string filename, int team, int tag)
{
	FangYuTa* fangYuTa = new FangYuTa;
	fangYuTa->basedata.file_name = filename;
	if (fangYuTa && fangYuTa->initWithFile(filename + "/" + filename + ".png"))
	{
		fangYuTa->autorelease();
		fangYuTa->setAnchorPoint(Vec2(0.5, 0));
		fangYuTa->setFangYuTaProperty(team, tag);
		fangYuTa->basedata.direction = 0;
		fangYuTa->basedata.status = 0;
		return fangYuTa;
	}
	CC_SAFE_DELETE(fangYuTa);

	return nullptr;
}

Soldier* Soldier::create(const std::string filename, int team, int type, int tag)
{
	Soldier* soldier = new Soldier;
	soldier->basedata.file_name = filename;
	if (soldier && soldier->initWithFile(filename + "/" + filename + ".png"))
	{
		soldier->autorelease();
		soldier->setAnchorPoint(Vec2(0.5, 0));
		soldier->setSoldierProperty(team, type, tag);
		soldier->basedata.direction = 0;
		soldier->basedata.status = 0;
		return soldier;
	}
	CC_SAFE_DELETE(soldier);

	return nullptr;
}

ShuiJing* ShuiJing::create(const std::string filename, int team, int lu, int tag)
{
	ShuiJing* shuiJing = new ShuiJing;
	shuiJing->basedata.file_name = filename;
	if (shuiJing && shuiJing->initWithFile(filename + "/" + filename + ".png"))
	{
		shuiJing->autorelease();
		shuiJing->setAnchorPoint(Vec2(0.5, 0));
		shuiJing->setShuiJingProperty(team, lu, tag);
		shuiJing->basedata.direction = 0;
		shuiJing->basedata.status = 0;
		return shuiJing;
	}
	CC_SAFE_DELETE(shuiJing);

	return nullptr;
}

JiDi* JiDi::create(const std::string filename)
{
	JiDi* jiDi = new JiDi;
	jiDi->basedata.file_name = filename;
	if (jiDi && jiDi->initWithFile(filename + "/" + filename + ".png"))
	{
		jiDi->autorelease();
		jiDi->setAnchorPoint(Vec2(0.5, 0));
		jiDi->basedata.direction = 0;
		jiDi->basedata.status = 0;
		return jiDi;
	}
	CC_SAFE_DELETE(jiDi);

	return nullptr;
}

YeGuai* YeGuai::create(const std::string filename, int tag, int the_type)
{
	YeGuai* yeGuai = new YeGuai;
	yeGuai->basedata.file_name = filename;
	if (yeGuai && yeGuai->initWithFile(filename + "/" + filename + ".png"))
	{
		yeGuai->autorelease();
		yeGuai->setAnchorPoint(Vec2(0.5, 0));
		yeGuai->setYeGuaiProperty(tag, the_type);
		yeGuai->basedata.direction = 0;
		yeGuai->basedata.status = 0;
		return yeGuai;
	}
	CC_SAFE_DELETE(yeGuai);

	return nullptr;
}

void Heroes::setHeroProperty(int team, int hero_type, int tag)
{
	basedata.Tag = tag;
	basedata.arrive = true;
	basedata.Team = team;
	basedata.type = HERO;
	heroType = hero_type;
	basedata.Level = 1;
	basedata.ZhenWangJ = HERO_ZWJY;
	basedata.ZhenWangQ = HERO_ZWJQ;
	basedata.ChiYouJ = 0;
	basedata.ChiYouQ = CHUSHIQ;
	switch (heroType)
	{
	case SABER:
		basedata.ShengMingZhi = HERO_SMZ_1 + basedata.Level*HERO_SMZ_1_CZ;
		basedata.FaLiZhi = HERO_FLZ_1 + basedata.Level*HERO_FLZ_1_CZ;
		basedata.GongJiLi = HERO_GJL_1 + basedata.Level*HERO_GJL_1_CZ;
		basedata.FangYuLi = HERO_FYL_1 + basedata.Level*HERO_FYL_1_CZ;
		basedata.GongJiFW = HERO_GJFW_1;
		basedata.GongSu = HERO_GS_1 + basedata.Level*HERO_GS_1_CZ;
		basedata.YiSu = HERO_YS_1;
		break;
	case ARCHER:
		basedata.ShengMingZhi = HERO_SMZ_2 + basedata.Level*HERO_SMZ_2_CZ;
		basedata.FaLiZhi = HERO_FLZ_2 + basedata.Level*HERO_FLZ_2_CZ;
		basedata.GongJiLi = HERO_GJL_2 + basedata.Level*HERO_GJL_2_CZ;
		basedata.FangYuLi = HERO_FYL_2 + basedata.Level*HERO_FYL_2_CZ;
		basedata.GongJiFW = HERO_GJFW_2;
		basedata.GongSu = HERO_GS_2 + basedata.Level*HERO_GS_2_CZ;
		basedata.YiSu = HERO_YS_2;
		break;
	case WIZARD:
		basedata.ShengMingZhi = HERO_SMZ_3 + basedata.Level*HERO_SMZ_3_CZ;
		basedata.FaLiZhi = HERO_FLZ_3 + basedata.Level*HERO_FLZ_3_CZ;
		basedata.GongJiLi = HERO_GJL_3 + basedata.Level*HERO_GJL_3_CZ;
		basedata.FangYuLi = HERO_FYL_3 + basedata.Level*HERO_FYL_3_CZ;
		basedata.GongJiFW = HERO_GJFW_3;
		basedata.GongSu = HERO_GS_3 + basedata.Level*HERO_GS_3_CZ;
		basedata.YiSu = HERO_YS_3;
		break;
	}
}

Heroes* Heroes::create(const std::string filename, int team, int hero_type, int tag)
{
	Heroes* heroes = new Heroes;
	heroes->basedata.file_name = filename;
	if (heroes && heroes->initWithFile(filename + "/" + filename + ".png"))
	{
		heroes->autorelease();
		heroes->setAnchorPoint(Vec2(0.5, 0));
		heroes->setHeroProperty(team, hero_type, tag);
		heroes->basedata.direction = 0;
		heroes->basedata.status = 0;
		return heroes;
	}
	CC_SAFE_DELETE(heroes);

	return nullptr;
}

void Heroes::Play_Animation()
{
	std::string Status, dir;
	auto cache = SpriteFrameCache::sharedSpriteFrameCache();
	switch (basedata.direction)
	{
	case 0: dir = "/up.plist"; break;
	case 1: dir = "/up_right.plist"; break;
	case 2: dir = "/right.plist"; break;
	case 3: dir = "/down_right.plist"; break;
	case 4: dir = "/down.plist"; break;
	case 5: dir = "/down_left.plist"; break;
	case 6: dir = "/left.plist"; break;
	case 7: dir = "/up_left.plist"; break;
	}
	switch (basedata.status)
	{
	case 0: Status = "/stand"; break;
	case 1: Status = "/move"; break;
	case 2: Status = "/attack"; break;
	case 3: Status = "/death"; break;
	}
	cache->addSpriteFramesWithFile(basedata.file_name + Status + dir);
	Vector<SpriteFrame*> frames;
	frames.reserve(6);
	char str[20];
	for (int i = 1; i < 7; i++)
	{
		sprintf(str, "%d.png", i);
		auto frame = cache->spriteFrameByName(str);
		frames.pushBack(frame);
	}
	auto animation = Animation::createWithSpriteFrames(frames, 0.15f);
	auto action = Animate::create(animation);
	if (basedata.status == STAND || basedata.status == MOVE)
	{
		auto repeat = RepeatForever::create(action);
		repeat->setTag(2);
		this->runAction(repeat);
	}
	if (basedata.status == ATTACK)
	{
		auto callbackFunc = [&]()
		{
			int tar_type = basedata.dq_target.type;
			switch (tar_type)
			{
			case HERO:
			{
				auto parent = getParent();
				auto target = (Heroes*)parent->getChildByTag(basedata.dq_target.targetTag);
				basedata.status = 0;
				target->underAttack(basedata.Tag, basedata.type);
				break;
			}
			case SOLDIER:
			{
				auto parent = getParent();
				auto target = (Soldier*)parent->getChildByTag(basedata.dq_target.targetTag);
				basedata.status = 0;
				target->underAttack(basedata.Tag, basedata.type);
				break;
			}
			case TA:
			{
				auto parent = getParent();
				auto target = (FangYuTa*)parent->getChildByTag(basedata.dq_target.targetTag);
				basedata.status = 0;
				target->underAttack(basedata.Tag, basedata.type);
				break;
			}
			case SHUIJING:
			{
				auto parent = getParent();
				auto target = (ShuiJing*)parent->getChildByTag(basedata.dq_target.targetTag);
				basedata.status = 0;
				target->underAttack(basedata.Tag, basedata.type);
				break;
			}
			case JIDI:
			{
				auto parent = getParent();
				auto target = (JiDi*)parent->getChildByTag(basedata.dq_target.targetTag);
				basedata.status = 0;
				target->underAttack(basedata.Tag, basedata.type);
				break;
			}
			case YEGUAI:
			{
				auto parent = getParent();
				auto target = (YeGuai*)parent->getChildByTag(basedata.dq_target.targetTag);
				basedata.status = 0;
				target->underAttack(basedata.Tag, basedata.type);
				break;
			}
			default:
				break;
			}
		};
		CallFunc *callFunc = CallFunc::create(callbackFunc);
		Action *actions = Sequence::create(action, callFunc, NULL);
		actions->setTag(2);
		this->runAction(actions);
	}
	if (basedata.status == DEAD)
	{
		auto callbackFunc1 = [&]()
		{
			setVisible(false);
		};
		auto callbackFunc2 = [&]()
		{
			basedata.status = 0;
			basedata.dqShengMZ = basedata.ShengMingZhi;
			setVisible(true);
		};
		CallFunc *callFunc1 = CallFunc::create(callbackFunc1);
		CallFunc *callFunc2 = CallFunc::create(callbackFunc2);
		auto delay = DelayTime::create(5);
		Action *actions = Sequence::create(action, callFunc1, delay, callFunc2, NULL);
		this->runAction(actions);
	}
	cache->removeSpriteFramesFromFile(basedata.file_name + Status + dir);
}

void Heroes::setTarget(int target_tag, int tar_type)
{
	basedata.dq_target.targetTag = target_tag;
	basedata.dq_target.type = tar_type;
	stopActionByTag(1);
}

void Heroes::updateVertextZ()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	float x = getPosition().x - origin.x - visibleSize.width / 2;
	float y = origin.y + visibleSize.height / 2 + 150 * 16.0 - getPosition().y;
	int x_tiles = (int)((2 * y + x) / 64.0);
	int y_tiles = (int)((2 * y - x) / 64.0);
	float lowestZ = -(150 + 150);
	float currentZ = x_tiles + y_tiles;
	this->setVertexZ(lowestZ + currentZ - 1);
}


void Heroes::underAttack(int enemy_tag, int ene_type)
{
	auto parent = getParent();
	switch (ene_type)
	{
	case HERO:
	{
		auto enemy = (Heroes*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	case SOLDIER:
	{
		auto enemy = (Soldier*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	case TA:
	{
		auto enemy = (FangYuTa*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	case YEGUAI:
	{
		auto enemy = (YeGuai*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	default:
		break;
	}
}

bool Heroes::dead(int enemy_tag, int ene_type)
{
	if (basedata.dqShengMZ > 0)
	{
		basedata.is_dead = 0;
		return basedata.is_dead;
	}
	basedata.is_dead = 1;
	basedata.status = DEAD;
	death += 1;
	if (ene_type == HERO)//may
	{
		auto parent = getParent();
		auto enemy = (Heroes*)parent->getChildByTag(enemy_tag);
		enemy->basedata.ChiYouQ += basedata.ZhenWangQ;
		enemy->basedata.ChiYouJ += basedata.ZhenWangJ;
		enemy->kill += 1;
		if (enemy->basedata.ChiYouJ > enemy->basedata.Level*SJ_SXJY&&enemy->basedata.Level < 20)
		{
			enemy->level_up();
		}
	}
	stopAllActions();
	Play_Animation();
	return basedata.is_dead;
}

void Heroes::returnNormal()
{
	if (clock() - gotTime >= skillBuff.theTime)
	{
		is_buff = false;
		if (skillBuff.boost_type == BOOST_TYPE_FANGYULI)
			basedata.FangYuLi /= skillBuff.boost;
		else if (skillBuff.boost_type == BOOST_TYPE_YISU)
			basedata.YiSu /= skillBuff.boost;
	}
}

void Heroes::gotBuff()
{
	is_buff = true;
	gotTime = clock();
	if (skillBuff.boost_type == BOOST_TYPE_FANGYULI)
		basedata.FangYuLi *= skillBuff.boost;
	else if (skillBuff.boost_type == BOOST_TYPE_YISU)
		basedata.YiSu *= skillBuff.boost;
}

bool Heroes::arrived()
{
	Vec2 position = getPosition();
	if (position == basedata.destination && basedata.arrive == false)
	{
		stopAllActions();
		basedata.status = STAND;
		Play_Animation();
		basedata.arrive = true;
	}
	return basedata.arrive;
}

void Heroes::set_destination(Vec2 des)
{
	Vec2 pos = getPosition();
	int Dir;
	float delta_x = des.x - pos.x;
	float delta_y = des.y - pos.y;
	float time = sqrt(delta_x * delta_x + delta_y * delta_y) / basedata.YiSu;
	basedata.dq_target.targetTag = 0;
	basedata.dq_target.type = 0;
	if (delta_x > 0.0f)
	{
		if (delta_y / delta_x >= 2.414214f) Dir = 0;
		if (delta_y / delta_x < 2.414214f && delta_y / delta_x >= 0.414214f) Dir = 1;
		if (delta_y / delta_x < 0.414214f && delta_y / delta_x >= -0.414214f) Dir = 2;
		if (delta_y / delta_x < -0.414214f && delta_y / delta_x >= -2.414214f) Dir = 3;
		if (delta_y / delta_x < -2.414214f) Dir = 4;
	}
	if (delta_x < 0.0f)
	{
		if (delta_y / delta_x >= 2.414214f) Dir = 4;
		if (delta_y / delta_x < 2.414214f && delta_y / delta_x >= 0.414214f) Dir = 5;
		if (delta_y / delta_x < 0.414214f && delta_y / delta_x >= -0.414214f) Dir = 6;
		if (delta_y / delta_x < -0.414214f && delta_y / delta_x >= -2.414214f) Dir = 7;
		if (delta_y / delta_x < -2.414214f) Dir = 0;
	}
	if (delta_x == 0.0f)
	{
		if (delta_y >= 0.0f) Dir = 0;
		else Dir = 4;
	}
	if (basedata.direction != Dir || basedata.status == 0)
	{
		basedata.status = MOVE;
		stopActionByTag(2);
		basedata.direction = Dir;
		Play_Animation();
	}
	if (basedata.status == MOVE)
		stopActionByTag(1);
	auto move_to = MoveTo::create(time, des);
	move_to->setTag(1);
	runAction(move_to);
	basedata.destination = des;
	basedata.arrive = false;
}

void Heroes::follow()
{
	if (basedata.dq_target.targetTag != 0 && basedata.status != ATTACK)
	{
		auto parent = getParent();
		Vec2 des;
		switch (basedata.dq_target.type)
		{
		case HERO:
		{
			auto target = (Heroes*)parent->getChildByTag(basedata.dq_target.targetTag);
			des = target->getPosition();
			if (target->basedata.status == DEAD)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = STAND;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
			break;
		}
		case SOLDIER:
		{
			auto target = (Soldier*)parent->getChildByTag(basedata.dq_target.targetTag);
			des = target->getPosition();
			if (target->basedata.status == DEAD)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = STAND;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
			break;
		}
		case SHUIJING:
		{
			auto target = (ShuiJing*)parent->getChildByTag(basedata.dq_target.targetTag);
			des = target->getPosition();
			if (target->basedata.status == DEAD)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = STAND;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
			break;
		}
		case JIDI:
		{
			auto target = (JiDi*)parent->getChildByTag(basedata.dq_target.targetTag);
			des = target->getPosition();
			if (target->basedata.status == DEAD)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = STAND;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
			break;
		}
		case TA:
		{
			auto target = (FangYuTa*)parent->getChildByTag(basedata.dq_target.targetTag);
			des = target->getPosition();
			if (target->basedata.status == DEAD)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = STAND;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
			break;
		}
		case YEGUAI:
		{
			auto target = (YeGuai*)parent->getChildByTag(basedata.dq_target.targetTag);
			des = target->getPosition();
			if (target->basedata.status == DEAD)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = STAND;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
			break;
		}
		default:
			break;
		}
		Vec2 pos = getPosition();
		float delta_x = des.x - pos.x;
		float delta_y = des.y - pos.y;
		int Dir;
		if (delta_x > 0.0f)
		{
			if (delta_y / delta_x >= 2.414214f) Dir = 0;
			if (delta_y / delta_x < 2.414214f && delta_y / delta_x >= 0.414214f) Dir = 1;
			if (delta_y / delta_x < 0.414214f && delta_y / delta_x >= -0.414214f) Dir = 2;
			if (delta_y / delta_x < -0.414214f && delta_y / delta_x >= -2.414214f) Dir = 3;
			if (delta_y / delta_x < -2.414214f) Dir = 4;
		}
		if (delta_x < 0.0f)
		{
			if (delta_y / delta_x >= 2.414214f) Dir = 4;
			if (delta_y / delta_x < 2.414214f && delta_y / delta_x >= 0.414214f) Dir = 5;
			if (delta_y / delta_x < 0.414214f && delta_y / delta_x >= -0.414214f) Dir = 6;
			if (delta_y / delta_x < -0.414214f && delta_y / delta_x >= -2.414214f) Dir = 7;
			if (delta_y / delta_x < -2.414214f) Dir = 0;
		}
		if (delta_x == 0.0f)
		{
			if (delta_y >= 0.0f) Dir = 0;
			else Dir = 4;
		}
		if (basedata.direction != Dir || basedata.status == 0)
		{
			basedata.status = MOVE;
			stopActionByTag(2);
			basedata.direction = Dir;
			Play_Animation();
		}
		float dx = (basedata.YiSu / 60.0f) * delta_x / sqrt(delta_x * delta_x + delta_y * delta_y);
		float dy = (basedata.YiSu / 60.0f) * delta_y / sqrt(delta_x * delta_x + delta_y * delta_y);
		setPosition(Vec2(pos.x + dx, pos.y + dy));
		if (pos.distance(des) < basedata.GongJiFW)
		{
			stopActionByTag(2);
			basedata.status = ATTACK;
			Play_Animation();
		}
	}
}

void Heroes::attack(int target_tag, int tar_type)
{
	setTarget(target_tag, tar_type);
	basedata.status = ATTACK;
	Play_Animation();
}

void FangYuTa::setFangYuTaProperty(int team, int tag)
{
	basedata.ShengMingZhi = TA_SMZ;
	basedata.FangYuLi = TA_FYL;
	basedata.GongJiLi = TA_GJL;
	basedata.GongSu = TA_GS;
	basedata.ZhenWangQ = TA_ZWJQ;
	basedata.ZhenWangJ = TA_ZWJY;
	basedata.GongJiFW = TA_GJFW;
	basedata.dqShengMZ = basedata.ShengMingZhi;

	basedata.Team = team;
	basedata.Tag = tag;

	basedata.dqShengMZ = TA_SMZ;
	basedata.type = TA;
}

void FangYuTa::setTarget(int target_tag, int tar_type)
{
	basedata.dq_target.targetTag = target_tag;
	basedata.dq_target.type = tar_type;
	stopActionByTag(1);
}

void FangYuTa::attack(int target_tag, int tar_type)
{
	setTarget(target_tag, tar_type);
	basedata.status = ATTACK;
	Play_Animation();
}

void FangYuTa::underAttack(int enemy_tag, int ene_type)
{
	auto parent = getParent();
	switch (ene_type)
	{
	case HERO:
	{
		auto enemy = (Heroes*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	case SOLDIER:
	{
		auto enemy = (Soldier*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	default:
		break;
	}
}

bool FangYuTa::dead(int enemy_tag, int ene_type)
{
	if (basedata.dqShengMZ > 0)
	{
		basedata.is_dead = 0;
		return basedata.is_dead;
	}
	basedata.is_dead = 1;
	basedata.status = DEAD;
	if (ene_type == HERO)//may
	{
		auto parent = getParent();
		auto enemy = (Heroes*)parent->getChildByTag(enemy_tag);
		enemy->basedata.ChiYouQ += basedata.ZhenWangQ;
		enemy->basedata.ChiYouJ += basedata.ZhenWangJ;
		if (enemy->basedata.ChiYouJ > enemy->basedata.Level*SJ_SXJY&&enemy->basedata.Level < 20)
		{
			enemy->level_up();
		}
	}
	stopAllActions();
	Play_Animation();
	return basedata.is_dead;
}

void FangYuTa::update(int heroes, int soldiers)
{
	auto position1 = this->getPosition();
	auto parent = getParent();

	if (basedata.dq_target.targetTag != 0)
	{
		auto the_dq_target = parent->getChildByTag(basedata.dq_target.targetTag);
		auto position4 = the_dq_target->getPosition();
		if (position1.distance(position4) <= basedata.GongJiFW)
		{
			attack(basedata.dq_target.targetTag, basedata.dq_target.type);
		}
		return;
	}

	basedata.dq_target.targetTag = 0;
	basedata.dq_target.type = 0;

	auto soldier = parent->getChildByTag(soldiers);
	auto position2 = soldier->getPosition();
	if (position1.distance(position2) > basedata.GongJiFW)
	{
		
			auto hero = (Heroes*)parent->getChildByTag(heroes);
			if (hero->basedata.Team != basedata.Team)
			{
				auto position3 = hero->getPosition();
				if (position1.distance(position3) < basedata.GongJiFW)
				{
					attack(heroes, HERO);
				}
			}
		
	}
	else
	{
		attack(soldiers, SOLDIER);
	}
}

void Soldier::setSoldierProperty(int team, int _type, int tag)
{
	basedata.type = SOLDIER;
	basedata.Tag = tag;
	basedata.Team = team;
	basedata.Level = 1;
	basedata.YiSu = BING_YS;
	basedata.GongSu = BING_GS;
	basedata.JingJieFW = BING_JJFW;

	the_type = _type;

	switch (_type)
	{
	case 1:
		basedata.GongJiLi = BING_GJL_1;
		basedata.ShengMingZhi = BING_SMZ_1;
		basedata.FangYuLi = BING_FYL_1;
		basedata.ZhenWangQ = BING_ZWJQ_1;
		basedata.ZhenWangJ = BING_ZWJQ_1;
		basedata.GongJiFW = BING_GJFW_1;
		break;
	case 2:
		basedata.GongJiLi = BING_GJL_2;
		basedata.ShengMingZhi = BING_SMZ_2;
		basedata.FangYuLi = BING_FYL_2;
		basedata.ZhenWangQ = BING_ZWJQ_2;
		basedata.ZhenWangJ = BING_ZWJQ_2;
		basedata.GongJiFW = BING_GJFW_2;
	case 3:
		basedata.GongJiLi = BING_GJL_3;
		basedata.ShengMingZhi = BING_SMZ_3;
		basedata.FangYuLi = BING_FYL_3;
		basedata.ZhenWangQ = BING_ZWJQ_3;
		basedata.ZhenWangJ = BING_ZWJQ_3;
		basedata.GongJiFW = BING_GJFW_3;
	default:
		break;
	}

	basedata.dqShengMZ = basedata.ShengMingZhi;

}

void Soldier::setTarget(int target_tag, int tar_type)
{
	basedata.dq_target.targetTag = target_tag;
	basedata.dq_target.type = tar_type;
	stopActionByTag(1);
}

void Soldier::attack(int target_tag, int tar_type)
{
	setTarget(target_tag, tar_type);
	basedata.status = ATTACK;
	Play_Animation();
}

void Soldier::move()
{
	if (basedata.dq_target.targetTag != 0 && basedata.status != ATTACK)
	{
		auto parent = getParent();
		Vec2 pos = getPosition();
		switch (basedata.dq_target.type)
		{
		case HERO:
		{
			auto target = (Heroes*)parent->getChildByTag(basedata.dq_target.targetTag);
			if (target->basedata.status == DEAD)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = 0;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
			Vec2 des = target->getPosition();
			if (pos.distance(des) > basedata.JingJieFW)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = 0;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
		}
		case SOLDIER:
		{
			auto target = (Soldier*)parent->getChildByTag(basedata.dq_target.targetTag);
			if (target->basedata.status == DEAD)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = 0;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
			Vec2 des = target->getPosition();
			if (pos.distance(des) > basedata.JingJieFW)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = 0;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
		}
		case TA:
		{
			auto target = (FangYuTa*)parent->getChildByTag(basedata.dq_target.targetTag);
			if (target->basedata.status == DEAD)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = 0;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
			Vec2 des = target->getPosition();
			if (pos.distance(des) > basedata.JingJieFW)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = 0;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
		}
		case SHUIJING:
		{
			auto target = (ShuiJing*)parent->getChildByTag(basedata.dq_target.targetTag);
			if (target->basedata.status == DEAD)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = 0;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
			Vec2 des = target->getPosition();
			if (pos.distance(des) > basedata.JingJieFW)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = 0;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
		}
		case JIDI:
		{
			auto target = (JiDi*)parent->getChildByTag(basedata.dq_target.targetTag);
			if (target->basedata.status == DEAD)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = 0;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
			Vec2 des = target->getPosition();
			if (pos.distance(des) > basedata.JingJieFW)
			{
				basedata.dq_target.targetTag = 0;
				basedata.dq_target.type = 0;
				basedata.status = 0;
				stopActionByTag(2);
				Play_Animation();
				return;
			}
		}
		default:
			break;
		}
		auto target = parent->getChildByTag(basedata.dq_target.targetTag);
		Vec2 des = target->getPosition();
		float delta_x = des.x - pos.x;
		float delta_y = des.y - pos.y;
		int Dir;
		if (delta_x > 0.0f)
		{
			if (delta_y / delta_x >= 2.414214f) Dir = 0;
			if (delta_y / delta_x < 2.414214f && delta_y / delta_x >= 0.414214f) Dir = 1;
			if (delta_y / delta_x < 0.414214f && delta_y / delta_x >= -0.414214f) Dir = 2;
			if (delta_y / delta_x < -0.414214f && delta_y / delta_x >= -2.414214f) Dir = 3;
			if (delta_y / delta_x < -2.414214f) Dir = 4;
		}
		if (delta_x < 0.0f)
		{
			if (delta_y / delta_x >= 2.414214f) Dir = 4;
			if (delta_y / delta_x < 2.414214f && delta_y / delta_x >= 0.414214f) Dir = 5;
			if (delta_y / delta_x < 0.414214f && delta_y / delta_x >= -0.414214f) Dir = 6;
			if (delta_y / delta_x < -0.414214f && delta_y / delta_x >= -2.414214f) Dir = 7;
			if (delta_y / delta_x < -2.414214f) Dir = 0;
		}
		if (delta_x == 0.0f)
		{
			if (delta_y >= 0.0f) Dir = 0;
			else Dir = 4;
		}
		if (basedata.direction != Dir || basedata.status == 0)
		{
			basedata.status = 1;
			stopActionByTag(2);
			basedata.direction = Dir;
			Play_Animation();
		}
		float dx = (basedata.YiSu / 60.0f) * delta_x / sqrt(delta_x * delta_x + delta_y * delta_y);
		float dy = (basedata.YiSu / 60.0f) * delta_y / sqrt(delta_x * delta_x + delta_y * delta_y);
		setPosition(Vec2(pos.x + dx, pos.y + dy));
		if (pos.distance(des) <= basedata.GongJiFW)
		{
			stopActionByTag(2);
			basedata.status = 2;
			Play_Animation();
		}
	}
}

void Soldier::update(int heroes, int soldiers, int buildings, int building_type)
{
	auto position1 = this->getPosition();
	auto parent = getParent();

	if (basedata.dq_target.targetTag != 0)
	{
		auto dq_target = parent->getChildByTag(basedata.dq_target.targetTag);
		auto position5 = dq_target->getPosition();
		if (position1.distance(position5) < basedata.JingJieFW)
		{
			if (position1.distance(position5) <= basedata.GongJiFW)
			{
				attack(basedata.dq_target.targetTag, basedata.dq_target.type);
			}
			else
			{
				move();
			}
			return;
		}
	}

	basedata.dq_target.targetTag = 0;
	basedata.dq_target.type = 0;

	auto dq_target_soldier = parent->getChildByTag(soldiers);
	auto dq_target_building = parent->getChildByTag(buildings);

	auto position3 = dq_target_soldier->getPosition();
	auto position4 = dq_target_building->getPosition();
	if (position1.distance(position3) > basedata.JingJieFW)
	{
		
			auto dq_target_hero = (Heroes*)parent->getChildByTag(heroes);
			if (dq_target_hero->basedata.Team != basedata.Team)
			{
				auto position2 = dq_target_hero->getPosition();
				auto d = position1.distance(position2);
				if (d < basedata.JingJieFW)
				{
					if (d <= basedata.GongJiFW)
					{
						attack(heroes, HERO);
					}
					else
					{
						setTarget(heroes, HERO);
						move();
					}
					return;
				}
			}
		

		if (position1.distance(position4) < basedata.JingJieFW)
		{
			if (position1.distance(position4) <= basedata.GongJiFW)
			{
				attack(buildings, building_type);
			}
			else
			{
				setTarget(buildings, building_type);
				move();
			}
		}
	}
	else
	{
		if (position1.distance(position3) < basedata.GongJiFW)
		{
			attack(soldiers, SOLDIER);
		}
		else
		{
			setTarget(soldiers, SOLDIER);
			move();
		}
	}
}

void Soldier::underAttack(int enemy_tag, int ene_type)
{
	auto parent = getParent();
	switch (ene_type)
	{
	case HERO:
	{
		auto enemy = (Heroes*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	case SOLDIER:
	{
		auto enemy = (Soldier*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	case TA:
	{
		auto enemy = (FangYuTa*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	default:
		break;
	}
}

bool Soldier::dead(int enemy_tag, int ene_type)
{
	if (basedata.dqShengMZ > 0)
	{
		basedata.is_dead = 0;
		return basedata.is_dead;
	}
	basedata.is_dead = 1;
	basedata.status = DEAD;
	if (ene_type == HERO)//may
	{
		auto parent = getParent();
		auto enemy = (Heroes*)parent->getChildByTag(enemy_tag);
		enemy->basedata.ChiYouQ += basedata.ZhenWangQ;
		enemy->basedata.ChiYouJ += basedata.ZhenWangJ;
		if (enemy->basedata.ChiYouJ > enemy->basedata.Level*SJ_SXJY&&enemy->basedata.Level < 20)
		{
			enemy->level_up();
		}
	}
	stopAllActions();
	Play_Animation();
	return basedata.is_dead;
}

void ShuiJing::setShuiJingProperty(int team, int lu, int tag)
{
	basedata.ShengMingZhi = SJ_SMZ;
	basedata.FangYuLi = SJ_FYL;
	basedata.ZhenWangQ = SJ_ZWJQ;
	basedata.Team = team;
	the_lu = lu;
	basedata.dqShengMZ = basedata.ShengMingZhi;
	basedata.type = SHUIJING;
	basedata.Tag = tag;
}

void ShuiJing::underAttack(int enemy_tag, int ene_type)
{
	auto parent = getParent();
	switch (ene_type)
	{
	case HERO:
	{
		auto enemy = (Heroes*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	case SOLDIER:
	{
		auto enemy = (Soldier*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	default:
		break;
	}
}

bool ShuiJing::dead(int enemy_tag, int ene_type)
{
	if (basedata.dqShengMZ > 0)
	{
		basedata.is_dead = 0;
		return basedata.is_dead;
	}
	basedata.is_dead = 1;
	basedata.status = DEAD;
	if (ene_type == HERO)//may
	{
		auto parent = getParent();
		auto enemy = (Heroes*)parent->getChildByTag(enemy_tag);
		enemy->basedata.ChiYouQ += basedata.ZhenWangQ;
		enemy->basedata.ChiYouJ += basedata.ZhenWangJ;
		if (enemy->basedata.ChiYouJ > enemy->basedata.Level*SJ_SXJY&&enemy->basedata.Level < 20)
		{
			enemy->level_up();
		}
	}
	stopAllActions();
	Play_Animation();
	return basedata.is_dead;
}

void JiDi::setJiDiProperty(int team, int tag)
{
	basedata.ShengMingZhi = JD_SMZ;
	basedata.FangYuLi = JD_FYL;
	basedata.Team = team;
	basedata.dqShengMZ = basedata.ShengMingZhi;
	basedata.type = JIDI;
}

void JiDi::boost(ShuiJing* shuijing)
{
	if (shuijing->basedata.is_dead = 0)
		boost_lu[shuijing->the_lu] = 0;
	else
		boost_lu[shuijing->the_lu] = 1;
}

bool JiDi::whetherBoost(int lu)
{
	return boost_lu[lu];
}

void JiDi::underAttack(int enemy_tag, int ene_type)
{
	auto parent = getParent();
	switch (ene_type)
	{
	case HERO:
	{
		auto enemy = (Heroes*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	case SOLDIER:
	{
		auto enemy = (Soldier*)parent->getChildByTag(enemy_tag);
		if (enemy->basedata.Team != basedata.Team)
		{
			auto jianShang = 100 / (100 + basedata.FangYuLi);
			basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
			if (basedata.dqShengMZ <= 0)
			{
				dead(enemy_tag, ene_type);
			}
		}
		break;
	}
	default:
		break;
	}
}

bool JiDi::dead(int enemy_tag, int ene_type)
{
	if (basedata.dqShengMZ > 0)
	{
		basedata.is_dead = 0;
		return basedata.is_dead;
	}
	basedata.is_dead = 1;
	basedata.status = DEAD;
	if (ene_type == HERO)//may
	{
		auto parent = getParent();
		auto enemy = (Heroes*)parent->getChildByTag(enemy_tag);
		enemy->basedata.ChiYouQ += basedata.ZhenWangQ;
		enemy->basedata.ChiYouJ += basedata.ZhenWangJ;
		if (enemy->basedata.ChiYouJ > enemy->basedata.Level*SJ_SXJY&&enemy->basedata.Level < 20)
		{
			enemy->level_up();
		}
	}
	stopAllActions();
	Play_Animation();
	return basedata.is_dead;
}

void YeGuai::setYeGuaiProperty(int tag, int the_type)
{
	basedata.Level = 1;
	basedata.Tag = tag;
	basedata.FangYuLi = YG_FYL + basedata.Level*YG_FYL_CZ;
	basedata.ShengMingZhi = YG_SMZ + basedata.Level*YG_SMZ_CZ;
	basedata.GongJiLi = YG_GJL + basedata.Level*YG_GJL_CZ;
	basedata.ZhenWangJ = YG_ZWJY + YG_ZWJY_CZ * basedata.Level;
	basedata.ZhenWangQ = YG_ZWJQ + YG_ZWJQ_CZ * basedata.Level;
	basedata.GongSu = YG_GS;
	basedata.YiSu = YG_YS;
	basedata.GongJiFW = YG_GJFW;
	basedata.JingJieFW = YG_JJFW;
	basedata.dqShengMZ = basedata.ShengMingZhi;
	basedata.type = YEGUAI;
}

void YeGuai::underAttack(int enemy_tag, int ene_type)
{
	if (is_active = 0)
	{
		is_active = 1;
		setTarget(enemy_tag, ene_type);
		move();
	}

	auto parent = getParent();
	auto enemy = (Heroes*)parent->getChildByTag(enemy_tag);

	auto jianShang = 100 / (100 + basedata.FangYuLi);
	basedata.dqShengMZ -= (int)jianShang*enemy->basedata.GongJiLi;
	if (basedata.dqShengMZ <= 0)
	{
		dead(enemy_tag, ene_type);
	}
}

bool YeGuai::dead(int enemy_tag, int ene_type)
{
	if (basedata.dqShengMZ > 0)
	{
		basedata.is_dead = 0;
		return basedata.is_dead;
	}
	basedata.is_dead = 1;
	basedata.status = DEAD;
	auto parent = getParent();
	auto enemy = (Heroes*)parent->getChildByTag(enemy_tag);
	enemy->basedata.ChiYouQ += basedata.ZhenWangQ;
	enemy->basedata.ChiYouJ += basedata.ZhenWangJ;
	if (enemy->basedata.ChiYouJ > enemy->basedata.Level*SJ_SXJY&&enemy->basedata.Level < 20)
	{
		enemy->level_up();
	}
	stopAllActions();
	Play_Animation();
	return basedata.is_dead;
}

void YeGuai::setTarget(int target_tag, int tar_type)
{
	basedata.dq_target.targetTag = target_tag;
	basedata.dq_target.type = tar_type;
	stopActionByTag(1);
}


bool YeGuai::arrived()
{
	Vec2 position = getPosition();
	if (position == basedata.destination && basedata.arrive == false)
	{
		stopAllActions();
		basedata.status = STAND;
		Play_Animation();
		basedata.arrive = true;
	}
	return basedata.arrive;
}

void YeGuai::move()
{

}

void Soldier::Play_Animation()
{
	std::string Status, dir;
	auto cache = SpriteFrameCache::sharedSpriteFrameCache();
	switch (basedata.direction)
	{
	case 0: dir = "/up.plist"; break;
	case 1: dir = "/up_right.plist"; break;
	case 2: dir = "/right.plist"; break;
	case 3: dir = "/down_right.plist"; break;
	case 4: dir = "/down.plist"; break;
	case 5: dir = "/down_left.plist"; break;
	case 6: dir = "/left.plist"; break;
	case 7: dir = "/up_left.plist"; break;
	}
	switch (basedata.status)
	{
	case 0: Status = "/stand"; break;
	case 1: Status = "/move"; break;
	case 2: Status = "/attack"; break;
	case 3: Status = "/death"; break;
	}
	cache->addSpriteFramesWithFile(basedata.file_name + Status + dir);
	Vector<SpriteFrame*> frames;
	frames.reserve(6);
	char str[20];
	for (int i = 1; i < 7; i++)
	{
		sprintf(str, "%d.png", i);
		auto frame = cache->spriteFrameByName(str);
		frames.pushBack(frame);
	}
	auto animation = Animation::createWithSpriteFrames(frames, 0.15f);
	auto action = Animate::create(animation);
	if (basedata.status == STAND || basedata.status == MOVE)
	{
		auto repeat = RepeatForever::create(action);
		repeat->setTag(2);
		this->runAction(repeat);
	}
	if (basedata.status == ATTACK)
	{
		auto callbackFunc = [&]()
		{
			int tar_type = basedata.dq_target.type;
			switch (tar_type)
			{
			case HERO:
			{
				auto parent = getParent();
				auto target = (Heroes*)parent->getChildByTag(basedata.dq_target.targetTag);
				basedata.status = 0;
				target->underAttack(basedata.Tag, basedata.type);
				break;
			}
			case SOLDIER:
			{
				auto parent = getParent();
				auto target = (Soldier*)parent->getChildByTag(basedata.dq_target.targetTag);
				basedata.status = 0;
				target->underAttack(basedata.Tag, basedata.type);
				break;
			}
			case TA:
			{
				auto parent = getParent();
				auto target = (FangYuTa*)parent->getChildByTag(basedata.dq_target.targetTag);
				basedata.status = 0;
				target->underAttack(basedata.Tag, basedata.type);
				break;
			}
			case SHUIJING:
			{
				auto parent = getParent();
				auto target = (ShuiJing*)parent->getChildByTag(basedata.dq_target.targetTag);
				basedata.status = 0;
				target->underAttack(basedata.Tag, basedata.type);
				break;
			}
			case JIDI:
			{
				auto parent = getParent();
				auto target = (JiDi*)parent->getChildByTag(basedata.dq_target.targetTag);
				basedata.status = 0;
				target->underAttack(basedata.Tag, basedata.type);
				break;
			}
			case YEGUAI:
			{
				auto parent = getParent();
				auto target = (YeGuai*)parent->getChildByTag(basedata.dq_target.targetTag);
				basedata.status = 0;
				target->underAttack(basedata.Tag, basedata.type);
				break;
			}
			default:
				break;
			}
		};
		CallFunc *callFunc = CallFunc::create(callbackFunc);
		Action *actions = Sequence::create(action, callFunc, NULL);
		actions->setTag(2);
		this->runAction(actions);
	}
	if (basedata.status == DEAD)
	{
		auto callbackFunc1 = [&]()
		{
			setVisible(false);
		};
		auto callbackFunc2 = [&]()
		{
			basedata.status = 0;
			basedata.dqShengMZ = basedata.ShengMingZhi;
			setVisible(true);
		};
		CallFunc *callFunc1 = CallFunc::create(callbackFunc1);
		CallFunc *callFunc2 = CallFunc::create(callbackFunc2);
		auto delay = DelayTime::create(5);
		Action *actions = Sequence::create(action, callFunc1, delay, callFunc2, NULL);
		this->runAction(actions);
	}
	cache->removeSpriteFramesFromFile(basedata.file_name + Status + dir);
}

void YeGuai::Play_Animation()
{

}

void FangYuTa::Play_Animation()
{

}

void ShuiJing::Play_Animation()
{

}

void JiDi::Play_Animation()
{

}

void Heroes::level_up()
{
	basedata.Level += 1;
	basedata.ShengMingZhi += HERO_SMZ_1_CZ;
	basedata.FangYuLi += HERO_FYL_1_CZ;
	basedata.GongJiLi += HERO_GJL_1_CZ;
	basedata.dqShengMZ += HERO_SMZ_1_CZ;
}

void YeGuai::level_up()
{
	basedata.Level += 1;
	basedata.ShengMingZhi += HERO_SMZ_1_CZ;
	basedata.FangYuLi += HERO_FYL_1_CZ;
	basedata.GongJiLi += HERO_GJL_1_CZ;
}

void Soldier::level_up()
{
	basedata.Level += 1;
	basedata.ShengMingZhi += BING_SMZ_1_CZ;
	basedata.FangYuLi += BING_FYL_1_CZ;
	basedata.GongJiLi += BING_GJL_1_CZ;
}

SkillsManager::SkillsManager(int the_id)
{
	id = the_id;

	switch (id)
	{
	case SABER_SKILL:
	{
		skill1.buff.boost = SABER_SKILL_1_BOOST;
		skill1.buff.theTime = SABER_SKILL_1_TIME;
		skill1.cd = SABER_SKILL_1_CD;
		skill1.buff.boost_type = BOOST_TYPE_YISU;
		skill2.buff.boost = SABER_SKILL_2_BOOST;
		skill2.buff.theTime = SABER_SKILL_2_TIME;
		skill2.cd = SABER_SKILL_2_CD;
		skill2.buff.boost_type = BOOST_TYPE_FANGYULI;
		skill3.effect_fw = SABER_SKILL_3_FW;
		skill3.damage = SABER_SKILL_3_DAMAGE;
		skill3.cd = SABER_SKILL_3_CD;
	}
	case ARCHER_SKILL:
	{
		skill1.buff.boost = ARCHER_SKILL_1_BOOST;
		skill1.buff.theTime = ARCHER_SKILL_1_TIME;
		skill1.cd = ARCHER_SKILL_1_CD;
		skill2.damage = ARCHER_SKILL_2_DAMAGE;
		skill2.enemy_debuff.boost = ARCHER_SKILL_2_DEBOOST;
		skill2.enemy_debuff.theTime = ARCHER_SKILL_2_TIME;
		skill2.enemy_debuff.boost_type = BOOST_TYPE_YISU;
		skill2.cd = ARCHER_SKILL_2_CD;
		skill2.caste_fw = ARCHER_SKILL_2_FW;
		skill3.caste_fw = ARCHER_SKILL_3_CASTFW;
		skill3.cd = ARCHER_SKILL_3_CD;
	}
	case WIZARD_SKILL:
	{
		skill1.caste_fw = WIZARD_SKILL_1_CASTFW;
		skill1.cd = WIZARD_SKILL_1_CD;
		skill1.damage = WIZARD_SKILL_1_DAMAGE;
		skill1.effect_fw = WIZARD_SKILL_1_FW;
		skill2.enemy_debuff.boost = WIZARD_SKILL_2_DEBOOST;
		skill2.enemy_debuff.theTime = WIZARD_SKILL_2_TIME;
		skill2.enemy_debuff.boost_type = BOOST_TYPE_YISU;
		skill2.cd = WIZARD_SKILL_2_CD;
		skill2.caste_fw = WIZARD_SKILL_2_CASTFW;
		skill2.damage = WIZARD_SKILL_2_DAMAGE;
		skill3.caste_fw = WIZARD_SKILL_3_CASTFW;
		skill3.cd = WIZARD_SKILL_3_CD;
		skill3.damage = WIZARD_SKILL_3_DAMAGE;
	}
	default:
		break;
	}
}

bool SkillsManager::check_cd(char key)
{
	clock_t now = clock();
	switch (key)
	{
	case 'q':
	{
		if (now - skill1.lasttime > skill1.cd)
			return true;
		break;
	}
	case 'w':
	{
		if (now - skill2.lasttime > skill2.cd)
			return true;
		break;
	}
	case 'e':
	{
		if (now - skill2.lasttime > skill2.cd)
			return true;
		break;
	}
	}
	return false;
}

void SkillsManager::makeBuffSkill(char key, Heroes* caster)
{
	Skill the_skill;
	switch (key)
	{
	case 'q':
		the_skill = skill1;
		break;
	case 'w':
		the_skill = skill2;
		break;
	}
	caster->skillBuff = the_skill.buff;
	caster->gotBuff();
}

