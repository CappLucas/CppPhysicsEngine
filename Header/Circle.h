#ifndef CIRCLE_H
#define CIRCLE_H

#pragma once

#include "Types.h"

class Circle{
public:
    Circle(Cooridinate newCenter, float newRadius) : radius(newRadius), center(newCenter){}
    ~Circle();

    //------------ getters --------------
    float getRadius(){return radius;}
    Cooridinate getCenter(){return center;}
    float getDiameter(){return radius*2;}

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
        center.first += displacement.first;
        center.second += displacement.second;
    };
private:
    float radius;
    Cooridinate center;
};

#endif