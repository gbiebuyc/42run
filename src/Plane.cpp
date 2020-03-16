#include <Plane.hpp>

Plane::Plane() :
    shader("shaders/plane.vs", "shaders/plane.fs")
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
  
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    float vertices[] = {
        0, 0, 0,
        1, 0, 0,
        1, -1, 0,
        0, -1, 0,
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4 * 3, vertices, GL_STATIC_DRAW);  

    // vertex positions
    glEnableVertexAttribArray(0);	
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glBindVertexArray(0);
}

void Plane::draw() {
    glUseProgram(shader.ID);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}
