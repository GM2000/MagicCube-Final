#pragma once

#include "Render.h"

struct shader
{
public:
	shader(int ProgramID)
	{
		shader::ProgramID = ProgramID;
	}
	unsigned int ProgramID;

	std::vector<unsigned int> UniformLocation;
};

extern std::vector<shader> Shader;