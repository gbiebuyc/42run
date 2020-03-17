#include <Game.hpp>

Game::Game() :
    projMat(glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f))
{
    viewMat = glm::mat4(1.0f);
    viewMat = glm::translate(viewMat, glm::vec3(0.0f, 0.0f, -3.0f));
    viewMat = glm::rotate(viewMat, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    loop();
}

void Game::loop(){
    draw();
    sleep(1);
}

void Game::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ground.draw(projMat, viewMat);
    myWindow.swapBuffers();
}
