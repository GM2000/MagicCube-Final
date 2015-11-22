#pragma once

#include "MagicCube.h"

struct location
{
	float X;
	float Y;
	float Z;

	double XRot;
	double YRot;
};
class mob
{
public:
	location MobLocation;
	double Speed;
	mob()
	{
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

	mob* addMob()
	{
		Mob.push_back(mob());
		return &Mob[Mob.size() - 1];
	}
};

extern mobs Mob;