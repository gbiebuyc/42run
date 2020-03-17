#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <Plane.hpp>
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
    glm::mat4 projMat, viewMat;

    void loop();
    void draw();

};

#endif
