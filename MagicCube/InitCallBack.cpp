
#include "MagicCube.h"

void windowResizeCallBack	(GLFWwindow* window, int WindowsWidth, int WindowsHeight);
void KeyBoardCallBack		(GLFWwindow* window, int key, int scancode, int action, int mods);
void MouseCallBack			(GLFWwindow* Window, double XPos, double YPos);

void initCallBack()
{
	glfwSetWindowSizeCallback(window,windowResizeCallBack);
	glfwSetKeyCallback(window, KeyBoardCallBack);
	glfwSetCursorPosCallback(window, MouseCallBack);
}