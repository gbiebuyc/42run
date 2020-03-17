#include <Game.hpp>

Game::Game() :
    projMat(glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f))
{
    glm::mat4 modelMat = glm::mat4(1.0f);
    modelMat = glm::translate(modelMat, playerPos);
    modelMat = glm::scale(modelMat, glm::vec3(0.3, 0.5, 0.3));
    player.setModelMat(modelMat);

    modelMat = glm::mat4(1.0f);
    modelMat = glm::translate(modelMat, glm::vec3(0.0f, 0.0f, -10.0f));
    modelMat = glm::scale(modelMat, glm::vec3(0.2, 0.2, 0.2));
    test.setModelMat(modelMat);

    modelMat = glm::mat4(1.0f);
    modelMat = glm::translate(modelMat, glm::vec3(0.0f, 0.0f, -10.0f));
    modelMat = glm::scale(modelMat, glm::vec3(2, 0.1, 20));
    ground.setModelMat(modelMat);

    glEnable(GL_DEPTH_TEST);
    loop();
}

void Game::loop(){
    while (!glfwWindowShouldClose(myWindow.window))
	{
		glfwPollEvents();
		handleEvents();
        playerPos.z -= 0.1;
        viewMat = glm::mat4(1.0f);
        viewMat = glm::rotate(viewMat, glm::radians(10.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        viewMat = glm::translate(viewMat, glm::vec3(0.0f, -1.5f, -(playerPos.z + 3.5f)));

        // Move player
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
    ground.draw(projMat, viewMat);
    player.draw(projMat, viewMat);
    test.draw(projMat, viewMat);
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
