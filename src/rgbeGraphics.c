#include <glad/glad.h>
#include <rgbeGraphics.h>
#include <stdlib.h>

GLFWwindow* window;

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

}

void rgbeResizeWindow(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
