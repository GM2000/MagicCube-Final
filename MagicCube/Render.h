#pragma once

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class screen
{
	//每个都是正方形，数据排列为12(形状)+8(纹理)+16(颜色),法线这类的以后在加
	std::vector<GLfloat> RenderGroup;
public:
	void drawScreen()
	{

	}
};