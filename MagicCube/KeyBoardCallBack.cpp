
#include "Render.h"

void KeyBoardCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	GobalProjection = glm::perspective(45.0f, (GLfloat)640 / (GLfloat)480, 0.1f, 500.0f);
	GobalTranslate = glm::translate(glm::mat4(), glm::vec3(0.0, 0.0, 0.0));
	GobalRotate = glm::rotate_slow(glm::mat4(), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}