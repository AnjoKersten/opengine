#ifndef UITEXT_H
#define UITEXT_H

//include glad
#include <glad.h>
//include streams
#include <iostream>
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
    void init();
    //Properties
    float scale;
    glm::vec3 color;
    std::string content;
    glm::vec3 pos;

    unsigned int _VAO;
	unsigned int _VBO; 
private:
    const char* font;
};

#endif