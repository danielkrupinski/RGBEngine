#include "graphics/graphics.h"

extern bool isRunning;

void initializeGraphics(void)
{
    graphicsCreateWindow();
    graphicsInitializeGlad();
    glViewport(0, 0, 800, 600);
}

void renderGraphics(void)
{
    if (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    else
        isRunning = false;
}
