#include <rgbeInput.h>
#include <stdbool.h>

extern GLFWwindow* window;
extern bool isRunning;

void rgbeProcessInput(void)
{
    if (!glfwWindowShouldClose(window)) {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }
    else
        isRunning = false;
}
