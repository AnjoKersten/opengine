#ifndef INPUT_H
#define INPUT_H

#include <glfw3.h>

class Input {
public:
    static Input* getInstance();
    Input();
    virtual ~Input();
    static void init(GLFWwindow* window);
    static void update();
    static bool getKey();
    static bool getKeyDown();
private:
    static Input* instance;
};

#endif