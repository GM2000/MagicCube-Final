
#include "Screen.h"
#include "Chunk.h"
#include "Mob.h"


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int renderMainLoop();
void initGame();

int main()
{
	initGame();

	//添加一个屏幕并且激活
	Screen.enableScreen(screenInfo::GameScreen);

	//获取新的RenderGroup的指针
	renderGroup* RenderGroup = Screen.addRenderGroup();

	//设置Shader
	RenderGroup->setShader(&Shader[0]);
	std::vector<GLfloat> RenderData;

	RenderData.reserve(10000);

	Blocks[0].AddRenderData(&RenderData, 0, 1, 1, 1, 1, 1, 1);
	//////////////////////////////////////////////
	//OK！

	//复制数据
	RenderGroup->setData(&RenderData);
	//激活渲染组
	RenderGroup->IsEnable = true;

	Mob.addMob(MobType[0]);

	renderMainLoop();
	//渲染主循环
	return 0;
}