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

	shader Normal2D("Normal2D");

	std::vector<GLfloat> RD;
	RD.push_back(-1.0);
	RD.push_back(1.0);
	RD.push_back(0.0);
	RD.push_back(-1.0);
	RD.push_back(-1.0);
	RD.push_back(0.0);
	RD.push_back(1.0);
	RD.push_back(-1.0);
	RD.push_back(0.0);
	RD.push_back(1.0);
	RD.push_back(1.0);
	RD.push_back(0.0);
	RG->setData(RD);


	screen.drawScreen();
	return renderMainLoop();
}