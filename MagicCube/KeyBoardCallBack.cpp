
#include "Render.h"

#include "Player.h"

bool Keys[512] = { false };

void KeyBoardCallBack(GLFWwindow* Window, int Key, int Scancode, int Action, int Mods)
{
	if (Action == GLFW_PRESS)
	{
		Keys[Key] = true;
	}else if (Action == GLFW_RELEASE)
	{
		Keys[Key] = false;
	}
}