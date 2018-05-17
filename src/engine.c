#include "engine.h"

bool isRunning;

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
