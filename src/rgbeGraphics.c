#include <glad/glad.h>
#include <math.h>
#include <rgbeGraphics.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern bool isRunning;

GLFWwindow* window;

static unsigned int vbo;
static unsigned int vao;
static unsigned int shaderProgram;
static const char* vertexShaderSource;
static const char* fragmentShaderSource;

void rgbeInitGraphics(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "RGBEngine", NULL, NULL);

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
    rgbeLoadShader();
    rgbeCompileShader();
}

void rgbeRenderGraphics(void)
{
    if (!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    else
        isRunning = false;
}

void rgbeShutdownGraphics(void)
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glfwTerminate();
}

static void rgbeCompileShader(void)
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", infoLog);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
    };

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glUseProgram(shaderProgram);
}

static void rgbeLoadShader(void)
{
    FILE* vertexShaderFile = fopen("vertexShader.vs", "r");
    if (!vertexShaderFile) {
        printf("Failed to open vertexShader.vs!\n");
        exit(1);
    }

    FILE* fragmentShaderFile = fopen("fragmentShader.fs", "r");
    if (!fragmentShaderFile) {
        printf("Failed to open fragmentShader.fs!\n");
        exit(1);
    }

    fseek(vertexShaderFile, 0L, SEEK_END);
    long vertexShaderFileSize = ftell(vertexShaderFile);
    rewind(vertexShaderFile);
    vertexShaderSource = calloc(vertexShaderFileSize + 1, 1);
    fread((char*)vertexShaderSource, 1, vertexShaderFileSize, vertexShaderFile);
    fclose(vertexShaderFile);

    fseek(fragmentShaderFile, 0L, SEEK_END);
    long fragmentShaderFileSize = ftell(fragmentShaderFile);
    rewind(fragmentShaderFile);
    fragmentShaderSource = calloc(fragmentShaderFileSize + 1, 1);
    fread((char*)fragmentShaderSource, 1, fragmentShaderFileSize, fragmentShaderFile);
    fclose(fragmentShaderFile);
}

static void rgbeResizeWindow(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
