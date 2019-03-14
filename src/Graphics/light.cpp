#include "light.h"

Light::Light(lightTypes type, Shader shader) {
    lType = type;
    lShader = shader;
    glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
}

Light::~Light() {

}

void Light::SetDirectionalLight(Camera cam) {

}

