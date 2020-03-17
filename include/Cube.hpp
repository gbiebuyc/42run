#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <glad/glad.h>
#include <Shader.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Cube {
public:
    Cube();
    void draw(glm::mat4 projMat, glm::mat4 viewMat);

private:
	GLuint VAO, VBO, EBO;
    Shader shader;
    glm::mat4 modelMat;

};

#endif
