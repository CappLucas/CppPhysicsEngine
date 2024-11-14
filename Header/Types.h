#ifndef TYPES_H
#define TYPES_H

#pragma once

#include <utility>
#include <vector>
#include <limits>
#include <memory>


struct CoordStruct{
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
    CoordStruct bottomLeft;
    CoordStruct topRight;
};

//a static float with value infinity
extern float Infinity; 


using Cooridinate = CoordStruct;

using Velocity = CoordStruct;

using Acceleration = CoordStruct;

using Plane = CornerStruct;

#endif