#pragma once

#include "RenderGroup.h"
#include <mutex>

typedef void(*screenOpenglCode)();

class screen
{
	//每个都是正方形，数据排列为12(形状)+8(纹理)+16(颜色),法线这类的以后在加
	std::vector<renderGroup> RenderGroup;

	screenOpenglCode ScreenOpenglCode;
public:
	screen(screenOpenglCode ScreenOpenglCode)
	{
		screen::ScreenOpenglCode = ScreenOpenglCode;
	}
	renderGroup* addRenderGroup()
	{
		RenderGroup.push_back(renderGroup());

		return &RenderGroup[RenderGroup.size() - 1];
	}
	renderGroup* getRenderGroup(int Count)
	{
		return &RenderGroup[Count];
	}
	void drawScreen()
	{
		ScreenOpenglCode();

		for (unsigned int i = 0; i < RenderGroup.size(); i++)
		{
			RenderGroup[i].draw();
		}
	}
};

//首先需要激活需要修改的Screen，然后再进行操作
class screens
{
	std::vector<screen> Screen;
	std::vector<GLuint> VertexArrays;
	std::mutex NowEnableScreenMutex;

	unsigned int	NowEnableScreen = 0;
public:
	//渲染
	void enableScreen(unsigned int ScreenID)
	{
		if (ScreenID < Screen.size())
		{
			glBindVertexArray(VertexArrays[ScreenID]);

			NowEnableScreenMutex.lock();
			NowEnableScreen = ScreenID;
			NowEnableScreenMutex.unlock();
		}
	}
	void drawScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Screen[NowEnableScreen].drawScreen();
	}
	//修改数据
	unsigned int addScreen(screenOpenglCode ScreenOpenglCode)
	{
		Screen.push_back(screen(ScreenOpenglCode));
		VertexArrays.resize(Screen.size());

		glGenVertexArrays(1,&VertexArrays[Screen.size() - 1]);

		return (unsigned int)Screen.size() - 1;
	}
	renderGroup* addRenderGroup()
	{
		return Screen[NowEnableScreen].addRenderGroup();
	}
	//读取数据
	unsigned int getEnableScreen()
	{
		NowEnableScreenMutex.lock();

		int ReturnData = NowEnableScreen;

		NowEnableScreenMutex.unlock();

		return ReturnData;
	}
	unsigned int getSize()
	{
		return (unsigned int)Screen.size();
	}
};

namespace screenInfo
{
	extern unsigned int TitleScreen;
	extern unsigned int GameScreen;
}
extern screens Screen;
