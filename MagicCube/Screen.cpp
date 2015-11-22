
#include "Screen.h"

namespace screenInfo
{
	unsigned int LoadingScreen;
	unsigned int TitleScreen;
	unsigned int GameScreen;
}
void initScreen()
{
	screenInfo::LoadingScreen = Screen.addScreen();
	screenInfo::TitleScreen = Screen.addScreen();
	screenInfo::GameScreen = Screen.addScreen();

	Screen.enableScreen(screenInfo::LoadingScreen);
}