#include <Game.hpp>

Game::Game() {
    for (int i = 0; i < 2; i++) {
        slices.push_front(WorldSlice());
    }
    glEnable(GL_DEPTH_TEST);
    loop();
}

void Game::loop(){
    while (!glfwWindowShouldClose(myWindow.window))
	{
		glfwPollEvents();
		handleEvents();
        playerPos.z -= 0.1;

        // Create view matrix
        viewMat = glm::mat4(1.0f);
        viewMat = glm::rotate(viewMat, glm::radians(10.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        viewMat = glm::translate(viewMat, glm::vec3(0.0f, -1.5f, -(playerPos.z + 3.0f)));

        // Create model matrix of player
        glm::mat4 modelMat = glm::mat4(1.0f);
        modelMat = glm::translate(modelMat, playerPos);
        modelMat = glm::scale(modelMat, glm::vec3(0.3, 0.5, 0.3));
        player.setModelMat(modelMat);

        draw();
        usleep(16000);
	}
}

void Game::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glm::mat4 viewMat = this->viewMat;
    player.draw(viewMat);
    auto it = slices.begin();
    it->draw(viewMat);
    for (it++; it != slices.end(); it++) {
        viewMat = glm::translate(viewMat, glm::vec3(0.0f, 0.0f, -it->getLength()));
        viewMat = glm::rotate(viewMat, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); 
        it->draw(viewMat);
    }
    myWindow.swapBuffers();
}

void Game::handleEvents()
{
    float speed = 0.03f;
	if (glfwGetKey(myWindow.window, GLFW_KEY_LEFT) == GLFW_PRESS)
        playerPos.x -= speed;
	if (glfwGetKey(myWindow.window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        playerPos.x += speed;
}
