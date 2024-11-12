#ifndef TYPES_H
#define TYPES_H

#include "Object.h"

#include <utility>
#include <vector>
#include <limits>

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

//is a const compiled at runtime with value infinity
constexpr float Infinity = std::numeric_limits<float>::infinity();

using Cooridinate = CoordStruct;

using Velocity = CoordStruct;

using Acceleration = CoordStruct;

using Plane = CornerStruct;

using ObjectVector = std::vector<Object*>;

using CollisionObjectVector = std::vector<ObjectVector>;

#endif