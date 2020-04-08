#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <glad/glad.h>
#include <Shader.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <array>

class Cube {
public:
    Cube(std::array<float, 3> color);
    void draw(glm::mat4 viewMat) const;
    void setModelMat(glm::mat4 &modelMat);

private:
    GLuint VAO, VBO, EBO;
    Shader shader;
    glm::mat4 modelMat;
    std::array<float, 3> color;

};

#endif
