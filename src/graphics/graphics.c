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
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    else
        isRunning = false;
}

void shutdownGraphics(void)
{
    glfwTerminate();
}
