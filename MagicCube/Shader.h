#pragma once

#include "Render.h"

//着色器基本信息
typedef void(*setShaderData)();
typedef void(*prepareRender)(GLuint ProgramID);

//一个shader
struct shader
{
	prepareRender PrepareRender;
public:
	setShaderData SetShaderData;

	shader(int ProgramID, setShaderData SetShaderData, prepareRender PrepareRender,unsigned char DataSize)
	{
		shader::DataSize		= DataSize;
		shader::SetShaderData	= SetShaderData;
		shader::PrepareRender	= PrepareRender;
		shader::ProgramID		= ProgramID;
	}
	void prepareRender()
	{
		PrepareRender(ProgramID);
	}
	unsigned char DataSize;
	unsigned int  ProgramID;
};

extern std::vector<GLuint> UniformLocation;
extern std::vector<shader> Shader;
//函数
void normail3DSet();
void normail3DPrepare(GLuint ProgramID);