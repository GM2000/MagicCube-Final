#pragma once

#include "Chunk.h"

//储存一个World（一般来说每个world有切仅有一个chunks类的变量）
class world
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
	~world()
	{
		Chunk.clear();
	}
	//用Chunk的ID来访问Chunk（并没有什么大用）
	chunk* operator [](unsigned int Count)
	{
		return &Chunk[Count];
	}
	//初始化Chunks，后期可能会有所修改
	world()
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

extern world MainWorld;