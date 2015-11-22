#pragma once

const float PI = 3.141592653589793238462f;
const double MouseSpeed = 50.0;

#include "Mob.h"
#include "Render.h"

class player
{
	mob* PlayerMob = NULL;

	double LastMoveTime = glfwGetTime();
public:
	mob* getPlayerMob()
	{
		return PlayerMob;
	}
	void playerMove()
	{
		bool HasChange = false;

		double FromLastTime = glfwGetTime() - LastMoveTime;

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
			PlayerMob->MobLocation.XRot -= (float)(asin(MouseYMove * 0.0001) * MouseSpeed * FromLastTime * 5000);
		}
		else {
			PlayerMob->MobLocation.XRot += (float)(asin(MouseYMove * 0.0001) * MouseSpeed * FromLastTime * 5000);
		}

		if (MouseXMove<0)
		{
			MouseXMove = -MouseXMove;
			PlayerMob->MobLocation.YRot -= (float)(asin(MouseXMove * 0.0001) * MouseSpeed * FromLastTime * 5000);
		}
		else {
			PlayerMob->MobLocation.YRot += (float)(asin(MouseXMove * 0.0001) * MouseSpeed * FromLastTime * 5000);
		}
		if (PlayerMob->MobLocation.XRot / (PI / 180) > 90)
		{
			PlayerMob->MobLocation.XRot = 90 * (PI / 180);
		}
		if (PlayerMob->MobLocation.XRot / (PI / 180) < -90)
		{
			PlayerMob->MobLocation.XRot = -90 * (PI / 180);
		}
		if ((!MouseXMove == 0) || (!MouseYMove == 0))
		{
			glfwSetCursorPos(window, MouseCenterX, MouseCenterY);

			HasChange = true;
		}

		LastMoveTime = glfwGetTime();

		if (Keys[GLFW_KEY_W])
		{
			HasChange = true;
			PlayerMob->MobLocation.X -= (float)(sin(PlayerMob->MobLocation.YRot) * PlayerMob->Speed * FromLastTime);
			PlayerMob->MobLocation.Z += (float)(cos(PlayerMob->MobLocation.YRot) * PlayerMob->Speed * FromLastTime);
		}
		if (Keys[GLFW_KEY_S])
		{
			HasChange = true;
			PlayerMob->MobLocation.X += (float)(sin(PlayerMob->MobLocation.YRot) * PlayerMob->Speed * FromLastTime);
			PlayerMob->MobLocation.Z -= (float)(cos(PlayerMob->MobLocation.YRot) * PlayerMob->Speed * FromLastTime);
		}
		if (Keys[GLFW_KEY_A])
		{
			HasChange = true;
			PlayerMob->MobLocation.X += (float)(cos(PlayerMob->MobLocation.YRot) * PlayerMob->Speed * FromLastTime);
			PlayerMob->MobLocation.Z += (float)(sin(PlayerMob->MobLocation.YRot) * PlayerMob->Speed * FromLastTime);
		}
		if (Keys[GLFW_KEY_D])
		{
			HasChange = true;
			PlayerMob->MobLocation.X -= (float)(cos((PlayerMob->MobLocation.YRot)) * PlayerMob->Speed * FromLastTime);
			PlayerMob->MobLocation.Z -= (float)(sin((PlayerMob->MobLocation.YRot)) * PlayerMob->Speed * FromLastTime);
		}
		if (HasChange)
		{
			GobalTranslate = glm::translate(glm::mat4(), glm::vec3(PlayerMob->MobLocation.X, PlayerMob->MobLocation.Y, PlayerMob->MobLocation.Z));
			GobalRotate = glm::rotate_slow(glm::mat4(), (float)PlayerMob->MobLocation.XRot, glm::vec3(1.0f, 0.0f, 0.0f)) * glm::rotate(glm::mat4(), (float)PlayerMob->MobLocation.YRot, glm::vec3(0.0f, 1.0f, 0.0f));
		}
	}
	void bindMob(mob* Mob)
	{
		PlayerMob = Mob;
	}
};

extern player Player;