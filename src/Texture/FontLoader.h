#ifndef FONTLOADER_H
#define FONTLOADER_H

// include glad & glfw
#include <glad.h>
#include <glfw3.h>
// include freetype
#include <ft2build.h>
#include FT_FREETYPE_H 
// include glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// include streams and c++ libs here
#include <iostream>
#include <map>
#include <vector>

struct Character {
    //Glyph
    unsigned int textureID; 
	glm::ivec2 size; 
	glm::ivec2 bearing; 
	unsigned int advance; 
};

class FontLoader {
public:
    FontLoader();
    virtual ~FontLoader();
    void addFont(const char *path);
    std::map<GLchar, Character> getFont(const char* path);
private:
    std::map<std::string, std::map<GLchar, Character>> fonts;
    std::vector<const char*> error;
};

#endif