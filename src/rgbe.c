#include <rgbe.h>
#include <rgbeGraphics.h>
#include <rgbeInput.h>
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
        rgbeProcessInput();
        rgbeRenderGraphics();
    }
    rgbeShutdownGraphics();
}
