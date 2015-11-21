
#include "Render.h"

#include "Mob.h"

mobs Mobs;

void KeyBoardCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_1)
	{
		Mobs.Mob[0].MobLocation.YRot += 0.1;
		Mobs.Mob[0].MobLocation.XRot += 0.1;
	}
	if (key == GLFW_KEY_2)
	{
		Mobs.Mob[0].MobLocation.Z -= 0.1;
	}
	if (key == GLFW_KEY_3)
	{
		Mobs.Mob[0].MobLocation.XRot += 0.1;
	}
	GobalTranslate = glm::translate(glm::mat4(), glm::vec3(Mobs.Mob[0].MobLocation.X, Mobs.Mob[0].MobLocation.Y, Mobs.Mob[0].MobLocation.Z));
	GobalRotate = glm::rotate_slow(glm::mat4(), Mobs.Mob[0].MobLocation.XRot, glm::vec3(1.0f, 0.0f, 0.0f)) * glm::rotate_slow(glm::mat4(), Mobs.Mob[0].MobLocation.YRot, glm::vec3(0.0f, 1.0f, 0.0f));
}