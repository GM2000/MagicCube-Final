#pragma once

const double PI = 3.141592653589793238462;

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

		LastMoveTime = glfwGetTime();

		if (Keys[GLFW_KEY_W])
		{
			HasChange = true;
			PlayerMob->MobLocation.X -= sin(PlayerMob->MobLocation.XRot * (PI / 180)) * PlayerMob->Speed * FromLastTime;
			PlayerMob->MobLocation.Z += cos(PlayerMob->MobLocation.XRot * (PI / 180)) * PlayerMob->Speed * FromLastTime;
		}
		if (Keys[GLFW_KEY_S])
		{
			HasChange = true;
			PlayerMob->MobLocation.X += sin(PlayerMob->MobLocation.XRot * (PI / 180)) * PlayerMob->Speed * FromLastTime;
			PlayerMob->MobLocation.Z -= cos(PlayerMob->MobLocation.XRot * (PI / 180)) * PlayerMob->Speed * FromLastTime;
		}
		if (Keys[GLFW_KEY_A])
		{
			HasChange = true;
			PlayerMob->MobLocation.X += cos(PlayerMob->MobLocation.XRot * (PI / 180)) * PlayerMob->Speed * FromLastTime;
			PlayerMob->MobLocation.Z += sin(PlayerMob->MobLocation.XRot * (PI / 180)) * PlayerMob->Speed * FromLastTime;
		}
		if (Keys[GLFW_KEY_D])
		{
			HasChange = true;
			PlayerMob->MobLocation.X += cos((PlayerMob->MobLocation.XRot + 180) * (PI / 180)) * PlayerMob->Speed * FromLastTime;
			PlayerMob->MobLocation.Z += sin((PlayerMob->MobLocation.XRot + 180) * (PI / 180)) * PlayerMob->Speed * FromLastTime;
		}
		if (HasChange)
		{
			GobalTranslate = glm::translate(glm::mat4(), glm::vec3(PlayerMob->MobLocation.X, PlayerMob->MobLocation.Y, PlayerMob->MobLocation.Z));
			GobalRotate = glm::rotate_slow(glm::mat4(), PlayerMob->MobLocation.XRot, glm::vec3(1.0f, 0.0f, 0.0f)) * glm::rotate_slow(glm::mat4(), PlayerMob->MobLocation.YRot, glm::vec3(0.0f, 1.0f, 0.0f));
		}
	}
	void bindMob(mob* Mob)
	{
		PlayerMob = Mob;
	}
};

extern player Player;