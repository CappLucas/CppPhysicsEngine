#ifndef RECTANGLE_H
#define RECTANGLE_H

#pragma once

#include "Types.h"

class Rectangle{
public:
    Rectangle(Plane newPlane) : plane(newPlane){};
    ~Rectangle();

    //------------------------- getters ---------------------------
    float getLeftX(){return plane.bottomLeft.x;}
    float getRightX(){return plane.topRight.x;}
    float getBottomY(){return plane.bottomLeft.y;}
    float getTopY(){return plane.topRight.y;}

    float getLength(){return plane.bottomLeft.x - plane.topRight.x;}
    float getHeight(){return plane.bottomLeft.y - plane.topRight.y;}

    float getXCenter(){return (plane.bottomLeft.x + plane.topRight.x)/2;}
    float getYCenter(){return (plane.bottomLeft.y + plane.topRight.y)/2;}

    Cooridinate getCenter(){return {getXCenter(),getYCenter()};}

    //------------------------- setters ----------------------------
    void changeLeftX(float leftX){if(leftX < getRightX()){plane.bottomLeft.x = leftX;}};
    void changeRightX(float rightX){if(rightX > getLeftX()){plane.topRight.x = rightX;}};
    void changeBottomY(float bottomY){if(bottomY < getTopY()){plane.bottomLeft.x = bottomY;}};
    void changeTopY(float topY){if(topY > getBottomY()){plane.topRight.x = topY;}};
    
    //------------------------- methods ----------------------------
    void moveTo(Cooridinate newPosition){
        //finds how much the rectangle has to move
        Cooridinate displacement = {newPosition.x - plane.bottomLeft.x,newPosition.y - plane.bottomLeft.y};

        plane.bottomLeft = newPosition;
        plane.topRight = {plane.topRight.x + displacement.x, plane.topRight.y + displacement.y};
    };
    void move(Cooridinate displacement){
        plane.bottomLeft.x += displacement.x;
        plane.topRight.x += displacement.x;
        plane.bottomLeft.y += displacement.y;
        plane.topRight.y += displacement.y;
    };
private:
    // holds the bottom left corner and the top right corner of the rectangle.
    // first cooridinate: ----bottom left corner----- other one: -------top right corner
    Plane plane;
};

#endif