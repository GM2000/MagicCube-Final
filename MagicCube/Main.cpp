#include "World.h"
#include "Block.h"

#include "Render.h"

int initGL();
int renderMainLoop();

int main()
{
	initGL();

	screens screen;
	screen.addScreen();
	screen.addScreen();
	screen.enableScreen(screen.addScreen());

	screen.addRenderGroup()->setData();

	screen.drawScreen();
	return renderMainLoop();
}