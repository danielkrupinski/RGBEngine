#include <glad/glad.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "gfx/graphics.h"

extern bool isRunning;
GLuint renderingProgram;
GLuint vertexArrayObject;

void initGraphics(void)
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
        const GLfloat color[] = { 0.0f, 0.2f, 0.0f, 1.0f };
        glClearBufferfv(GL_COLOR, 0, color);
        glUseProgram(renderingProgram);
        glDrawArrays(GL_PATCHES, 0, 3);
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

void graphicsInitializeGlad(void)
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        fprintf(stderr, "Failed to initialize GLAD!\n");
}
