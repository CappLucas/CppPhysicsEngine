#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#pragma once

#include "Types.h"

#include <cmath>
#include <memory>
//box used to represent the bounding boxes of each object 
struct BoundingBox{
    //sets the bottom left corner bound to teh farthest opposite point, same with top right corner
    Plane border{{Infinity,Infinity},{-Infinity, -Infinity}};

    //make a function to set the boundary of the bounding box

    //since default values are infinity, any new box that comes in with shrink the size, 
    //effectively making a bounding box for our quadtree. Also, and new box will resize the bounding box to fit the new stuff
    void mergeBox(BoundingBox mergingBox){
        //expands the box if any value is greater than the current.
        border.bottomLeft.x = std::min(border.bottomLeft.x, mergingBox.border.bottomLeft.x);
        border.bottomLeft.y = std::min(border.bottomLeft.y, mergingBox.border.bottomLeft.y);
        border.topRight.x = std::max(border.bottomLeft.x, mergingBox.border.bottomLeft.x);
        border.topRight.x = std::max(border.bottomLeft.x, mergingBox.border.bottomLeft.x);
    }
};

//function that loops through some container and returns a bounding box with the right size.
template <class Iterator>
BoundingBox findBoundingBox(Iterator begginning, Iterator end){
    BoundingBox returnBox;

    while(begginning != end){
        returnBox.mergeBox(*begginning);

        begginning += 1;
    }
    return returnBox;
}

#endif