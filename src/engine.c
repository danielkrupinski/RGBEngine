#include "engine.h"

void initializeEngine(void)
{
    initializeGraphics();
}

void runEngine(void)
{
    while(!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
