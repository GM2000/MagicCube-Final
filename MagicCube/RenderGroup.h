#pragma once

#include "Shader.h"

class renderGroup
{
	shader	*ShaderProgram  = 0;
	GLuint	Buffer			= 0;
	GLuint  BufferSize		= 0;
public:
	std::vector<GLfloat>	RenderData;

	bool	IsEnable = false;

	renderGroup()
	{
		glGenBuffers(1, &Buffer);
	}
	void setShader(shader *ShaderProgram)
	{
		renderGroup::ShaderProgram = ShaderProgram;
	}
	void refreshData()
	{
		if (RenderData.size() <= BufferSize)
		{
			return;
		}
		glBindBuffer(GL_ARRAY_BUFFER, Buffer);

		glBufferData(GL_ARRAY_BUFFER, RenderData.size() * sizeof(GLfloat), &RenderData.at(0), GL_STATIC_DRAW);
		
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		BufferSize =(GLuint)RenderData.size();
	}
	void draw()
	{
		if (IsEnable)
		{
			glBindBuffer(GL_ARRAY_BUFFER, Buffer);

			ShaderProgram->useShader();

			glDrawArrays(GL_QUADS, 0, BufferSize / ShaderProgram->DataSize);
		}
	}
};