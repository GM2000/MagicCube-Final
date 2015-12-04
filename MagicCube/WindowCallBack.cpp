
#include "Screen.h"

int WindowWidth;
int WindowHeight;

void windowResizeCallBack(GLFWwindow* Window, int WindowsWidth, int WindowsHeight)
{
	glViewport(0, 0, WindowsWidth, WindowsHeight);

	WindowWidth		= WindowsWidth;
	WindowHeight	= WindowsHeight;

	GobalMat.GobalProjection = glm::perspective(45.0f, (GLfloat)WindowsWidth / (GLfloat)WindowsHeight, 0.1f, 500.0f);
}