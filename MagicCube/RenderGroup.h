#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

extern glm::mat4 Projection;

class renderGroup
{
	glm::mat4 TransportMatrix = glm::translate(glm::mat4(), glm::vec3(0.0, 0.0, 0.0));
	glm::mat4 RotateMatrix = glm::rotate_slow(glm::mat4(), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	GLuint	Shader = 0;
	GLuint	Buffer = 0;
	GLuint  BufferSize = 0;
public:
	bool	IsEnable = false;

	void setShader(GLuint Shader)
	{
		renderGroup::Shader = Shader;
	}
	void setData(std::vector<GLfloat> RenderData)
	{
		//∆’Õ®
		glGenBuffers(1, &Buffer);
		glBindBuffer(GL_ARRAY_BUFFER, Buffer);

		glBufferData(GL_ARRAY_BUFFER, RenderData.size() * sizeof(GLfloat), &RenderData[0], GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT,
			GL_FALSE, 0, (GLvoid*)0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)(RenderData.size() * 12 * sizeof(GLfloat)));

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		BufferSize = RenderData.size();
	}
	void draw()
	{
		if (IsEnable)
		{
			glUseProgram(Shader);
			glBindBuffer(GL_ARRAY_BUFFER, Buffer);

			glDrawArrays(0, BufferSize, GL_QUADS);
		}
	}
};