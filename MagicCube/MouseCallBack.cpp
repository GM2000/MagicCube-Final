
#include "MagicCube.h"

mouseLoc Mouse;

void MouseCallBack(GLFWwindow* Window, double XPos, double YPos)
{
	Mouse.X = XPos;
	Mouse.Y = YPos;
}
