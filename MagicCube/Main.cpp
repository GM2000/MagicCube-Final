
#include "Screen.h"
#include "Chunk.h"
//初始化Chunk
chunks Chunk;

int initGL();
int renderMainLoop();
void initGame();

int main()
{
	//初始化OpenGL
	initGL();

	//添加一个屏幕并且激活
	Screen.enableScreen(Screen.addScreen(true));

	//获取新的RenderGroup的指针
	renderGroup* RenderGroup = Screen.addRenderGroup();

	//设置Shader
	RenderGroup->setShader(&Shader[0]);
	std::vector<GLfloat> RenderData;

	RenderData.reserve(100);
	//提供渲染数据
	RenderData.push_back(-0.5);
	RenderData.push_back(0.5);
	RenderData.push_back(0.0);
	RenderData.push_back(-0.5);
	RenderData.push_back(-0.5);
	RenderData.push_back(0.0);
	RenderData.push_back(0.5);
	RenderData.push_back(-0.5);
	RenderData.push_back(0.0);
	RenderData.push_back(0.5);
	RenderData.push_back(0.5);
	RenderData.push_back(0.0);
	//OK！

	//复制数据
	RenderGroup->setData(&RenderData);
	//激活渲染组
	RenderGroup->IsEnable = true;

	//初始化游戏
	initGame();

	//渲染主循环
	return renderMainLoop();
}