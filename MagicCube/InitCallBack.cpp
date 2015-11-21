
#include "MagicCube.h"

extern GLFWwindow* window;

void windowResizeCallBack(GLFWwindow* window, int WindowsWidth, int WindowsHeight);

void initCallBack()
{
	glfwSetWindowSizeCallback(window,windowResizeCallBack);
}