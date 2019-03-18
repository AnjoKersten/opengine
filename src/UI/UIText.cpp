#include "UIText.h"

UIText::UIText(const char *fontPath) {
    this->setFont(fontPath);
    
}

void UIText::setFont(const char *fontP) {
    font = fontP;
}