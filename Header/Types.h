#ifndef TYPES_H
#define TYPES_H

#include "Object.h"

#include <utility>
#include <vector>

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

using ObjectVector = std::vector<Object*>;

using CollisionObjectVector = std::vector<ObjectVector>;

#endif