#pragma once

#include "Block.h"
#include "ChunkMap.h"
#include "RenderGroup.h"

static int		MaxChunkNumber = 2500;

//储存单个Chunk的数据
class chunk
{
private:
	//方块数据
	blockData BlockData[16][16][256];
public:
	//RenderGroup指针
	renderGroup *RenderGroup;

	void RefreshRenderData()
	{

	}
	//获取方块数据，请保证BlockX，BlockY，BlockZ在相应的范围内
	blockData getBlock(unsigned char BlockX, unsigned char BlockY, unsigned char BlockZ)
	{
		if ((BlockX > 15) | (BlockY > 15) | (BlockZ > 15))
		{
			throw;
		}
		return BlockData[BlockX][BlockY][BlockZ];
	}
	//获取方块数据，请保证BlockX，BlockY，BlockZ在相应的范围内
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

//储存一组Chunk（一般来说每个world有切仅有一个chunks类的变量）
class chunks
{
	//寻找空闲的ChunkID
	unsigned int findFreeChunkID()
	{
		if (FreeChunksList.size() == 0)
		{
			if (HasUseChunkID == MaxChunkNumber)
			{
				return -1;
			}
			return HasUseChunkID++;
		}

		int FreeChunkID = FreeChunksList.back();

		FreeChunksList.pop_back();

		return FreeChunkID;
	}

	int		HasUseChunkID = 0;

	std::list<int>		FreeChunksList;
	chunkMap			ChunkMap;
	std::vector<chunk>	Chunk;

public:
	//用Chunk的ID来访问Chunk（并没有什么大用）
	chunk* operator [](unsigned int Count)
	{
		return &Chunk[Count];
	}
	//初始化Chunks，后期可能会有所修改
	chunks()
	{
		Chunk.reserve(MaxChunkNumber);
	}
	//添加一个Chunk，返回值表示了是否成功添加Chunk
	bool addChunk(int ChunkX, int ChunkZ)
	{
		int FreeChunk = findFreeChunkID();

		if (FreeChunk == -1)
		{
			return false;
		}
		Chunk[FreeChunk].IsEmpty = false;
		Chunk[FreeChunk].ChunkX = ChunkX;
		Chunk[FreeChunk].ChunkZ = ChunkZ;
		ChunkMap.addChunk(ChunkX, ChunkZ, FreeChunk);

		return true;
	}
	//删除chunk
	void delChunk(int ChunkX, int ChunkZ)
	{
		int getChunkID = ChunkMap.delChunk(ChunkX, ChunkZ);

		if (getChunkID == -1)
		{
			return;
		}
		Chunk[getChunkID].IsEmpty = true;

		FreeChunksList.push_back(getChunkID);
	}
	//寻找chunk
	chunk* findChunk(int ChunkX, int ChunkZ)
	{
		int getChunkID = ChunkMap.findChunk(ChunkX, ChunkZ);

		if (getChunkID == -1)
		{
			EmptyChunk.IsEmpty = true;

			return &EmptyChunk;
		}
		return &Chunk[getChunkID];
	}
};