#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLFW_WINDOW_SYSTEM

#ifdef GLFW_WINDOW_SYSTEM
    #include "window-system/glfw.h"
    GLFWwindow* window;
#endif

void rgbInit();
