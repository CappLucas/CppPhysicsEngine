#ifndef TYPES_H
#define TYPES_H

#pragma once

#include <utility>
#include <vector>
#include <limits>


struct CoordStruct{
    CoordStruct(){}
    CoordStruct(float newX, float newY) : x(newX), y(newY){}

    float x;
    float y;

    //allows for adding and subtracting cooridinates
    CoordStruct operator + (CoordStruct &c){
        return {x + c.x, y + c.y};
    }
    CoordStruct operator - (CoordStruct &c){
        return {x + c.x, y + c.y};
    }
};

struct CornerStruct{
    CornerStruct(){}
    CornerStruct(CoordStruct newBottomLeft, CoordStruct newTopRight) : bottomLeft(newBottomLeft), topRight(newTopRight){}

    CoordStruct bottomLeft;
    CoordStruct topRight;
};

//a static float with value infinity
extern float Infinity; 


using Cooridinate = CoordStruct;

using Velocity = CoordStruct;

using Acceleration = CoordStruct;

using Plane = CornerStruct;


class Object;

using ObjectVector = std::vector<Object*>;

using CollisionObjectVector = std::vector<ObjectVector>;

#endif