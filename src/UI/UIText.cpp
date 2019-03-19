#include "UIText.h"

UIText::UIText(const char *fontPath, float _scale, glm::vec3 _color) {
    this->setFont(fontPath);
    this->scale = _scale;
	this->color = _color;
    
    this->content = "NULL";

	this->center = true;

	this->lColors = std::vector<glm::vec3>();

    this->init();
}

UIText::~UIText() {

}

void UIText::setFont(const char *fontP) {
    font = fontP;
}

void UIText::setColorLerp(glm::vec3 s, glm::vec3 e) {
	lColors.clear();
	int lerp = content.length();
	float r = (s.x - e.x) / lerp;
	float g = (s.y - e.y) / lerp;
	float b = (s.z - e.z) / lerp;
	for (int i = 1; i <= lerp; i++) {
		glm::vec3 c = glm::vec3(s.x - r * i, s.y - g * i, s.z - b * i);
		lColors.push_back(c);
	}
	lColors.push_back(e);
}

void UIText::removeColorLerp() {
	lColors.clear();
}

bool UIText::doColorLerp() {
	if (lColors.size() > 0) {
		return true;
	}
	return false;
}

glm::vec3 UIText::getColorLerp(int i) {
	if (i < 0 || i >= lColors.size()) {
		return glm::vec3(0, 1, 0);
	}
	return lColors[i];
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