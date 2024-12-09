//
// Created by radwanfa on 12/2/24.
//
#include <glad/glad.h>
#include "../../../include/circle.h"
#include "../../../include/shader.h"
#include <iostream>
#include <cmath>
#include <iomanip>

#include "../../../include/Window.h"

using namespace std;

mesh* circle::circle_mesh = new mesh();
unsigned int* circle::count = new unsigned int();
float* circle::radius = new float();


circle::circle(float radius, unsigned int count) {
    this->instance = Window::get();
    *circle::count = count;
    *circle::radius = radius;
    circle_mesh->vertices = new vector<vertex>;
    circle_mesh->indices = new vector<unsigned int>;
    start = new vertex();
    *start = {{0.0f, 0.0f}, {0.0f, 1.0f, 1.0f}};
    configure();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, (circle_mesh->vertices->size()*sizeof(vertex)), circle_mesh->vertices->data(), GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, (circle_mesh->indices->size()*sizeof(unsigned int)), circle_mesh->indices->data(), GL_DYNAMIC_DRAW);

    Shader = new shader("../shaders/vertex.glsl", "../shaders/fragment.glsl");
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,  sizeof(vertex), offsetof(vertex, pos));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof(vertex), reinterpret_cast<void *>(offsetof(vertex, col)));
    glEnableVertexAttribArray(1);


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

void circle::configure() {
    for (int i = 0; i <= *circle::count; i++) {
        circle_mesh->vertices->push_back({{
            start->pos.x + (((*circle::radius) / instance->width * instance->height) * cos(i * (2 * (numbers::pi)) / *(circle::count))),
            start->pos.y + (*circle::radius * sin(i * (2 * (numbers::pi)) / *(circle::count)))},
            {0.0f, 1.0f, 1.0f}});
        circle_mesh->indices->push_back(0);
        circle_mesh->indices->push_back(i);
        circle_mesh->indices->push_back(i + 1);
    }
    for (int i = 1; i < circle_mesh->vertices->size(); i++) {
        cout << "x: " << (*circle_mesh->vertices)[i].pos.x << " y: " << (*circle_mesh->vertices)[i].pos.y << endl;
    }
}


void circle::draw() {
    Shader->use();
    glBindVertexArray(VAO);

    glDrawElements(GL_TRIANGLE_FAN, circle_mesh->indices->size(), GL_UNSIGNED_INT, nullptr);
}

mesh* circle::get_mesh() {
    return circle_mesh;
}

circle::~circle() {
    delete count;
    delete radius;
    delete circle_mesh;
}