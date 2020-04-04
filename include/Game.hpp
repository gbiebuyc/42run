#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <Cube.hpp>
#include <GameWindow.hpp>
#include <WorldSlice.hpp>
#include <unistd.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <list>

class Game {
public:
    Game();

private:
    GameWindow myWindow;
    Cube player{{0, 0, 1}};
    glm::mat4 viewMat;
    glm::vec3 playerPos{0, 0.5f, 0};
    std::list<WorldSlice> slices;

    void loop();
    void draw();
    void handleEvents();

};

#endif
