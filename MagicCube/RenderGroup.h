#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

extern glm::mat4 Projection;

//加载Shader所需的结构
typedef struct
{
	GLenum       type;
	const char*  filename;
	GLuint       shader;
} shaderInfo;
//加载Shader的函数
GLuint loadShaders(shaderInfo* shaders);

class shader
{
public:
	unsigned int ShaderProgramID = 0;
	unsigned int InputDataType	 = 0;

	shader() {}

	shader(std::string ShaderName, int InputDataType)
	{
		shader::InputDataType = InputDataType;

		ShaderName = "GLSL\\" + ShaderName;

		std::string Vert = ShaderName;
		Vert.append(".vert");
		std::string Frag = ShaderName;
		Frag.append(".frag");

		shaderInfo  shaders[] = {
			{ GL_VERTEX_SHADER, Vert.c_str() },
			{ GL_FRAGMENT_SHADER, Frag.c_str() },
			{ GL_NONE, NULL } };

		ShaderProgramID = loadShaders(shaders);
	}
};

class renderGroup
{
	glm::mat4 TransportMatrix = glm::translate(glm::mat4(), glm::vec3(0.0, 0.0, 0.0));
	glm::mat4 RotateMatrix = glm::rotate_slow(glm::mat4(), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	shader	Shader;
	GLuint	Buffer = 0;
	GLuint  BufferSize = 0;
public:
	bool	IsEnable = false;

	void setShader(shader Shader)
	{
		renderGroup::Shader = Shader;
	}
	void setData(std::vector<GLfloat> RenderData)
	{
		//普通
		glGenBuffers(1, &Buffer);
		glBindBuffer(GL_ARRAY_BUFFER, Buffer);

		glBufferData(GL_ARRAY_BUFFER, RenderData.size() * sizeof(GLfloat), &RenderData[0], GL_STATIC_DRAW);

		switch (Shader.InputDataType)
		{
		case 0:
			glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, 0, (GLvoid*)0);
			glEnableVertexAttribArray(0);
		}

		BufferSize = RenderData.size();
	}
	void draw()
	{
		if (IsEnable)
		{
			glUseProgram(Shader.ShaderProgramID);
			glBindBuffer(GL_ARRAY_BUFFER, Buffer);

			glDrawArrays(GL_QUADS, 0, BufferSize);
		}
	}
};