
#include <thread>
#include "Player.h"
#include "World.h"
#include "Screen.h"

std::thread GameThread;

player Player;

//ÓÎÏ·Ö÷Ñ­»·
void gameMain()
{
	while (!glfwWindowShouldClose(window))
	{
		if (Screen.getEnableScreen() == 0)
		{

		}
		else
		{
			Player.playerMove();
		}
	}
}

void initGame()
{
	GameThread = std::thread(gameMain);
	Player.bindMob(Mob.addMob());
}