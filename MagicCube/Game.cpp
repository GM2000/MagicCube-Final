
#include <thread>
#include "Player.h"
#include "World.h"
#include "Screen.h"

player Player;

std::thread GameThread;

void gameMain()
{
	while (!glfwWindowShouldClose(window))
	{
		if (Screen.getEnableScreen() != 0)
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
	Player.bindMob(Mobs.addMob());

	GameThread = std::thread(gameMain);
}