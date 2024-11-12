#ifndef RECTANGLE_H
#define RECTANGLE_H

#pragma once

#include "Types.h"

class Rectangle{
public:
    //constructor by two points
    Rectangle(Plane newPlane) : plane(newPlane){};
    //constructor by one point and length and width values.
    Rectangle(Cooridinate newBottomLeftCorner, float length, float height){
        plane.bottomLeft = newBottomLeftCorner;
        plane.topRight = {newBottomLeftCorner.x + length, newBottomLeftCorner.y + height};
    }
    

    //------------------------- getters ---------------------------
    Cooridinate getBottomLeftCorner(){return plane.bottomLeft;}
    Cooridinate getTopRightCorner(){return plane.topRight;}

    float getLeftX(){return plane.bottomLeft.x;}
    float getRightX(){return plane.topRight.x;}
    float getBottomY(){return plane.bottomLeft.y;}
    float getTopY(){return plane.topRight.y;}

    float getLength(){return plane.topRight.x - plane.bottomLeft.x;}
    float getHeight(){return plane.topRight.y - plane.bottomLeft.y;}

    float getXCenter(){return (plane.bottomLeft.x + plane.topRight.x)/2;}
    float getYCenter(){return (plane.bottomLeft.y + plane.topRight.y)/2;}

    Cooridinate getCenter(){return {getXCenter(),getYCenter()};}

    //------------------------- setters ----------------------------
    void setBottomLeft(Cooridinate newCorner){plane.bottomLeft = newCorner;}
    void setTopRight(Cooridinate newCorner){plane.topRight = newCorner;}

    void setLeftX(float leftX){if(leftX < getRightX()){plane.bottomLeft.x = leftX;}};
    void setRightX(float rightX){if(rightX > getLeftX()){plane.topRight.x = rightX;}};
    void setBottomY(float bottomY){if(bottomY < getTopY()){plane.bottomLeft.x = bottomY;}};
    void setTopY(float topY){if(topY > getBottomY()){plane.topRight.x = topY;}};
    
    //------------------------- methods ----------------------------
    void moveTo(Cooridinate newPosition){
        //finds how much the rectangle has to move
        Cooridinate displacement = newPosition - plane.bottomLeft;

        plane.bottomLeft = newPosition;
        plane.topRight = plane.topRight + displacement;
    };
    void move(Cooridinate displacement){

        //using the overloaded plus operator
        plane.bottomLeft = plane.bottomLeft + displacement;
        plane.topRight = plane.topRight + displacement;
    };
private:
    // holds the bottom left corner and the top right corner of the rectangle.
    // first cooridinate: ----bottom left corner----- other one: -------top right corner
    Plane plane;
};

#endif