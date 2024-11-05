#ifndef RECTANGLE_H
#define RECTANGLE_H

#pragma once

#include "Types.h"

class Rectangle{
public:
    Rectangle(Plane newPlane) : plane(newPlane){};
    ~Rectangle();

    //------------------------- getters ---------------------------
    float getLength(){return plane.first.first - plane.second.first;}
    float getHeight(){return plane.first.second - plane.second.first;}

    float getXCenter(){return (plane.first.first + plane.second.first)/2;}
    float getYCenter(){return (plane.first.second + plane.second.second)/2;}

    Cooridinate getCenter(){return {getXCenter(),getYCenter()};}

    //------------------------- setters ----------------------------
    void changeLeftX(float leftX);
    void changeRightX(float rightX);
    void changeTopY(float topY);
    void changeBottomY(float bottomY);

    //------------------------- methods ----------------------------
    void moveTo(Cooridinate newPosition);
    void move(Cooridinate displacement);

private:
    // holds the bottom left corner and the top right corner of the rectangle.
    Plane plane;
};

#endif