//
// Created by radwan on 10/18/2024.
//
#include <glad/glad.h>
#include "../../include/Window.h"

#include <linmath.h>
#include <cmath>
#include <iostream>
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include <array>

#include "../../include/circle.h"

#include FT_FREETYPE_H

#include "../../include/key_input.h"
#include "../../include/mouse_input.h"
#include "../../include/shader.h"
using namespace std;

Window* Window::object = nullptr;

Window::Window() {
    width = 1920;
    height = 1080;
    this->title = "GLFW IS TRASH";
    this->fadeToBlack = false;
    this->r = 1.0f;
    this->g = 1.0f;
    this->b = 1.0f;
    this->a = 1.0f;
    this->window = nullptr;
}

Window* Window::get() {
    if (Window::object == nullptr) {
        Window::object = new Window();
    }
    return Window::object;
}

void Window::ErrorCallback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

void Window::glGetFrameBufferSize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}


int Window::run() {
    Window::init();
    Window::loop();
    return 0;
}
int Window::init() {
    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }
    Window::window = glfwCreateWindow(Window::width, Window::height, Window::title.c_str(), nullptr, nullptr);
    if (!Window::window) {
        glfwTerminate();
        cerr << "Failed to create GLFW window" << endl;
        return -1;
    }
    glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);

    glfwSetCursorPosCallback(Window::window, mouse_input::cursorPosCallback);
    glfwSetMouseButtonCallback(Window::window, mouse_input::mouseButtonCallback);
    glfwSetScrollCallback(Window::window, mouse_input::scrollCallback);
    glfwSetKeyCallback(Window::window, key_input::keyCallback);
    glfwSetErrorCallback(Window::ErrorCallback);
    glfwSetFramebufferSizeCallback(Window::window, Window::glGetFrameBufferSize);
    glfwMakeContextCurrent(Window::window);

    gladLoadGL();

    Circle = new circle(0.5f, 1000);


    return 0;
}

int Window::loop() {
    auto beginTime = static_cast<float>(glfwGetTime());
    float lastTime;
    float dt;

    while (!glfwWindowShouldClose(get()->window)) {;
        // int width, height;
        glfwGetFramebufferSize(get()->window, &width, &height);
        const float ratio = width / (float) height;
        //cout << "ratio: " << ratio << endl;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        Circle->draw();

        glfwPollEvents();
        glfwSwapBuffers(get()->window);
        lastTime = static_cast<float>(glfwGetTime());
        dt = lastTime - beginTime;
        beginTime = lastTime;
    }
    glfwDestroyWindow(Window::window);
    glfwTerminate();
    return 0;
}

Window::~Window() {
}