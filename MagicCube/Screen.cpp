
#include "Screen.h"

namespace screenInfo
{
	unsigned int LoadingScreen;
	unsigned int TitleScreen;
	unsigned int GameScreen;
}

void Normail3DGameScreen()
{
	glEnable(GL_DEPTH_TEST);
}
void Normail2DScreen()
{
	glDisable(GL_DEPTH_TEST);
}
void initScreen()
{
	screenInfo::LoadingScreen = Screen.addScreen(Normail2DScreen);
	screenInfo::TitleScreen = Screen.addScreen(Normail2DScreen);
	screenInfo::GameScreen = Screen.addScreen(Normail3DGameScreen);

	Screen.enableScreen(screenInfo::LoadingScreen);
}