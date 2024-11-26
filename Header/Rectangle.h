#ifndef RECTANGLE_H
#define RECTANGLE_H

#pragma once

#include "Types.h"

using namespace TypeSpace;

class Rectangle{
public:
    //default constructor
    Rectangle();
    //constructor by two points
    Rectangle(Plane newPlane);
    //constructor by one point and length and width values.
    Rectangle(Cooridinate newBottomLeftCorner, float length, float height);

    //------------------------- getters ---------------------------
    Plane getPlane(){return plane;}

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

    std::vector<float> getCooridinates(){return {getLeftX(),getBottomY(), getRightX(), getTopY()};};
    std::vector<float> getCLH(){return {getLeftX(),getBottomY(), getLength(), getHeight()};}
    
    //------------------------- setters ----------------------------
    void setBottomLeft(Cooridinate newCorner){plane.bottomLeft = newCorner;}
    void setTopRight(Cooridinate newCorner){plane.topRight = newCorner;}

    void setLeftX(float leftX){if(leftX < getRightX()){plane.bottomLeft.x = leftX;}};
    void setRightX(float rightX){if(rightX > getLeftX()){plane.topRight.x = rightX;}};
    void setBottomY(float bottomY){if(bottomY < getTopY()){plane.bottomLeft.x = bottomY;}};
    void setTopY(float topY){if(topY > getBottomY()){plane.topRight.x = topY;}};
    
    //------------------------- methods ----------------------------
    void moveTo(Cooridinate newPosition);
    void move(Cooridinate displacement);
    Plane showMove(Cooridinate displacement);
    
private:
    //holds bottom left and top right corner of the rectangle
    Plane plane;
};

#endif