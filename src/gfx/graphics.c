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

void graphicsCreateWindow(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "RGBEngine", NULL, NULL);

    if (!window) {
        fprintf(stderr, "Failed to create GLFW window!\n");
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, graphicsResizeWindow);
}

void graphicsResizeWindow(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
