#include <stdbool.h>
#include "engine.h"

bool isRunning;

void rgbeInit(void)
{
    initGraphics();
    isRunning = true;
}

void rgbeRun(void)
{
    while (isRunning) {
        renderGraphics(glfwGetTime());
    }
    shutdownGraphics();
}
