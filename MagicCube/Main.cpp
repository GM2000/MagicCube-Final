
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

	//////////////////////////////////////////////

	for (int i2 = -32; i2 < 32; i2++)
	{
		for (int j2 = -32; j2 < 32; j2++)
		{
			//获取新的RenderGroup的指针
			renderGroup* RenderGroup = Screen.addRenderGroup();

			//设置Shader
			RenderGroup->setShader(&Shader[0]);

			for (int i = 0; i < 16; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					Blocks[0].AddRenderData(RenderGroup, 0, 1, 1, 1, 1, 1, 1, i + i2 * 16, -2, j + j2 * 16);
				}
			}

			RenderGroup->refreshData();
			//激活渲染组
			RenderGroup->IsEnable = true;
		}
	}
	//////////////////////////////////////////////
	//OK！

	renderMainLoop();
	//渲染主循环
	return 0;
}