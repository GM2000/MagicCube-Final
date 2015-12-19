#pragma once

#include "Render.h"

//着色器基本信息
typedef void(*useShader)(GLuint ProgramID);

//一个shader
class shader
{
	useShader UseShader;
public:
	unsigned int  ProgramID;
	unsigned char DataSize;

	shader(int ProgramID, useShader UseShader,unsigned char DataSize)
	{
		shader::DataSize		= DataSize;
		shader::UseShader		= UseShader;
		shader::ProgramID		= ProgramID;
	}
	void useShader()
	{
		UseShader(ProgramID);
	}
};

extern std::vector<GLuint> UniformLocation;
extern std::vector<shader> Shader;
//函数
void normail3DUse(GLuint ProgramID);