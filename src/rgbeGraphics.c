#include <glad/glad.h>
#include <GLFW/glfw3.h>

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
        return 1;
    }
    
    glfwMakeContextCurrent(window);
}
