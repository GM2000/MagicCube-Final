
#include "Screen.h"
#include "Chunk.h"
#include "Mob.h"
//初始化Chunk
world MainWorld;

int initGL();
int renderMainLoop();
void initGame();
void initScreen();
void initTexture();
void initMob();

int main()
{
	//初始化OpenGL
	initGL();

	//初始化生物
	initMob();

	Mob.addMob(MobType[0]);
	//初始化游戏
	initGame();

	initScreen();

	initTexture();

	//添加一个屏幕并且激活
	//Screen.enableScreen(Screen.addScreen());
	//添加一个屏幕并且激活
	Screen.enableScreen(screenInfo::GameScreen);

	//获取新的RenderGroup的指针
	renderGroup* RenderGroup = Screen.addRenderGroup();

	//设置Shader
	RenderGroup->setShader(&Shader[0]);
	std::vector<GLfloat> RenderData;

	RenderData.reserve(100);
	//提供渲染数据
	for (int i = 0; i < 1000; i++)
	{
		RenderData.push_back(-0.5);
		RenderData.push_back(0.5);
		RenderData.push_back(i*0.00001);

		RenderData.push_back(0.0);
		RenderData.push_back(0.0);
		/////////////////////
		RenderData.push_back(-0.5);
		RenderData.push_back(-0.5);
		RenderData.push_back(i*0.00001);

		RenderData.push_back(0.0);
		RenderData.push_back(1.0);
		//////////////////////
		RenderData.push_back(0.5);
		RenderData.push_back(-0.5);
		RenderData.push_back(i*0.00001);

		RenderData.push_back(1.0);
		RenderData.push_back(1.0);
		////////////////////
		RenderData.push_back(0.5);
		RenderData.push_back(0.5);
		RenderData.push_back(i*0.00001);

		RenderData.push_back(1.0);
		RenderData.push_back(0.0);
	}
	//////////////////////////////////////////////
	//OK！

	//复制数据
	RenderGroup->setData(&RenderData);
	//激活渲染组
	RenderGroup->IsEnable = true;


	//渲染主循环
	return renderMainLoop();
}