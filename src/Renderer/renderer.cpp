#include "renderer.h"

/**
Constructor
Window creation
*/
Renderer::Renderer() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    window = glfwCreateWindow(con.xRes, con.yRes, "OPENGINE", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

Renderer::~Renderer() {

}

void Renderer::setupSkybox(Shader cubemapShader, Shader skyboxShader) {
    //Skybox VAO
    glGenVertexArrays(1, &skyboxVAO);
    glGenBuffers(1, &skyboxVBO);
    glBindVertexArray(skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(box.skyboxVertices), &box.skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //Shader config
    cubemapShader.use();
    cubemapShader.setInt("texture1", 0);
    skyboxShader.use();
    skyboxShader.setInt("skybox", 0);
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

void Renderer::renderText(UIText* text, UICollection* parent, Shader* shader){
	shader->setVec3("textColor", text->color);

	// set texture and VAO
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(text->_VAO);


	std::string::const_iterator c;
	std::string str = text->content;
	float scale = text->scale;

	// get width and height
	float w = 0;
	float h = 0;
	for (c = str.begin(); c != str.end(); c++) {
		Character ch = fLoader->getFont(text->getFont())[*c];
		w += ch.size.x * scale;
		h = (ch.size.y * scale) > h ? ch.size.y * scale : h;
	}

	// get message scale and position
	float x = (text->pos.x + parent->pos.x) - w/2;
	float y = (text->pos.y + parent->pos.y) - h/2; //(text->position.y - SHEIGHT) * -1 + parent->position.x;
	
	std::cout << "x:" << x << " y: " << y << std::endl;

	// Iterate through all characters
	int i = 0;
	for (c = str.begin(); c != str.end(); c++){
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
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // Be sure to use glBufferSubData and not glBufferData

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// Render quad
		glDrawArrays(GL_TRIANGLES, 0, 6);
		// Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
		x += (ch.advance >> 6) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

/**
 Input to close the window.
 Input key is the escape button.
 The function expects a window.
 */
void Renderer::processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
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
