#include "World.h"
#include "Block.h"

#include <stdio.h>
#include <windows.h>


#include <iostream>

int initGL();
int renderMainLoop();

int main()
{
	/*
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;

	double time;

	//test ChunkMap
	std::cout << "start!" << std::endl;

	chunks test;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);

	QueryPerformanceCounter(&nEndTime);
	std::cout << "AT" <<(double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart << "s start" << std::endl;

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			test.addChunk(i, j);
		}
	}

	QueryPerformanceCounter(&nEndTime);
	std::cout << "AT" << (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart << "s add 2500 chunks" << std::endl;

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			test.delChunk(i, j);
		}
	}

	QueryPerformanceCounter(&nEndTime);
	std::cout << "AT" << (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart << "s del 2500 chunks" << std::endl;

	blockData i = test.findChunk(16, 5)->getBlock(15, 15, 15);

	QueryPerformanceCounter(&nEndTime);
	std::cout << "AT" << (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart << "s find a chunk" << std::endl;

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			test.addChunk(i, j);
		}
	}
	test.delChunk(12, 15);

	QueryPerformanceCounter(&nEndTime);
	std::cout << "AT" << (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart << "s add 2500 chunks and del a chunks" << std::endl;

	test.delChunk(31, 31);
	std::cout << test.findChunk(31, 31)->IsEmpty << std::endl;

	QueryPerformanceCounter(&nEndTime);
	std::cout << "AT" << (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart << "s del a chunks" << std::endl;

	int hasfondnum = 0;

	for (int j = 0; j< 50; j++)
	{
		for (int i = 0; i < 50; i++)
		{
			if (test.findChunk(i, j)->IsEmpty == true)
			{
				if (((i == 12) && (j == 15)) || ((i == 31) && (j == 31)))
				{
					hasfondnum++;
				}
				else {
					std::cout << "ERROR!" << std::endl;
				}
			}
		}
	}

	QueryPerformanceCounter(&nEndTime);
	std::cout << hasfondnum << "AT" << (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart << "s find chunk 2500 times" << std::endl;

	QueryPerformanceCounter(&nEndTime);
	std::cout << "AT" << (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart << "s end"<<std::endl;

	//Text Blocks
	blocks testb;
	testb.addBlock("123", (blocks::blockTexture(1, 1, 1, 1, 1, 1)),0);
	std::vector<GLfloat> t;
	testb[0].addRenderData(&t,0, 0, 0, 0, 0, 0, 0);
	*/

	initGL();
	
	return renderMainLoop();
	//return test.findChunk(1, 2);
}