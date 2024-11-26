#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#pragma once

#include "Types.h"
#include "Rectangle.h"

using namespace TypeSpace;

#include <cmath>
//box used to represent the bounding boxes of each object 
//in a namespace to help avoid ambiguity
namespace BoundingBoxSpace{
    struct BoundingBox{
        BoundingBox(){border = Rectangle{{{ConstantSpace::INFINITY_FLOAT,ConstantSpace::INFINITY_FLOAT},{-ConstantSpace::INFINITY_FLOAT, -ConstantSpace::INFINITY_FLOAT}}};}
        BoundingBox(Rectangle newBorder) : border(newBorder){};
        Rectangle border;

        void mergeBox(BoundingBox mergingBox);
    };

    BoundingBox findBoundingBox(ObjectSpace::ObjectVector &object);
}




#endif