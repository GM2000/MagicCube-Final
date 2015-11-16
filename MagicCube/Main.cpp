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

	renderGroup* RG = screen.addRenderGroup();
	RG->IsEnable = true;
	RG->draw();


	screen.drawScreen();
	return renderMainLoop();
}