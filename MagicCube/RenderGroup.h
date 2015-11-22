#pragma once

#include "Shader.h"

class renderGroup
{
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

		BufferSize =(GLuint)RenderData->size();
	}
	void draw()
	{
		if (IsEnable)
		{
			glUniformMatrix4fv(ShaderProgramID->UniformLocation[0], 1, GL_TRUE, glm::value_ptr(GobalProjection));
			glUniformMatrix4fv(ShaderProgramID->UniformLocation[1], 1, GL_TRUE, glm::value_ptr(GobalTranslate));
			glUniformMatrix4fv(ShaderProgramID->UniformLocation[2], 1, GL_TRUE, glm::value_ptr(GobalRotate));
			GLfloat ee[] = { 1.0,0.0,1.0 };
			glUniform3fv(ShaderProgramID->UniformLocation[1], 1, ee);

 			glUseProgram(ShaderProgramID->ProgramID);
			glBindBuffer(GL_ARRAY_BUFFER, Buffer);

			glDrawArrays(GL_QUADS, 0, BufferSize/3);
		}
	}
};