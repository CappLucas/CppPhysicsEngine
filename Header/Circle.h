#ifndef CIRCLE_H
#define CIRCLE_H

#pragma once

#include "Types.h"

class Circle{
public:
    Circle(Cooridinate newCenter, float newRadius) : radius(newRadius), center(newCenter){}

    //------------ getters --------------
    float getRadius(){return radius;}
    Cooridinate getCenter(){return center;}
    float getDiameter(){return radius*2;}

    Cooridinate getLeft(){return {center.x - radius, center.y};}
    Cooridinate getRight(){return {center.x + radius, center.y};}
    Cooridinate getTop(){return {center.x, center.y - radius};}
    Cooridinate getBottom(){return {center.x, center.y + radius};}

    //------------ setters ---------------
    void setRadius(float newRadius){
        if(newRadius > 0){radius = newRadius;}
    }
    void setCenter(Cooridinate newCenter){center = newCenter;}

    //-----------methods---------------
    void moveTo(Cooridinate newCenter){
        center = newCenter;
    };
    void move(Cooridinate displacement){
        center.x += displacement.x;
        center.y += displacement.y;
    };
private:
    float radius;
    Cooridinate center;
};

#endif