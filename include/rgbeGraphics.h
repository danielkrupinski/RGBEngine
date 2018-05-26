#ifndef RGBE_GRAPHICS_H
#define RGBE_GRAPHICS_H

#include <GLFW/glfw3.h>

void rgbeInitGraphics(void);
void rgbeRenderGraphics(void);

static void rgbeResizeWindow(GLFWwindow*, int, int);
static void rgbeShutdownGraphics(void);

#endif // RGBE_GRAPHICS_H
