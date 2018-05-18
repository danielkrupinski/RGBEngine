#ifndef RGBE_GRAPHICS_WINDOW_H
#define RGBE_GRAPHICS_WINDOW_H

#include <GLFW/glfw3.h>

GLFWwindow* window;

void graphicsCreateWindow(void);
void graphicsResizeWindow(GLFWwindow*, int, int);

#endif // RGBE_GRAPHICS_WINDOW_H
