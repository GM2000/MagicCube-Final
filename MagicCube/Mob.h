#pragma once

#include "MagicCube.h"

struct location
{
	float X;
	float Y;
	float Z;

	float XRot;
	float YRot;
};
class mob
{
public:
	location MobLocation;
	mob()
	{
		MobLocation.X = 0;
		MobLocation.Y = 0;
		MobLocation.Z = 0;
		MobLocation.XRot = 0;
		MobLocation.YRot = 0;
	}
};
class mobs
{

public:
	std::vector<mob> Mob;
	mobs()
	{
		Mob.push_back(mob());
	}
	void addMob()
	{
		Mob.push_back(mob());
	}
};