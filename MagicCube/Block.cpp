
#include "Block.h"

blocks Blocks;

void stone(renderGroup* RenderGroup, int Addition, bool RenderTop, bool RenderDown, bool RenderLeft, bool RenderRight, bool RenderFront, bool RenderBack, float X, float Y, float Z)
{
	if (RenderTop)
	{
		//左后上
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//纹理
																								 //右后上
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//纹理
																								 //右前上
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//纹理
																								 //左前上
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//纹理
	}
	if (RenderDown)
	{
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//纹理

		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//纹理

		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//纹理

		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//纹理
	}
	if (RenderLeft)
	{
		//左后上
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//纹理
																								 //左后下
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//纹理
																								 //左前下
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//纹理
																								 //左前上
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//纹理
	}
	if (RenderRight)
	{
		//右后上
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//纹理
																								 //右后下
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//纹理
																								 //右前下
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//纹理
																								 //右前上
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//纹理
	}
	if (RenderFront)
	{
		//左前上
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//纹理
																								 //左前下
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//纹理
																								 //右前下
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//纹理
																								 //右前上
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//纹理
	}
	if (RenderBack)
	{
		//左后上
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//纹理
																								 //左后下
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//纹理
																								 //右后下
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//纹理
																								 //右后上
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//顶点

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//纹理
	}
}

void initBlock()
{
	Blocks.addBlock("Stone", stone);
}