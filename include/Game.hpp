#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <Plane.hpp>
#include <Cube.hpp>
#include <GameWindow.hpp>
#include <unistd.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Game {
public:
    Game();

private:
    GameWindow myWindow;
    Plane ground;
    Cube player;
    glm::mat4 projMat, viewMat;
    double z = 3.0;

    void loop();
    void draw();

};

#endif
