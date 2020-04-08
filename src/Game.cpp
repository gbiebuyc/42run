#include <Game.hpp>

Game::Game() {
    std::srand(std::time(0));
    WorldSlice newSlice;
    for (int i = 0; i < 3; i++) {
        newSlice = WorldSlice();
        newSlice.is_first = !i;
        slices.push_back(newSlice);
    }
    glEnable(GL_DEPTH_TEST);
    loop();
}

void Game::loop(){
    int camRotY = 0;
    while (!glfwWindowShouldClose(myWindow.window))
    {
        glfwPollEvents();
        handleEvents();
        playerPos.z -= 0.1;
        WorldSlice &currentSlice = *std::next(slices.begin());
        if (-playerPos.z >= currentSlice.getLength()) {
            camRotY = currentSlice.getDirection();
            slices.pop_front();
            WorldSlice newSlice = WorldSlice();
            newSlice.is_first = false;
            slices.push_back(newSlice);
            if (camRotY < 0) {
                playerPos.z = -playerPos.x;
                playerPos.x = 0;
            } else if (camRotY > 0) {
                playerPos.z = playerPos.x;
                playerPos.x = 0;
            } else {
                playerPos.z = 0;
            }
        }
        #define ROT_SPEED 3
        if (camRotY < 0)
            camRotY += ROT_SPEED;
        if (camRotY > 0)
            camRotY -= ROT_SPEED;

        // Create view matrix
        viewMat = glm::mat4(1.0f);
// #define VIEW_FAR
#ifdef VIEW_FAR
        viewMat = glm::rotate(viewMat, glm::radians(30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        viewMat = glm::translate(viewMat, glm::vec3(0.0f, -10.0f, -(playerPos.z + 20.0f)));
#else
        viewMat = glm::rotate(viewMat, glm::radians(12.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        viewMat = glm::translate(viewMat, glm::vec3(0.0f, -2.0f, -(playerPos.z + 5.0f)));
#endif
        viewMat = glm::rotate(viewMat, glm::radians((float)camRotY ), glm::vec3(0.0f, 1.0f, 0.0f));

        // Create model matrix of player
        glm::mat4 modelMat = glm::mat4(1.0f);
        modelMat = glm::translate(modelMat, playerPos);
        modelMat = glm::scale(modelMat, glm::vec3(0.3, PLAYER_HEIGHT, 0.3));
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
    viewMat = glm::rotate(viewMat, glm::radians(-(float)it->getDirection()), glm::vec3(0.0f, 1.0f, 0.0f));
    viewMat = glm::translate(viewMat, glm::vec3(0.0f, 0.0f, it->getLength()));
    for (; it != slices.end(); it++) {
        it->draw(viewMat);
        viewMat = glm::translate(viewMat, glm::vec3(0.0f, 0.0f, -it->getLength()));
        viewMat = glm::rotate(viewMat, glm::radians((float)it->getDirection()), glm::vec3(0.0f, 1.0f, 0.0f));
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
