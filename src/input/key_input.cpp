//
// Created by radwan on 10/23/2024.
//

#include "../../include/key_input.h"
key_input* key_input::instance = nullptr;

key_input::key_input() {
    std::fill(std::begin(this->key_pressed), std::end(this->key_pressed), false);
}

key_input *key_input::get() {
    if (instance == nullptr) {
        instance = new key_input();
    } else {
        return instance;
    }
    return instance;
}

void key_input::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        get()->key_pressed[key] = true;
    } else if (action == GLFW_RELEASE) {
        get()->key_pressed[key] = false;
    }
}


bool key_input::getKeyPressed(int key) {
    return get()->key_pressed[key];
}
