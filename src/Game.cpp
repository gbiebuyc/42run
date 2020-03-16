#include <Game.hpp>

Game::Game() {
    loop();
}

void Game::loop(){
    draw();
    sleep(1);
}

void Game::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ground.draw();
    myWindow.swapBuffers();
}
