//
// Created by radwan on 10/22/2024.
//

#ifndef MOUSE_INPUT_H
#define MOUSE_INPUT_H
#include "Window.h"


class mouse_input {
    public:
    static mouse_input* get();
    ~mouse_input();
    static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    static float getXPos();
    static void endFrame();
    static float getYPos();
    static float getScrollX();
    static float getScrollY();
    static float getLastX();
    static float getLastY();
    static bool getButtonPressed(int button);
    static bool getIsDragging();
    static float getDxPos();
    static float getDyPos();
    private:
    mouse_input();
    static mouse_input* instance;
    double xpos, ypos;
    bool mouse_pressed[3];
    double lastx, lasty;
    double deltax, deltay;
    double scrollx, scrolly;
    bool isDragging;
};
#endif