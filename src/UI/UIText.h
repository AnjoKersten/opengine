#ifndef UITEXT_H
#define UITEXT_H

//include glad
#include <glad.h>
#include <glfw3.h>
//include streams & c++ libs here
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
// include freetype
#include <ft2build.h>
#include FT_FREETYPE_H
//include glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class UIText {
public:
    UIText(const char *fontPath, float _scale);
    virtual ~UIText();
    void setFont(const char *fontP);
    const char* getFont() { return font; };
    void setColorLerp(glm::vec3 s, glm::vec3 e);
    void removeColorLerp();
    bool doColorLerp();
    glm::vec3 getColorLerp(int i);
    void init();
    //Properties
    float scale;
    glm::vec3 color;
    std::string content;
    glm::vec3 pos;
    //VAO, VBO
    unsigned int _VAO;
	unsigned int _VBO; 
private:
    std::vector<glm::vec3> lColors;
    const char* font;
};

#endif