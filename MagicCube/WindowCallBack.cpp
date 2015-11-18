
#include "Render.h"

glm::mat4 Projection;

void windowResizeCallBack(GLFWwindow* window, int WindowsWidth, int WindowsHeight)
{
	if (Screen.getSize() > 0)
	{
		if (WindowsWidth > WindowsHeight)
		{
			Screen.enableScreen(1);
			Screen.getScreen()->getRenderGroup(0)->IsEnable = true;
		}
		else if (WindowsWidth < 150)
		{
			Screen.enableScreen(0);
			Screen.getScreen()->getRenderGroup(0)->IsEnable = true;
		}
		else {
			Screen.getScreen()->getRenderGroup(0)->IsEnable = false;
		}
	}
	glViewport(0, 0, WindowsWidth, WindowsHeight);

	Projection = glm::perspective(45.0f, (GLfloat)WindowsWidth / (GLfloat)WindowsHeight, 0.1f, 500.0f);
}