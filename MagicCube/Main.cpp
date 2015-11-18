#include "World.h"
#include "Block.h"

#include "Render.h"

int initGL();
int renderMainLoop();

int main()
{
	//初始化OpenGL
	initGL();
	//加载一个Shader并设置Shader类型（以后可能不需要标注类型）
	shader Normal2D("Normail2D", 0);

	//添加一个屏幕并且激活
	Screen.enableScreen(Screen.addScreen());

	//获取新的RenderGroup的指针
	renderGroup* RenderGroup = Screen.addRenderGroup();

	//设置Shader
	RenderGroup->setShader(Normal2D);
	std::vector<GLfloat> RenderData;

	//提供渲染数据
	RenderData.push_back(-1.0);
	RenderData.push_back(1.0);
	RenderData.push_back(0.0);
	RenderData.push_back(-1.0);
	RenderData.push_back(-1.0);
	RenderData.push_back(0.0);
	RenderData.push_back(1.0);
	RenderData.push_back(-1.0);
	RenderData.push_back(0.0);
	RenderData.push_back(1.0);
	RenderData.push_back(1.0);
	RenderData.push_back(0.0);
	//OK！

	//复制数据
	RenderGroup->setData(RenderData);
	//激活渲染组
	RenderGroup->IsEnable = true;
	//第二块屏幕
	//添加一个屏幕并且激活
	Screen.enableScreen(Screen.addScreen());

	//获取新的RenderGroup的指针
	RenderGroup = Screen.addRenderGroup();

	//设置Shader
	RenderGroup->setShader(Normal2D);
	RenderData.clear();

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
	RenderGroup->setData(RenderData);
	//激活渲染组
	RenderGroup->IsEnable = true;

	//渲染主循环
	return renderMainLoop();
}