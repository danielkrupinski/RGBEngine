#include <glad/glad.h>
#include "graphics/glad.h"
#include <stdio.h>

void graphicsInitializeGlad(void)
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        fprintf(stderr, "Failed to initialize GLAD!\n");
}
