
#include "Shader.h"

//∆’Õ®3D
void normail3DSet()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)(12 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}
void normail3DPrepare(GLuint ProgramID)
{
	glUniformMatrix4fv(UniformLocation[0], 1, GL_TRUE, glm::value_ptr(GobalProjection));
	glUniformMatrix4fv(UniformLocation[1], 1, GL_TRUE, glm::value_ptr(GobalTranslate));
	glUniformMatrix4fv(UniformLocation[2], 1, GL_TRUE, glm::value_ptr(GobalRotate));

	glUseProgram(ProgramID);
}