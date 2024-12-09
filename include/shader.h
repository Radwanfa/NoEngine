//
// Created by radwanfa on 12/2/24.
//

#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <glad/glad.h>


class shader {
    public:
    GLuint ID;

    shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    void use();
    void setBool(const std::string& name, bool value);
    void setInt(const std::string& name, int value);
    void setFloat(const std::string& name, float value);
};



#endif //SHADER_H
