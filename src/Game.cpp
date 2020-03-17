#include <Game.hpp>

Game::Game() :
    projMat(glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f))
{
    glEnable(GL_DEPTH_TEST);
    loop();
}

void Game::loop(){
    while (!glfwWindowShouldClose(myWindow.window))
	{
		glfwPollEvents();
		//handle_events(d);
        z -= 0.1;
    viewMat = glm::mat4(1.0f);
    viewMat = glm::rotate(viewMat, glm::radians(10.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    viewMat = glm::translate(viewMat, glm::vec3(0.0f, -1.0f, -z));
        draw();
        usleep(100000);
	}
}

void Game::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ground.draw(projMat, viewMat);
    player.draw(projMat, viewMat);
    myWindow.swapBuffers();
}
