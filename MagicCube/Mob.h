#pragma once

#include "MagicCube.h"

class mob;
//生物基本信息
typedef bool(*refreshMob)(mob*);
typedef void(*renderMob)(mob*);

//生物基本信息（渲染，移动等）
struct mobType
{
	mobType(refreshMob RefreshMob,renderMob RenderMob)
	{
		mobType::RefreshMob = RefreshMob;
		mobType::RenderMob = RenderMob;
	}
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
			//警告！这里可能会有错误发生！
			if (Mob[i].RefreshMob(&Mob[i]))
			{
				Camera.writeGobalTranslate(&(glm::translate(glm::mat4(), glm::vec3(Mob[i].MobLocation.X, Mob[i].MobLocation.Y, Mob[i].MobLocation.Z))));
				Camera.writeGobalRotate(&(glm::rotate_slow(glm::mat4(), (float)Mob[i].MobLocation.XRot, glm::vec3(1.0f, 0.0f, 0.0f)) * glm::rotate(glm::mat4(), (float)Mob[i].MobLocation.YRot, glm::vec3(0.0f, 1.0f, 0.0f))));
			}
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