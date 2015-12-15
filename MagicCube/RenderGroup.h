#pragma once

#include "Shader.h"

class renderGroup
{
	shader	*ShaderProgram  = 0;
	GLuint	Buffer			= 0;
	GLuint  BufferSize		= 0;
public:
	bool	IsEnable = false;

	void setShader(shader *ShaderProgram)
	{
		renderGroup::ShaderProgram = ShaderProgram;
	}
	void setData(std::vector<GLfloat> *RenderData)
	{
		if (RenderData->size() == 0)
		{
			return;
		}
		glGenBuffers(1, &Buffer);
		glBindBuffer(GL_ARRAY_BUFFER, Buffer);

		glBufferData(GL_ARRAY_BUFFER, RenderData->size() * sizeof(GLfloat), &RenderData->at(0), GL_STATIC_DRAW);

		ShaderProgram->SetShaderData();
		
		BufferSize =(GLuint)RenderData->size();
	}
	void draw()
	{
		if (IsEnable)
		{
			ShaderProgram->prepareRender();

			glBindBuffer(GL_ARRAY_BUFFER, Buffer);
			glDrawArrays(GL_QUADS, 0, BufferSize / ShaderProgram->DataSize);
		}
	}
};