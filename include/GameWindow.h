#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

class GameWindow
{
    public:
        GameWindow();
        virtual ~GameWindow();

    private:
        GLFWwindow	*window;

};

#endif // WINDOW_H
