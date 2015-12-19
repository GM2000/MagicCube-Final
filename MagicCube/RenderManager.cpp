
#include "Screen.h"
#include "Render.h"

camera Camera;

GLFWwindow* window;

screens Screen;

void initCallBack();
void initShader();

int initGL()
{
	//初始化GLFW
	if (!glfwInit())
		return -1;

	//创建窗口
	window = glfwCreateWindow(640, 480, "Magic Cube", NULL, NULL);

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

	initShader();
	initCallBack();

	//初始化Opengl的一些东西
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);

	glfwSetWindowSize(window, 870, 512);
	
	return true;
}
int renderMainLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		//渲染
		Screen.drawScreen();
		//交换缓存
		glfwSwapBuffers(window); 

		//处理用户交互
		glfwPollEvents();
	}
	//结束
	glfwTerminate();

	return 0;
}