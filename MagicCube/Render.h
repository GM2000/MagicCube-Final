#pragma once

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class renderGroup
{
	GLuint Shader = 0;
	GLuint Buffer = 0;
public:
	void setShader(GLuint Shader)
	{
		renderGroup::Shader = Shader;
	}
	void setData(GLfloat* RenderData)
	{
		glGenBuffers(1, &Buffer);
		glBindBuffer(GL_ARRAY_BUFFER, Buffer);

	}
	void draw()
	{

	}
};

class screen
{
	//每个都是正方形，数据排列为12(形状)+8(纹理)+16(颜色),法线这类的以后在加
	std::vector<renderGroup> RenderGroup;
public:
	renderGroup* addRenderGroup()
	{
		RenderGroup.push_back(renderGroup());

		return &RenderGroup[RenderGroup.size() - 1];
	}
	void drawScreen()
	{
		for (int i = 0; i < RenderGroup.size(); i++)
		{
			RenderGroup[i].draw();
		}
	}
};

//首先需要激活需要修改的Screen，然后再进行操作
class screens
{
	std::vector<screen> Screen;
public:
	std::vector<GLuint> VertexArrays;

	unsigned int NowEnableScreen = 0;

	//渲染
	void enableScreen(unsigned int ScreenID)
	{
		if (ScreenID < Screen.size())
		{
			glBindVertexArray(VertexArrays[ScreenID]);

			NowEnableScreen = ScreenID;

			return;
		}
		throw(1001);
	}
	void drawScreen()
	{
		Screen[NowEnableScreen].drawScreen();
	}
	//修改数据
	unsigned int addScreen()
	{
		Screen.push_back(screen());
		VertexArrays.resize(Screen.size());

		glGenVertexArrays(1,&VertexArrays[Screen.size() - 1]);

		return Screen.size() - 1;
	}
	renderGroup* addRenderGroup()
	{
		return Screen[NowEnableScreen].addRenderGroup();
	}
};