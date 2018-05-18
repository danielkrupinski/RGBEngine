#include "graphics/shader.h"

GLuint graphicsCompileShaders(void)
{
    static const GLchar* vertexShaderSource[] = {
        "#version 460 core                              \n"
        "                                               \n"
        "void main(void)                                \n"
        "{                                              \n"
        "   gl_Position = vec4(0.0, 0.0, 0.5, 1.0);     \n"
        "}                                              \n"
    };

    static const GLchar* fragmentShaderSource[] = {
        "#version 460 core                          \n"
        "                                           \n"
        "out vec4 color;                            \n"
        "                                           \n"
        "void main(void)                            \n"
        "{                                          \n"
        "   color = vec4(0.0, 0.8, 1.0, 1.0);       \n"
        "}                                          \n"
    };

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}
