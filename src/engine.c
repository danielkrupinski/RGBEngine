#include <stdbool.h>
#include "engine.h"

bool isRunning;

void initEngine(void)
{
    initGraphics();
    isRunning = true;
}

void runEngine(void)
{
    while (isRunning) {
        renderGraphics(glfwGetTime());
    }
    shutdownGraphics();
}
