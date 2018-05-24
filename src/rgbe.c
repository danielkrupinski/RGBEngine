#include <rgbe.h>
#include <rgbeGraphics.h>
#include <stdbool.h>

bool isRunning = false;

void rgbeInitEngine(void)
{
    rgbeInitGraphics();
    isRunning = true;
}

void rgbeRunEngine(void)
{
    while (isRunning) {
        rgbeRenderGraphics();
    }
    rgbeShutdownGraphics();
}
