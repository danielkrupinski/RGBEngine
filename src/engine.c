#include "engine.h"

void initializeEngine(void)
{
    initializeGraphics();
    isRunning = true;
}

void runEngine(void)
{
    while (isRunning) {
        renderGraphics(glfwGetTime());
    }
}
