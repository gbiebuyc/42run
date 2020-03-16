#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <Plane.hpp>
#include <GameWindow.hpp>
#include <unistd.h>
#include <GLFW/glfw3.h>

class Game {
public:
    Game();

private:
    GameWindow myWindow;
    Plane ground;

    void loop();
    void draw();

};

#endif
