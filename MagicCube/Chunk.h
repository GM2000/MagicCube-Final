#pragma once

#include "Block.h"
#include "ChunkMap.h"
#include "RenderGroup.h"

static int		MaxChunkNumber = 4096;

//储存单个Chunk的数据
class chunk
{
private:
	//方块数据
	blockData BlockData[16][16][256];
public:
	//RenderGroup指针
	renderGroup *RenderGroup;

	//获取方块数据，请保证BlockX，BlockY，BlockZ在相应的范围内
	blockData getBlock(unsigned char BlockX, unsigned char BlockY, unsigned char BlockZ)
	{
		if ((BlockX > 15) | (BlockY > 15) | (BlockZ > 15))
		{
			throw;
		}
		return BlockData[BlockX][BlockY][BlockZ];
	}
	//设置方块数据，请保证BlockX，BlockY，BlockZ在相应的范围内
	void setBlock(unsigned char BlockX, unsigned char BlockY, unsigned char BlockZ, blockData BlockData)
	{
		if ((BlockX > 15) | (BlockY > 15) | (BlockZ > 15))
		{
			throw;
		}
		chunk::BlockData[BlockX][BlockY][BlockZ] = BlockData;
	}
	bool	IsEmpty = true;

	int		ChunkX = 0;
	int		ChunkZ = 0;
};

static chunk	EmptyChunk;
