#include <glad.h>
#include <glfw3.h>

#include "../Renderer/shader.h"
#include "../Renderer/camera.h"
#include "../Texture/Texture.h"

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
    void SetDiffuseMap(const char *texPath);
    void SetSpecularMap(const char *texPath);
    void SetDirectionalLight(Camera cam);
    Shader lShader;
};
