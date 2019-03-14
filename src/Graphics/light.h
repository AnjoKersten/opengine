#include <glad.h>
#include <glfw3.h>

#include "../Renderer/shader.h"
#include "../Renderer/camera.h"

enum lightTypes {
    Directional
};

class Light {
private:
    unsigned int lightVAO;
    lightTypes lType;
public:
    Light(lightTypes type, Shader shader);
    virtual ~Light();
    void SetDirectionalLight(Camera cam);
};
