#ifndef RGBE_GRAPHICS_H
#define RGBE_GRAPHICS_H

#include <GLFW/glfw3.h>

void rgbeInitGraphics(void);
void rgbeRenderGraphics(void);
void rgbeShutdownGraphics(void);

static void rgbeCompileShader(void);
static void rgbeLoadShader(void);
static void rgbeResizeWindow(GLFWwindow*, int, int);

#endif // RGBE_GRAPHICS_H
