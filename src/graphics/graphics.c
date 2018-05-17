#include "graphics/graphics.h"

void initializeGraphics(void)
{
    graphicsCreateWindow();
    graphicsInitializeGlad();
    glViewport(0, 0, 800, 600);
}

void renderGraphics(void)
{
    
}
