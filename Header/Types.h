#ifndef TYPES_H
#define TYPES_H

#include <utility>

struct coordStruct{
    float x;
    float y;
};

struct cornerStruct{
    coordStruct bottomLeft;
    coordStruct topRight;
};

using Cooridinate = coordStruct;

using Velocity = coordStruct;

using Acceleration = coordStruct;

using Plane = cornerStruct;

#endif