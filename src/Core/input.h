#ifndef INPUT_H
#define INPUT_H

#include <glfw3.h>
#include <glad.h>
#include <vector>
#include <string>
#include <iostream>

class Input {
public:
    static Input* getInstance();
    Input();
    virtual ~Input();
    static void init(GLFWwindow* window);
    static void update();
    static bool getKey(int kCode);
    static bool getKeyDown(int kCode);
    static void keyHandler(GLFWwindow* window, int key, int scanCode, int action, int mode);
private:
    static Input* instance;
    GLFWwindow* window;
    bool _keys[GLFW_KEY_LAST];
    bool _keysDown[GLFW_KEY_LAST];
};

#endif
