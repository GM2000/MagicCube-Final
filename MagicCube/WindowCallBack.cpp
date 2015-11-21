
#include "Screen.h"

void windowResizeCallBack(GLFWwindow* window, int WindowsWidth, int WindowsHeight)
{
	glViewport(0, 0, WindowsWidth, WindowsHeight);

	GobalProjection = glm::perspective(45.0f, (GLfloat)WindowsWidth / (GLfloat)WindowsHeight, 0.1f, 500.0f);
}