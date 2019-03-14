#include "light.h"

Light::Light(lightTypes type, Shader shader) {
    lType = type;
    glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
}

Light::~Light() {

}

void Light::SetDirectionalLight(Camera cam) {

}

