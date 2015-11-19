#pragma once

#include "Shader.h"
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

extern glm::mat4 Projection;

class renderGroup
{
	glm::mat4 TransportMatrix = glm::translate(glm::mat4(), glm::vec3(0.0, 0.0, 0.0));
	glm::mat4 RotateMatrix = glm::rotate_slow(glm::mat4(), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	shader	*ShaderProgramID= 0;
	GLuint	Buffer			= 0;
	GLuint  BufferSize		= 0;
public:
	bool	IsEnable = false;

	void setShader(shader *ShaderProgramID)
	{
		renderGroup::ShaderProgramID = ShaderProgramID;
	}
	void setData(std::vector<GLfloat> *RenderData)
	{
		//ÆÕÍ¨
		glGenBuffers(1, &Buffer);
		glBindBuffer(GL_ARRAY_BUFFER, Buffer);

		glBufferData(GL_ARRAY_BUFFER, RenderData->size() * sizeof(GLfloat), &RenderData->at(0), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, 0, (GLvoid*)0);
		glEnableVertexAttribArray(0);

		BufferSize = RenderData->size();
	}
	void draw()
	{
		if (IsEnable)
		{
			glUniformMatrix4fv(ShaderProgramID->UniformLocation[0], 1, GL_TRUE, glm::value_ptr(Projection));

 			glUseProgram(ShaderProgramID->ProgramID);
			glBindBuffer(GL_ARRAY_BUFFER, Buffer);

			glDrawArrays(GL_QUADS, 0, BufferSize/3);
		}
	}
};