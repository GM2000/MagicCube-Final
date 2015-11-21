
#include "MagicCube.h"

extern GLFWwindow* window;

void windowResizeCallBack	(GLFWwindow* window, int WindowsWidth, int WindowsHeight);
void KeyBoardCallBack		(GLFWwindow* window, int key, int scancode, int action, int mods);

void initCallBack()
{
	glfwSetWindowSizeCallback(window,windowResizeCallBack);
	glfwSetKeyCallback(window, KeyBoardCallBack);
}