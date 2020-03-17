#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <Cube.hpp>
#include <GameWindow.hpp>
#include <unistd.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <array>

class Game {
public:
    Game();

private:
    GameWindow myWindow;
    Cube ground{{0, 1, 0}};
    Cube player{{0, 0, 1}};
    Cube test{{1, 0, 1}};
    glm::mat4 projMat, viewMat;
    glm::vec3 playerPos{0, 0.5f, 0};

    void loop();
    void draw();
    void handleEvents();

};

#endif
