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
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

        GLFWwindow	*window;
    private:

};

#endif // WINDOW_H
