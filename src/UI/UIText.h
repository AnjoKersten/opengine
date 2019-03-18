#ifndef UITEXT_H
#define UITEXT_H

// include freetype
#include <ft2build.h>
#include FT_FREETYPE_H

class UIText {
public:
    UIText(const char *fontPath);
    virtual ~UIText();
    void setFont(const char *fontP);
private:
    const char* font;
};

#endif