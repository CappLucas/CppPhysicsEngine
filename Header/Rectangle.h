#ifndef RECTANGLE_H
#define RECTANGLE_H

#pragma once

#include "Types.h"

class Rectangle{
public:
    Rectangle(Plane newPlane) : plane(newPlane){};
    ~Rectangle();

    //------------------------- getters ---------------------------
    float getLeftX(){return plane.first.first;}
    float getRightX(){return plane.second.first;}
    float getBottomY(){return plane.first.second;}
    float getTopY(){return plane.second.second;}

    float getLength(){return plane.second.first = plane.first.second;}
    float getHeight(){return plane.second.second = plane.first.second;}

    float getXCenter(){return (plane.first.first + plane.second.first)/2;}
    float getYCenter(){return (plane.first.second + plane.second.second)/2;}

    Cooridinate getCenter(){return {getXCenter(),getYCenter()};}

    //------------------------- setters ----------------------------
    void changeLeftX(float leftX){if(leftX < getRightX()){plane.first.first = leftX;}};
    void changeRightX(float rightX){if(rightX > getLeftX()){plane.second.first = rightX;}};
    void changeBottomY(float bottomY){if(bottomY < getTopY()){plane.first.first = bottomY;}};
    void changeTopY(float topY){if(topY > getBottomY()){plane.first.first = topY;}};
    
    //------------------------- methods ----------------------------
    void moveTo(Cooridinate newPosition){
        //finds how much the rectangle has to move
        Cooridinate displacement = {newPosition.first - plane.first.first,newPosition.second - plane.first.second};

        plane.first = newPosition;
        plane.second = {plane.second.first + displacement.first, plane.second.second + displacement.second};
    };
    void move(Cooridinate displacement){
        plane.first.first += displacement.first;
        plane.second.first += displacement.first;
        plane.first.second += displacement.second;
        plane.second.second += displacement.second;
    };
private:
    // holds the bottom left corner and the top right corner of the rectangle.
    // first cooridinate: ----bottom left corner----- other one: -------top right corner
    Plane plane;
};

#endif