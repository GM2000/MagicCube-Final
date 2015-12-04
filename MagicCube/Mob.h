#pragma once

#include "MagicCube.h"

class mob;
//生物基本信息
typedef void(*refreshMob)(mob*);
typedef void(*renderMob)(mob*);

//生物基本信息（渲染，移动等）
struct mobType
{
	refreshMob RefreshMob;
	renderMob  RenderMob;
};

//生物坐标
struct location
{
	float X;
	float Y;
	float Z;

	double XRot;
	double YRot;
};

//储存一个生物
class mob
{
	friend class mobs;

	refreshMob RefreshMob;
	renderMob  RenderMob;
public:
	location   MobLocation;

	double Speed;
	double LastMoveTime=glfwGetTime();

	//初始化生物
	mob(refreshMob RefreshMob,renderMob  RenderMob)
	{
		mob::RefreshMob = RefreshMob;
		mob::RenderMob  = RenderMob;

		MobLocation.X = 0;
		MobLocation.Y = 0;
		MobLocation.Z = 0;

		MobLocation.XRot = 0;
		MobLocation.YRot = 0;

		Speed = 1;
	}
};

class mobs
{

public:
	std::vector<mob> Mob;

	//刷新所有生物位置
	void refreshMobs()
	{
		for (unsigned int i = 0; i < Mob.size(); i++)
		{
			Mob[i].RefreshMob(&Mob[i]);
		}
	}
	//添加生物
	mob* addMob(mobType ModType)
	{
		Mob.push_back(mob(ModType.RefreshMob, ModType.RenderMob));
		return &Mob[Mob.size() - 1];
	}
};

extern mobs Mob;
extern std::vector<mobType> MobType;