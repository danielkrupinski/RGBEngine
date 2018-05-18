#include <glad/glad.h>
#include <math.h>
#include <stdbool.h>
#include "graphics/graphics.h"

extern bool isRunning;
GLuint renderingProgram;
GLuint vertexArrayObject;

void initializeGraphics(void)
{
    graphicsCreateWindow();
    graphicsInitializeGlad();
    glViewport(0, 0, 800, 600);
    renderingProgram = graphicsCompileShaders();
    glCreateVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);
}

void renderGraphics(double currentTime)
{
    if (!glfwWindowShouldClose(window)) {
        const GLfloat color[] = { (float)sin(currentTime) * 0.5f + 0.5f,
                                  (float)cos(currentTime) * 0.5f + 0.5f,
                                  0.0f, 1.0f };
        glClearBufferfv(GL_COLOR, 0, color);
        glUseProgram(renderingProgram);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    else
        isRunning = false;
}

void shutdownGraphics(void)
{
    glDeleteVertexArrays(1, &vertexArrayObject);
    glDeleteProgram(renderingProgram);
    glfwTerminate();
}
