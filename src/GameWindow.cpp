#include <GameWindow.hpp>
#include "stdio.h"
#include "stdlib.h"
#include <iostream>

GameWindow::GameWindow()
{
    glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, GLFW_FALSE);
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    this->window = glfwCreateWindow(800, 600, "42run", NULL, NULL);
    if (this->window == NULL)
        exit(printf("Failed to create GLFW window\n"));
    glfwSetWindowUserPointer(this->window, this);
	glfwSetKeyCallback(window, (GLFWkeyfun)GameWindow::key_callback);
    glfwMakeContextCurrent(this->window);
//	glfwSetFramebufferSizeCallback(d->window, framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		exit(printf("Failed to initialize GLAD\n"));
}

GameWindow::~GameWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void GameWindow::swapBuffers() {
    glfwSwapBuffers(window);
}

void GameWindow::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    (void)scancode;
    (void)mods;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
