
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

glm::mat4 Projection;

void windowResizeCallBack(GLFWwindow* window, int WindowsWidth, int WindowsHeight)
{
	Projection = glm::perspective(45.0f, (GLfloat)WindowsWidth / (GLfloat)WindowsHeight, 0.1f, 500.0f);
}