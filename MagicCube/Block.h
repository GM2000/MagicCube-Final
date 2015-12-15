#pragma once

#include "MagicCube.h"

typedef void(*addRenderData)(std::vector<GLfloat> *TodalData, int Addition, bool RenderTop, bool RenderDown, bool RenderLeft, bool RenderRight, bool RenderFront, bool RenderBack);

struct blockData
{
	unsigned short	BlockID			= 0;
	unsigned char	BlockAddition	= 0;
};

class blocks
{
private:
	//block类
	class block
	{
		unsigned int	BlockID;

		std::string BlockName;

	public:
		addRenderData AddRenderData;

		//初始化Block
		block(unsigned int BlockID, const char* BlockName, addRenderData AddRenderData)
		{
			block::BlockID			= BlockID;
			block::BlockName		= BlockName;
			block::AddRenderData	= AddRenderData;

		}
		//获取BlockID
		unsigned int getBlockID()
		{
			return BlockID;
		}
		//获取Block名称
		std::string getBlockName()
		{
			return BlockName;
		}
	};
	//储存所有种类block数据
	std::vector<block> Blocks;
public:
	//通过ID查找Block
	block operator [](unsigned int BlockID)
	{
		if (BlockID > Blocks.size())
		{
			return block(0,"NULL",NULL);
		}
		return Blocks[BlockID];
	}
	//添加一个新的Block
	void addBlock(const char* BlockName, addRenderData AddRenderData)
	{
		Blocks.push_back(block((unsigned int)Blocks.size(), BlockName, AddRenderData));
	}
};

//声明Blocks
extern blocks Blocks;

//初始化Block
void initBlock();