
#include <thread>
#include "World.h"
#include "Screen.h"
#include "Mob.h"
#include <Windows.h>

std::thread GameMainThread;

//初始化
int	 initGL();
void initBlock();
void initGame();
void initScreen();
void initTexture();
void initMob();

//游戏主循环
void gameMainThread()
{
	while (!glfwWindowShouldClose(window))
	{
		Sleep(10);
		if (Screen.getEnableScreen() == 0)
		{

		}
		else
		{
			Mob.refreshMobs();
		}
	}
}
void initGame()
{
	//初始化OpenGL
	initGL();

	//初始化生物
	initMob();

	//初始化屏幕
	initScreen();

	//初始化纹理
	initTexture();

	//初始化Block
	initBlock();

	Mob.addMob(MobType[0]);

	GameMainThread = std::thread(gameMainThread);
	GameMainThread.detach();
}