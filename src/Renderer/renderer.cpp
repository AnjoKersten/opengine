#include "renderer.h"

/**
Constructor
Window creation
*/
Renderer::Renderer() {

    //Shader* skyboxShader = new Shader("../src/Shaders/skybox.vs", "../src/Shaders/skybox.fs");
    //Shader* cubemapShader = new Shader("../src/Shaders/cubemap.vs", "../src/Shaders/cubemap.fs");

    //this->skyboxInit(cubemapShader, skyboxShader);
}

Renderer::~Renderer() {

}

void Renderer::skyboxInit(Shader* cubemapShader, Shader* skyboxShader) {
    //Skybox VAO
    glGenVertexArrays(1, &skyboxVAO);
    glGenBuffers(1, &skyboxVBO);
    glBindVertexArray(skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(box.skyboxVertices), &box.skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //Shader config
    cubemapShader->use();
    cubemapShader->setInt("texture1", 0);
    skyboxShader->use();
    skyboxShader->setInt("skybox", 0);
}

void Renderer::drawSkybox(glm::mat4 view, glm::mat4 projection, Shader skyboxShader) {
    //Shader skyboxShader("../Shaders/skyboxVertex.vs", "../Shaders/skyboxFrag.fs");
    unsigned int cubemapTexture = box.loadSkybox(faces); 
    glDepthFunc(GL_LEQUAL);
    skyboxShader.use();
    skyboxShader.setMat4("view", view);
    skyboxShader.setMat4("projection", projection);
    glBindVertexArray(skyboxVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS); // set depth function back to default
}

void Renderer::renderScene(Scene* scene, GLFWwindow* window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_viewMatrix = scene->camera()->GetViewMatrix();

	_projectionMatrix = glm::perspective(45.0f, con.xRes / con.yRes, 0.1f, 10000.0f);

	glm::mat4 modelMatrix = glm::mat4(1.0f);

	this->renderActor(_viewMatrix, _projectionMatrix, modelMatrix, scene, scene->camera());

	//renderSkybox();

	glfwPollEvents();
	glfwSwapBuffers(window);
}

void Renderer::renderActor(glm::mat4 view, glm::mat4 projection, glm::mat4 modelMatrix, Actor* actor, Camera* camera) {
	glm::vec3 pos = glm::vec3(actor->position.x, actor->position.y, actor->position.z);
	glm::vec3 rot = glm::vec3(actor->rotation.x, actor->rotation.y, actor->rotation.z);
	glm::vec3 scale = glm::vec3(actor->scale.x, actor->scale.y, actor->scale.z);

	glm::mat4 transformMatrix = glm::translate(glm::mat4(1.0f), pos);
	glm::mat4 rotationMatrix = glm::eulerAngleYXZ(rot.y, rot.x, rot.z);
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale);

	glm::mat4 mm = transformMatrix * rotationMatrix * scaleMatrix;

	modelMatrix *= mm;

	Model* model = actor->model;
	if (model != NULL) {
		this->renderOBJ(model, view, projection);
	}
	
	vector<Actor*> children = actor->actors;
	vector<Actor*>::iterator child;
	for (child = children.begin(); child != children.end(); child++) {
		this->renderActor(view, projection, modelMatrix, *child, camera);
	}
}

void Renderer::renderText(UIText* text, UICollection* parent, Shader* shader) {
	FontLoader* fLoader;
	fLoader->addFont("assets/fonts/arial.ttf");
	shader->setVec3("textColor", text->color);

	// set texture and VAO
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(text->_VAO);


	std::string::const_iterator c;
	std::string str = text->content;
	float scale = text->scale;

	float x = 0;
	float y = 0;
	if (text->center) {
		// get width and height
		float w = 0;
		float h = 0;
		for (c = str.begin(); c != str.end(); c++) {
			Character ch = fLoader->getFont(text->getFont())[*c];
			w += ch.size.x * scale;
			h = (ch.size.y * scale) > h ? ch.size.y * scale : h;
		}

		x = (text->pos.x + parent->pos.x) - w / 2;
		y = (text->pos.y + parent->pos.y) - h / 2;

		x -= 6; // <-- a small offset
	}else {
		x = (text->pos.x + parent->pos.x);
		y = (text->pos.y + parent->pos.y);
	}

	// Iterate through all characters
	int i = 0;
	for (c = str.begin(); c != str.end(); c++) {
		// if lerp color set new color
		i++;
		if (text->doColorLerp()) {
			shader->setVec3("textColor", text->getColorLerp(i));
		}

		// get charackter
		Character ch = fLoader->getFont(text->getFont())[*c];

		// set pos
		GLfloat xpos = x + ch.bearing.x * scale;
		GLfloat ypos = y - (ch.size.y - ch.bearing.y) * scale;

		// set width and height
		GLfloat w = ch.size.x * scale;
		GLfloat h = ch.size.y * scale;

		// Update VBO for each character
		GLfloat vertices[6][4] = {
			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos,     ypos,       0.0, 1.0 },
			{ xpos + w, ypos,       1.0, 1.0 },

			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos + w, ypos,       1.0, 1.0 },
			{ xpos + w, ypos + h,   1.0, 0.0 }
		};

		// Render glyph texture over quad
		glBindTexture(GL_TEXTURE_2D, ch.textureID);

		// Update content of VBO memory
		glBindBuffer(GL_ARRAY_BUFFER, text->_VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		x += (ch.advance >> 6) * scale;
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Renderer::renderOBJ(Model* mod, glm::mat4 proj, glm::mat4 view) {
	modShader = new Shader("../src/Shaders/model.vs", "../src/Shaders/model.fs");
	modShader->use();
	modShader->setMat4("projection", proj);
	modShader->setMat4("view", view);
	glm::mat4 model;
        model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
	model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
	glUniformMatrix4fv(glGetUniformLocation(modShader->ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
	mod->Draw(modShader);
}

/**
 Input to close the window.
 Input key is the escape button.
 The function expects a window.
 */
void Renderer::processInput(GLFWwindow *window) {
    if (input.getKeyDown(GLFW_KEY_SPACE)) {
        glfwSetWindowShouldClose(window, true);
    }
}

/**
 A function to clean up the window before it's being closed.
 */
void Renderer::cleanUp() {
    glDeleteVertexArrays(1, &skyboxVAO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &skyboxVAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
