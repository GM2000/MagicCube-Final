#pragma once

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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