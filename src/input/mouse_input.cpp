//
// Created by radwan on 10/22/2024.
//

#include "../../include/mouse_input.h"

#include <iostream>

mouse_input* mouse_input::instance = nullptr;

mouse_input::mouse_input() {
    this->deltax, this->deltay = 0.0;
    this->xpos, this->ypos = 0.0;
    this->lastx, this->lasty = 0.0;
    this->scrollx, this->scrolly = 0.0;
    this->isDragging = false;
}

mouse_input* mouse_input::get() {
    if (instance == nullptr) {
        instance = new mouse_input();
    }
    return instance;
}

void mouse_input::cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    get()->lastx = get()->xpos;
    get()->lasty = get()->ypos;
    get()->xpos = xpos;
    get()->ypos = ypos;
    get()->deltax = xpos - get()->lastx;
    get()->deltay = ypos - get()->lasty;
    get()->isDragging = get()->mouse_pressed[0] || get()->mouse_pressed[1] || get()->mouse_pressed[2];
}

void mouse_input::scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    get()->scrollx = xoffset;
    get()->scrolly = yoffset;
}

void mouse_input::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        if (button < sizeof(get()->mouse_pressed)) {
            get()->mouse_pressed[button] = true;
        }
    } else if (action == GLFW_RELEASE) {
        if (button < sizeof(get()->mouse_pressed)) {
            get()->mouse_pressed[button] = false;
            get()->isDragging = false;
        }
    }
}

void mouse_input::endFrame() {
    get()->lastx = get()->xpos;
    get()->lasty = get()->ypos;
    get()->xpos = 0.0;
    get()->ypos = 0.0;
}

float mouse_input::getXPos() {
    return static_cast<float>(get()->xpos);
}

float mouse_input::getYPos() {
    return static_cast<float>(get()->ypos);
}

float mouse_input::getScrollX() {
    return static_cast<float>(get()->scrollx);
}

float mouse_input::getScrollY() {
    return static_cast<float>(get()->scrolly);
}

bool mouse_input::getIsDragging() {
    return get()->isDragging;
}

bool mouse_input::getButtonPressed(const int button) {
    if (button < sizeof(get()->mouse_pressed)) {
        return get()->mouse_pressed[button];
    }
    return false;
}

float mouse_input::getDxPos() {
    return static_cast<float>(get()->deltax);
}

float mouse_input::getDyPos() {
    return static_cast<float>(get()->deltay);
}

float mouse_input::getLastX() {
    return static_cast<float>(get()->lastx);
}

float mouse_input::getLastY() {
    return static_cast<float>(get()->lasty);
}

mouse_input::~mouse_input() {
    delete instance;
}