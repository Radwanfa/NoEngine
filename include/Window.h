//
// Created by Radwan on 10/18/2024.
//

#ifndef WINDOW_H
#define WINDOW_H
#include "shader.h"
#include <GLFW/glfw3.h>
#include <string>
#include "circle.h"



static vertex vertices[] = {
    {{0.5f, 0.5f}, {0.0f, 0.0f, 0.0f}},
     {{0.5f, -0.5f}, {1.0f, 0.0f, 1.0f}},
     {{-0.5f,  -0.5f}, {0.5f, 1.0f, 2.0f}},
    {{-0.5f, 0.5f}, {1.0f, 0.0f, 0.2f}}
};

static unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};
class Window {
public:
    int width;
    int height;
    private:
        static Window* object;
        int  success;
        char infoLog[512];
        Window();
        shader* Shader;
        circle* Circle;
        std::string title;
        int init();
        int loop();
        GLFWwindow* window;
        bool fadeToBlack;
    unsigned int fragmentShader;
    unsigned int vertexShader;
    unsigned int shaderProgram;
        unsigned int VBO, EBO, VAO;

        float r;
        float b;
        float g;
        float a;
        
    public:
        static Window* get();
        static void ErrorCallback(int error, const char* description);
    static void glGetFrameBufferSize(GLFWwindow* window, int width, int height);
        int run();
        ~Window();
};
#endif
