//
// Created by Mathijs Hoving on 2018-12-16.
//

#include "Color.h"

/**
 A function that sets color type (RED, GREEN, BLUE, YELLOW, CYAN, PURPLE, WHITE, GREY, BLACK).
 Expects a color type
 */
void Color::setColorType(ColorTypes type) {
    switch (type) {
        case RED:
            setColor(1.0f, 0.0f, 0.0f);
            break;
        case GREEN:
            setColor(0.0f, 1.0f, 0.0f);
            break;
        case BLUE:
            setColor(0.0f, 0.0f, 1.0f);
            break;
        case YELLOW:
            setColor(1.0f, 1.0f, 0.0f);
            break;
        case CYAN:
            setColor(0.0f, 1.0f, 1.0f);
            break;
        case PURPLE:
            setColor(1.0f, 0.0f, 1.0f);
            break;
        case WHITE:
            setColor(1.0f, 1.0f, 1.0f);
            break;
        case GREY:
            setColor(0.5f, 0.5f, 0.5f);
            break;
        case BLACK:
            setColor(0.0f, 0.0f, 0.0f);
            break;
    }
}

