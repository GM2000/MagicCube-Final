
#include "Screen.h"

glm::mat4 Projection = glm::perspective(45.0f, (GLfloat)640 / (GLfloat)480, 0.1f, 500.0f);

void windowResizeCallBack(GLFWwindow* window, int WindowsWidth, int WindowsHeight)
{
	glViewport(0, 0, WindowsWidth, WindowsHeight);

	Projection = glm::perspective(45.0f, (GLfloat)WindowsWidth / (GLfloat)WindowsHeight, 0.1f, 500.0f);
}