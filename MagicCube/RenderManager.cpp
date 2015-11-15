
#include "Render.h"

GLFWwindow* window;

void initShaders();

int initGL()
{
	//初始化GLFW
	if (!glfwInit())
		return -1;

	//创建窗口
	window = glfwCreateWindow(640, 480, "TEST", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -2;
	}

	//让窗体环境正确
	glfwMakeContextCurrent(window);

	//初始化GLEW
	if (glewInit() != GLEW_OK)
		return -3;

	initShaders();

	return true;
}
int renderMainLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		//渲染

		//交换缓存
		glfwSwapBuffers(window); 

		//处理用户交互
		glfwPollEvents();
	}
	//结束
	glfwTerminate();

	return 0;
}