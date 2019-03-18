#ifndef UICOLLECTION_H
#define UICOLLECTION_H

//include UIText
#include "UIText.h"
//include Vector
#include <vector>

class UICollection {
public:
    UICollection();
    virtual ~UICollection();

    std::vector<UIText*> AllText();
    int TextSize();

    //Properties
    glm::vec3 pos;
    glm::vec3 size;

    //Center line up
    glm::vec3 center();

protected:
    void add(UIText* text);
    void remove(UIText* text);
private:
    std::vector<UIText*> amount;
};

#endif