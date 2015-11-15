#pragma once

#include <GL/glew.h>
#include <vector>
#include <string>

const int Texture_Up	 = 0;
const int Texture_Down	 = 1;
const int Texture_Left	 = 2;
const int Texture_Right	 = 3;
const int Texture_Front	 = 4;
const int Texture_Back	 = 5;

const int Block_Tyoe_Block_Normal	= 0;
const int Block_Tyoe_HalfBlock		= 1;

struct blockData
{
	unsigned int	BlockID			= 0;
	unsigned short	BlockAddition	= 0;
	unsigned char	Light			= 0;
};

class blocks
{
public:
	class blockTexture
	{
		int Texture[6]{ 0 };
	public:
		blockTexture(
			int TextureUp,
			int TextureDown,
			int TextureLeft,
			int TextureRight,
			int TextureFront,
			int TextureBack)
		{
			Texture[Texture_Up]		= TextureUp;
			Texture[Texture_Down]	= TextureDown;
			Texture[Texture_Left]	= TextureLeft;
			Texture[Texture_Right]	= TextureRight;
			Texture[Texture_Front]	= TextureFront;
			Texture[Texture_Back]	= TextureBack;
		}

		blockTexture()
		{
			Texture[Texture_Up]		= 0;
			Texture[Texture_Down]	= 0;
			Texture[Texture_Left]	= 0;
			Texture[Texture_Right]	= 0;
			Texture[Texture_Front]	= 0;
			Texture[Texture_Back]	= 0;
		}

	};
private:
	class block
	{
		blockTexture	BlockTexture;

		unsigned int	BlockType;
		unsigned int	BlockID;

		std::string BlockName;

	public:
		block(unsigned int BlockID, blockTexture BlockTexture, const char* BlockName,unsigned int BlockType)
		{
			block::BlockID		= BlockID;
			block::BlockTexture = BlockTexture;
			block::BlockName	= BlockName;
			block::BlockType	= BlockType;

		}
		void addRenderData(std::vector<GLfloat> *TodalData,int Addition, bool RenderTop, bool RenderDown, bool RenderLeft, bool RenderRight, bool RenderFront, bool RenderBack);

		unsigned int getBlockID()
		{
			return BlockID;
		}
		std::string getBlockName()
		{
			return BlockName;
		}
	};
public:
	std::vector<block> Blocks;

	block operator [](unsigned int BlockID)
	{
		if (BlockID > Blocks.size())
		{
			return block(0,blockTexture(),"NULL",0);
		}
		return Blocks[BlockID];
	}
	void addBlock(const char* BlockName, blockTexture BlockTexture,unsigned int BlockType)
	{
		Blocks.push_back(block(Blocks.size(), BlockTexture, BlockName, BlockType));
	}
};