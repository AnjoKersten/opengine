#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <string>
#include <vector>

#include <glm/gtx/euler_angles.hpp>

#include "../config.h"
#include "../Graphics/skybox.h"
#include "shader.h"
#include "../UI/UIText.h"
#include "../UI/UICollection.h"
#include "../Texture/FontLoader.h"
#include "../Model/model.h"
#include "../Core/input.h"
#include "actor.h"
#include "camera.h"

class Renderer {
public:
    Renderer();
    virtual ~Renderer();
    void processInput(GLFWwindow* window);
    void skyboxInit(Shader* cubemapShader, Shader* skyboxShader);
    void drawSkybox(glm::mat4 view, glm::mat4 projection, Shader skyboxShader);
    void renderActor(glm::mat4 view, glm::mat4 projection, glm::mat4 modelMatrix, Actor* actor, Camera* camera);
    void renderText(UIText* text, UICollection* parent, Shader* shader);
    void renderOBJ(Model* mod, glm::mat4 proj, glm::mat4 view);
    // cleans up the VBO's, VAO's and the EBO's.
    void cleanUp();
    // view and projection matrices.
private:
    Skybox box;
    config con;
    Input input;
    unsigned int VBO, VAO, EBO;
    unsigned int skyboxVAO, skyboxVBO;
    Shader* modShader;
    vector<string> const faces {
        "assets/Sprites/Skybox/right.tga",
	"assets/Sprites/Skybox/left.tga",
	"assets/Sprites/Skybox/top.tga",
	"assets/Sprites/Skybox/bottom.tga",
	"assets/Sprites/Skybox/front.tga",
	"assets/Sprites/Skybox/back.tga"
    };
};

#endif
