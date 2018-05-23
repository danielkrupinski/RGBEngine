#ifndef RGBE_GRAPHICS_H
#define RGBE_GRAPHICS_H

#include "shader.h"
#include "window.h"

void initGraphics(void);

void renderGraphics(double);

void shutdownGraphics(void);

void graphicsInitializeGlad(void);

#endif // RGBE_GRAPHICS_H
