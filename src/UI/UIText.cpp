#include "UIText.h"

UIText::UIText(const char *fontPath, float _scale) {
    this->setFont(fontPath);
    this->scale = _scale;
    
    this->content = "No content";

    this->init();
}

void UIText::setFont(const char *fontP) {
    font = fontP;
}

void UIText::init() {
    // create text quad
	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);
	glBindVertexArray(_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}