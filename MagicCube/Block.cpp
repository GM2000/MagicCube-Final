
#include "Block.h"

blocks Blocks;

void stone(std::vector<GLfloat> *TodalData, int Addition, bool RenderTop, bool RenderDown, bool RenderLeft, bool RenderRight, bool RenderFront, bool RenderBack)
{
	if (RenderTop)
	{
		//左后上
		TodalData->push_back(-1.0); TodalData->push_back(1.0); TodalData->push_back(-1.0);//顶点

		TodalData->push_back(0 / 32.0); TodalData->push_back(0 / 32.0);//纹理
																	   //右后上
		TodalData->push_back(1.0); TodalData->push_back(1.0); TodalData->push_back(-1.0);//顶点

		TodalData->push_back(1 / 32.0); TodalData->push_back(0 / 32.0);//纹理
																	   //右前上
		TodalData->push_back(1.0); TodalData->push_back(1.0); TodalData->push_back(1.0);//顶点

		TodalData->push_back(1 / 32.0); TodalData->push_back(1 / 32.0);//纹理
																	   //左前上
		TodalData->push_back(-1.0); TodalData->push_back(1.0); TodalData->push_back(1.0);//顶点

		TodalData->push_back(0 / 32.0); TodalData->push_back(1 / 32.0);//纹理
	}
	if (RenderDown)
	{
		TodalData->push_back(-1.0); TodalData->push_back(-1.0); TodalData->push_back(-1.0);//顶点

		TodalData->push_back(0 / 32.0); TodalData->push_back(0 / 32.0);//纹理
																	   
		TodalData->push_back(-1.0); TodalData->push_back(-1.0); TodalData->push_back(1.0);//顶点

		TodalData->push_back(1 / 32.0); TodalData->push_back(0 / 32.0);//纹理
																	   
		TodalData->push_back(1.0); TodalData->push_back(-1.0); TodalData->push_back(1.0);//顶点

		TodalData->push_back(1 / 32.0); TodalData->push_back(1 / 32.0);//纹理
																	   
		TodalData->push_back(1.0); TodalData->push_back(-1.0); TodalData->push_back(-1.0);//顶点

		TodalData->push_back(0 / 32.0); TodalData->push_back(1 / 32.0);//纹理
	}
	if (RenderLeft)
	{
		//左后上
		TodalData->push_back(-1.0); TodalData->push_back(1.0); TodalData->push_back(-1.0);//顶点

		TodalData->push_back(0 / 32.0); TodalData->push_back(0 / 32.0);//纹理
																	   //左后下
		TodalData->push_back(-1.0); TodalData->push_back(1.0); TodalData->push_back(1.0);//顶点

		TodalData->push_back(1 / 32.0); TodalData->push_back(0 / 32.0);//纹理
																	   //左前下
		TodalData->push_back(-1.0); TodalData->push_back(-1.0); TodalData->push_back(1.0);//顶点

		TodalData->push_back(1 / 32.0); TodalData->push_back(1 / 32.0);//纹理
																	   //左前上
		TodalData->push_back(-1.0); TodalData->push_back(-1.0); TodalData->push_back(-1.0);//顶点

		TodalData->push_back(0 / 32.0); TodalData->push_back(1 / 32.0);//纹理
	}
	if (RenderRight)
	{
		//右后上
		TodalData->push_back(1.0); TodalData->push_back(1.0); TodalData->push_back(-1.0);//顶点

		TodalData->push_back(0 / 32.0); TodalData->push_back(0 / 32.0);//纹理
																	   //右后下
		TodalData->push_back(1.0); TodalData->push_back(-1.0); TodalData->push_back(-1.0);//顶点

		TodalData->push_back(1 / 32.0); TodalData->push_back(0 / 32.0);//纹理
																	   //右前下
		TodalData->push_back(1.0); TodalData->push_back(-1.0); TodalData->push_back(1.0);//顶点

		TodalData->push_back(1 / 32.0); TodalData->push_back(1 / 32.0);//纹理
																	   //右前上
		TodalData->push_back(1.0); TodalData->push_back(1.0); TodalData->push_back(1.0);//顶点

		TodalData->push_back(0 / 32.0); TodalData->push_back(1 / 32.0);//纹理
	}
	if (RenderFront)
	{
		//左前上
		TodalData->push_back(-1.0); TodalData->push_back(1.0); TodalData->push_back(1.0);//顶点

		TodalData->push_back(0 / 32.0); TodalData->push_back(0 / 32.0);//纹理
																	   //左前下
		TodalData->push_back(1.0); TodalData->push_back(1.0); TodalData->push_back(1.0);//顶点

		TodalData->push_back(1 / 32.0); TodalData->push_back(0 / 32.0);//纹理
																	   //右前下
		TodalData->push_back(1.0); TodalData->push_back(-1.0); TodalData->push_back(1.0);//顶点

		TodalData->push_back(1 / 32.0); TodalData->push_back(1 / 32.0);//纹理
																	   //右前上
		TodalData->push_back(-1.0); TodalData->push_back(-1.0); TodalData->push_back(1.0);//顶点

		TodalData->push_back(0 / 32.0); TodalData->push_back(1 / 32.0);//纹理
	}
	if (RenderBack)
	{
		//左后上
		TodalData->push_back(-1.0); TodalData->push_back(1.0); TodalData->push_back(-1.0);//顶点

		TodalData->push_back(0 / 32.0); TodalData->push_back(0 / 32.0);//纹理
																	   //左后下
		TodalData->push_back(-1.0); TodalData->push_back(-1.0); TodalData->push_back(-1.0);//顶点

		TodalData->push_back(1 / 32.0); TodalData->push_back(0 / 32.0);//纹理
																	   //右后下
		TodalData->push_back(1.0); TodalData->push_back(-1.0); TodalData->push_back(-1.0);//顶点

		TodalData->push_back(1 / 32.0); TodalData->push_back(1 / 32.0);//纹理
																	   //右后上
		TodalData->push_back(1.0); TodalData->push_back(1.0); TodalData->push_back(-1.0);//顶点

		TodalData->push_back(0 / 32.0); TodalData->push_back(1 / 32.0);//纹理
	}
}

void initBlock()
{
	Blocks.addBlock("Stone", stone);
}