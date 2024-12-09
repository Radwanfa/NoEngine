//
// Created by radwan on 10/23/2024.
//

#ifndef KEY_INPUT_H
#define KEY_INPUT_H
#include "Window.h"


class key_input {
    public:
    static key_input* get();
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    ~key_input();
    static bool getKeyPressed(int key);
    private:
    key_input();
    static key_input* instance;
    bool key_pressed[256];
};



#endif 
