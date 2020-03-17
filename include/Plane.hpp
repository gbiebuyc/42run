#ifndef PLANE_HPP
#define PLANE_HPP

#include <iostream>
#include <glad/glad.h>
#include <Shader.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Plane {
public:
    Plane();
    void draw(glm::mat4 projMat, glm::mat4 viewMat);

private:
	GLuint VAO, VBO, EBO;
    Shader shader;

};

#endif
