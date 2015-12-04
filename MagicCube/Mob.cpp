
#include "Render.h"
#include "Mob.h"

mobs Mob;

std::vector<mobType> MobType;

const unsigned int Mob_Player = 0;

const double PI = 3.141592653589793238462;

double MouseSpeed = 50.0;

void playerRefresh(mob* Mob)
{
	bool HasChange = false;

	double FromLastTime = (glfwGetTime() - Mob->LastMoveTime) * 10;

	double MouseXMove;
	double MouseYMove;

	float MouseCenterX;
	float MouseCenterY;

	MouseCenterX = WindowWidth * 0.5f;
	MouseCenterY = WindowHeight * 0.5f;

	MouseXMove = Mouse.X - MouseCenterX;
	MouseYMove = Mouse.Y - MouseCenterY;

	if (MouseYMove<0)
	{
		MouseYMove = -MouseYMove;
		Mob->MobLocation.XRot -= (float)(asin(MouseYMove * 0.0001) * MouseSpeed * FromLastTime * 5000);
	}
	else {
		Mob->MobLocation.XRot += (float)(asin(MouseYMove * 0.0001) * MouseSpeed * FromLastTime * 5000);
	}

	if (MouseXMove<0)
	{
		MouseXMove = -MouseXMove;
		Mob->MobLocation.YRot -= (float)(asin(MouseXMove * 0.0001) * MouseSpeed * FromLastTime * 5000);
	}
	else {
		Mob->MobLocation.YRot += (float)(asin(MouseXMove * 0.0001) * MouseSpeed * FromLastTime * 5000);
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
	if (HasChange)
	{
		GobalMat.writeGobalTranslate(&(glm::translate(glm::mat4(), glm::vec3(Mob->MobLocation.X, Mob->MobLocation.Y, Mob->MobLocation.Z))));
		GobalMat.writeGobalRotate(&(glm::rotate_slow(glm::mat4(), (float)Mob->MobLocation.XRot, glm::vec3(1.0f, 0.0f, 0.0f)) * glm::rotate(glm::mat4(), (float)Mob->MobLocation.YRot, glm::vec3(0.0f, 1.0f, 0.0f))));
	}

	Mob->LastMoveTime = glfwGetTime();
}

void initMob()
{
	MobType.resize(1);
	MobType[Mob_Player].RefreshMob = playerRefresh;
}