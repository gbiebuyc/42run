#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GameWindow
{
    public:
        GameWindow();
        virtual ~GameWindow();
        void swapBuffers();

    private:
        GLFWwindow	*window;

};

#endif // WINDOW_H
