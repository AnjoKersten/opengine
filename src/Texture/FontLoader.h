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
#include <maps>

class FontLoader {
public:
    FontLoader();
    virtual ~FontLoader();
    void addFont(const char *path);
private:

};

#endif