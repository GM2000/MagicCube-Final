
#include "Block.h"

void blocks::block::addRenderData(std::vector<GLfloat> *TodalData, int Addition, bool RenderTop, bool RenderDown, bool RenderLeft, bool RenderRight, bool RenderFront, bool RenderBack)
{
	std::vector<GLfloat> RenderData;

	switch (BlockType)
	{
	case Block_Tyoe_Block_Normal:
	{
		TodalData->push_back(0.0f);
		TodalData->push_back(3.2f);
	}
	default:
		break;
	}
}