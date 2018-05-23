#include <stdbool.h>
#include "engine.h"

bool isRunning;

void initEngine(void)
{
    initializeGraphics();
    isRunning = true;
}

void runEngine(void)
{
    while (isRunning) {
        renderGraphics(glfwGetTime());
    }
    shutdownGraphics();
}
