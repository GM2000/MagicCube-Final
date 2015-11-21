#pragma once

#include "MagicCube.h"

class chunkMap
{
	class chunkLocation
	{
		int ChunkX = 0;
		int ChunkZ = 0;

		unsigned int ChunkID = 0;

	public:
		//初始化
		//分别提供Chunk的坐标和ChunkID
		chunkLocation(int inputChunkX, int inputChunkZ, unsigned int inputChunkID)
		{
			ChunkX = inputChunkX;
			ChunkZ = inputChunkZ;

			ChunkID = inputChunkID;
		}
		//只提供Chunk的坐标，ChunkID为空，只在查找Chunk时使用，其他情况使用它将会不安全
		chunkLocation(int inputChunkX, int inputChunkZ)
		{
			ChunkX = inputChunkX;
			ChunkZ = inputChunkZ;

			ChunkID = 0;
		}

		//操作符重载
		bool operator==(chunkLocation Location)
		{
			if ((Location.ChunkX == ChunkX) && (Location.ChunkZ == ChunkZ))
			{
				return true;
			}
			return false;
		}
		//判断大小（先判断X，在判断Z）
		bool operator>(chunkLocation Location)
		{
			if ((Location.ChunkX < ChunkX))
			{
				return true;
			}
			else if ((Location.ChunkX == ChunkX))
			{
				if ((Location.ChunkZ < ChunkZ))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		//判断大小（先判断X，在判断Z）
		bool operator<(chunkLocation Location)
		{
			if ((Location.ChunkX > ChunkX))
			{
				return true;
			}
			else if ((Location.ChunkX == ChunkX))
			{
				if ((Location.ChunkZ > ChunkZ))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}

		//返回ChunkID
		unsigned int getChunkID()
		{
			return ChunkID;
		}
	};

	//二分查找
	unsigned int binarySearchChunk(int ChunkX,int ChunkZ)
	{
		if (!HasSort)
		{
			//生序排列
			std::sort(ChunkMap.begin(), ChunkMap.end());
			HasSort = true;
		}

		if (ChunkMap.empty() || ChunkMap.size() == 0)
			return -1;

		chunkLocation FindChunkLoc(ChunkX, ChunkZ);

		int NowRight = 0;
		int NowMid = 0;

		int NowLeft = ChunkMap.size() - 1;

		while (NowRight <= NowLeft)
		{
			NowMid = (NowRight + NowLeft) / 2;

			if (ChunkMap[NowMid] < FindChunkLoc)
				NowRight = NowMid + 1;
			else if (ChunkMap[NowMid] > FindChunkLoc)
				NowLeft = NowMid - 1;
			else
			{
				return NowMid;
			}
		}
		return -1;
	}

	std::vector<chunkLocation> ChunkMap;

	bool HasSort = true;

public:
	//添加Chunk到ChunkMap
	void addChunk(int ChunkX, int ChunkZ, unsigned int ChunkID)
	{
		ChunkMap.push_back(chunkLocation(ChunkX, ChunkZ, ChunkID));
		HasSort = false;
	}
	//从ChunkMap中移除Chunk
	unsigned int delChunk(int ChunkX, int ChunkZ)
	{
		int FindChunkID = binarySearchChunk(ChunkX, ChunkZ);

		if (FindChunkID == -1)
		{
			return -1;
		}
		const int ReturnChunkID = ChunkMap[FindChunkID].getChunkID();

		std::vector<chunkLocation>::iterator FindIterator = ChunkMap.begin() + FindChunkID;

		ChunkMap.erase(FindIterator);

		return ReturnChunkID;
	}
	//查找Chunk
	unsigned int findChunk(int ChunkX, int ChunkZ)
	{
		int FindChunkID = binarySearchChunk(ChunkX, ChunkZ);
		
		if (FindChunkID == -1)
		{
			return -1;
		}
		return ChunkMap[FindChunkID].getChunkID();
	}
};