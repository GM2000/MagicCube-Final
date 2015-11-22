#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <list>
#include <vector>

struct mouseLoc
{
	double X;
	double Y;
};

extern int WindowWidth;
extern int WindowHeight;

extern GLFWwindow* window;
extern mouseLoc Mouse;
extern bool Keys[512];
