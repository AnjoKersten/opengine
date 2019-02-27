//
// Created by Mathijs Hoving on 2018-12-16.
//

#ifndef OPENGINE_COLOR_H
#define OPENGINE_COLOR_H

/**
 An enum with 9 different color types (RED, GREEN, BLUE, YELLOW, CYAN, PURPLE, WHITE, GREY, BLACK).
 */
enum ColorTypes {
    RED, GREEN, BLUE, YELLOW, CYAN, PURPLE, WHITE, GREY, BLACK
};

class Color {
public:

    /**
     Constructor.
     Set the color.
     Expects a red type color, a green type color, a blue type color.
     */
    Color(float red, float green, float blue) {
        setColor(red, green, blue);
    }

    /**
     Constructor.
     Set a color type.
     Expects a color type (RED, GREEN, BLUE, YELLOW, CYAN, PURPLE, WHITE, GREY, BLACK).
     */
    Color(ColorTypes type) {
        setColorType(type);
    }

    /**
     A getter for te color red.
     */
    float getRed() {
        return Red;
    }

    /**
     A getter for te color green.
     */
    float getGreen() {
        return Green;
    }

    /**
     A getter for te color blue.
     */
    float getBlue() {
        return Blue;
    }

private:

    /**
     Sets the color type.
     */
    void setColorType(ColorTypes type);

    /**
     Sets the color.
     */
    void setColor(float red, float green, float blue) {
        Red = red;
        Green = green;
        Blue = blue;
    }

    /**
     variables for the color.
     */
    float Red, Green, Blue;
};

#endif //OPENGINE_COLOR_H
