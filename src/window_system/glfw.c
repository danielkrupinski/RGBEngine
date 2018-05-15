#include <GLFW/glfw3.h>
#include "window-system/glfw.h"

GLFWwindow* rgbCreateWindow(int width, int height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW Window", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return window;
    }

    glfwMakeCurentContext(window);
    return window;
}
