//
// Created by radwanfa on 12/2/24.
//

#ifndef CIRCLE_H
#define CIRCLE_H


#include "shader.h"
#include "structs.h"


class circle {
public:
    static mesh* circle_mesh;
    static unsigned int* count;
    Window* instance;
    unsigned int VAO, VBO, EBO;
    vertex* start;
    void* pointer;
    static float* radius;
    shader* Shader;
    circle(float radius, unsigned int count);
    void draw();
    void configure();
    mesh* get_mesh();
    ~circle();
};



#endif //CIRCLE_H
