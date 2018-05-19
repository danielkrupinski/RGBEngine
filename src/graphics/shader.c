#include "graphics/shader.h"

GLuint graphicsCompileShaders(void)
{
    static const GLchar* vertexShaderSource[] = {
        "#version 460 core                                                      \n"
        "                                                                       \n"
        "void main(void)                                                        \n"
        "{                                                                      \n"
        "   const vec4 vertices[3] = vec4[3](vec4(0.25, -0.25, 0.5, 1.0),       \n"
        "                                     vec4(-0.25, -0.25, 0.5, 1.0),     \n"
        "                                     vec4(0.25, 0.25, 0.5, 1.0));      \n"
        "   gl_Position = vertices[gl_VertexID];                                \n"
        "}                                                                      \n"
    };

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, vertexShaderSource, NULL);
    glCompileShader(vertexShader);

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

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    static const GLchar* tessellationShaderSource[] = {
        "#version 460 core                                                                 \n"
        "                                                                                  \n"
        "layout (vertices = 3) out;                                                        \n"
        "                                                                                  \n"
        "void main(void)                                                                   \n"
        "{                                                                                 \n"
        "    if (gl_InvocationID == 0) {                                                   \n"
        "        gl_TessLevelInner[0] = 5.0;                                               \n"
        "        gl_TessLevelOuter[0] = 5.0;                                               \n"
        "        gl_TessLevelOuter[1] = 5.0;                                               \n"
        "        gl_TessLevelOuter[2] = 5.0;                                               \n"
        "    }                                                                             \n"
        "    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;     \n"
        "}                                                                                 \n"
    };

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}
