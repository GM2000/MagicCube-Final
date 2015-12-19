
#include "Shader.h"

int lastUseShader	=	-1;

//∆’Õ®3D

void normail3DUse(GLuint ProgramID)
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	if ((lastUseShader != 0) || Camera.hasCameraChange())
	{
		glUniformMatrix4fv(UniformLocation[0], 1, GL_TRUE, glm::value_ptr(Camera.GobalProjection));
		glUniformMatrix4fv(UniformLocation[1], 1, GL_TRUE, glm::value_ptr(Camera.readGobalTranslate()));
		glUniformMatrix4fv(UniformLocation[2], 1, GL_TRUE, glm::value_ptr(Camera.readGobalRotate()));

		glUseProgram(ProgramID);

		lastUseShader = 0;
	}
}