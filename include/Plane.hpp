#ifndef PLANE_HPP
#define PLANE_HPP

#include <iostream>
#include <glad/glad.h>
#include <Shader.hpp>

class Plane {
public:
    Plane();
    void draw();

private:
	GLuint VAO, VBO, EBO;
    Shader shader;

};

#endif
