#include "light.h"

Light::Light(lightTypes type, Shader shader) {
    lType = type;
    lShader = shader;
    glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
}

Light::~Light() {

}

void Light::SetDiffuseMap(const char *texPath) {
    Texture diffMap(texPath);
	glActiveTexture(GL_TEXTURE0);
	lShader.setInt("material.diffuse", 0);
}

void Light::SetSpecularMap(const char *texPath) {
    Texture specMap(texPath);
	glActiveTexture(GL_TEXTURE1);
	lShader.setInt("material.specular", 1);
}

void Light::SetDirectionalLight(Camera cam) {
    if (lType == Directional) {
        lShader.use();
		lShader.setVec3("light.direction", -4.0f, -16.0f, -6.0f);
		lShader.setVec3("viewPos", cam.Position);
		lShader.setVec3("light.ambient", 0.25f, 0.25f, 0.25f);
		lShader.setVec3("light.diffuse", 0.8f, 0.8f, 0.8f);
		lShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
		lShader.setFloat("material.shininess", 32.0f);
    }
}

