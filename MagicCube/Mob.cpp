
#include "Render.h"
#include "Mob.h"
#include <iostream>

mobs Mob;

std::vector<mobType> MobType;

unsigned int Mob_Player;

const double PI = 3.141592653589793238462;

double MouseSpeed = 50.0;

//移动玩家并且返回是否移动
bool playerRefresh(mob* Mob)
{
	bool HasChange = false;

	double FromLastTime = (glfwGetTime() - Mob->LastMoveTime);

	double MouseXMove;
	double MouseYMove;

	float MouseCenterX;
	float MouseCenterY;

	MouseCenterX = WindowWidth * 0.5f;
	MouseCenterY = WindowHeight	* 0.5f;

	MouseXMove = Mouse.X - MouseCenterX;
	MouseYMove = Mouse.Y - MouseCenterY;

	if (MouseYMove<0)
	{
		MouseYMove = -MouseYMove;
		Mob->MobLocation.XRot -= (float)(asin(MouseYMove * 0.0001) * MouseSpeed * FromLastTime * 1000.0);
	}
	else {
		Mob->MobLocation.XRot += (float)(asin(MouseYMove * 0.0001) * MouseSpeed * FromLastTime * 1000.0);
	}

	if (MouseXMove<0)
	{
		MouseXMove = -MouseXMove;
		Mob->MobLocation.YRot -= (float)(asin(MouseXMove * 0.0001) * MouseSpeed * FromLastTime * 1000.0);
	}
	else {
		Mob->MobLocation.YRot += (float)(asin(MouseXMove * 0.0001) * MouseSpeed * FromLastTime * 1000.0);
	}
	if (Mob->MobLocation.XRot / (PI / 180) > 90)
	{
		Mob->MobLocation.XRot = 90 * (PI / 180);
	}
	if (Mob->MobLocation.XRot / (PI / 180) < -90)
	{
		Mob->MobLocation.XRot = -90 * (PI / 180);
	}
	if ((!MouseXMove == 0) || (!MouseYMove == 0))
	{
		glfwSetCursorPos(window, MouseCenterX, MouseCenterY);

		HasChange = true;
	}

	if (Keys[GLFW_KEY_W])
	{
		HasChange = true;
		Mob->MobLocation.X -= (float)(sin(Mob->MobLocation.YRot) * Mob->Speed * FromLastTime);
		Mob->MobLocation.Z += (float)(cos(Mob->MobLocation.YRot) * Mob->Speed * FromLastTime);
	}
	if (Keys[GLFW_KEY_S])
	{
		HasChange = true;
		Mob->MobLocation.X += (float)(sin(Mob->MobLocation.YRot) * Mob->Speed * FromLastTime);
		Mob->MobLocation.Z -= (float)(cos(Mob->MobLocation.YRot) * Mob->Speed * FromLastTime);
	}
	if (Keys[GLFW_KEY_A])
	{
		HasChange = true;
		Mob->MobLocation.X += (float)(cos(Mob->MobLocation.YRot) * Mob->Speed * FromLastTime);
		Mob->MobLocation.Z += (float)(sin(Mob->MobLocation.YRot) * Mob->Speed * FromLastTime);
	}
	if (Keys[GLFW_KEY_D])
	{
		HasChange = true;
		Mob->MobLocation.X -= (float)(cos((Mob->MobLocation.YRot)) * Mob->Speed * FromLastTime);
		Mob->MobLocation.Z -= (float)(sin((Mob->MobLocation.YRot)) * Mob->Speed * FromLastTime);
	}
	Mob->LastMoveTime = glfwGetTime();

	return HasChange;
}

void playerRender(mob* Mob)
{
}

void initMob()
{
	//玩家
	Mob_Player = MobType.size();
	MobType.push_back(mobType(playerRefresh, playerRender));
}