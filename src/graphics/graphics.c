#include "graphics/graphics.h"
#include "graphics/glad.h"
#include "graphics/window.h"

void initializeGraphics(void)
{
    graphicsCreateWindow();
    graphicsInitializeGlad();
}
