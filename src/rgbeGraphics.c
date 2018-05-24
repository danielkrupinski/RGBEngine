#include <glad/glad.h>
#include <rgbeGraphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

GLFWwindow* window;
extern bool isRunning;

void rgbeInitGraphics(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    window = glfwCreateWindow(800, 600, "OpenGL 4.6 Window", NULL, NULL);

    if (!window) {
        printf("Failed to create GLFW window!\n");
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD!\n");
        glfwTerminate();
        exit(1);
    }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, rgbeResizeWindow);
}

void rgbeRenderGraphics(void)
{
    if (!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    else
        isRunning = false;
}

void rgbeResizeWindow(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void rgbeShutdownGraphics(void)
{
    glfwTerminate();
}
