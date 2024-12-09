//
// Created by radwanfa on 12/3/24.
//

#ifndef STRUCTS_H
#define STRUCTS_H
#include <vector>
#include <glm/glm.hpp>


typedef struct vertex {
    glm::vec2 pos;
    glm::vec3 col;
} vertex;

typedef struct mesh {
    std::vector<vertex>* vertices;
    std::vector<unsigned int>* indices;
} mesh;
#endif //STRUCTS_H