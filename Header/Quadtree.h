#ifndef QUADTREE_H
#define QUADTREE_H

#pragma once

#include "Types.h"

#include <cmath>

//box used to represent the bounding boxes of each object 
struct BoundingBox{
    //sets the bottom left corner bound to teh farthest opposite point, same with top right corner
    CornerStruct bounds{{Infinity,Infinity},{-Infinity, -Infinity}};

    //make a function to set the boundary of the bounding box

    //since default values are infinity, any new box that comes in with shrink the size, 
    //effectively making a bounding box for our quadtree. Also, and new box will resize the bounding box to fit the new stuff
    void mergeBox(BoundingBox mergingBox){
        //expands the box if any value is greater than the current.
        bounds.bottomLeft.x = std::min(bounds.bottomLeft.x, mergingBox.bounds.bottomLeft.x);
        bounds.bottomLeft.y = std::min(bounds.bottomLeft.y, mergingBox.bounds.bottomLeft.y);
        bounds.topRight.x = std::max(bounds.bottomLeft.x, mergingBox.bounds.bottomLeft.x);
        bounds.topRight.x = std::max(bounds.bottomLeft.x, mergingBox.bounds.bottomLeft.x);
    }
};

//function that loops through some container and returns a bounding box with the right size.
template <class Iterator>
BoundingBox findBoundingBox(Iterator begginning, Iterator end){
    BoundingBox returnBox;
    while(begginning != end){
        returnBox.mergeBox(*Iterator);
        begginning += 1;
    }
    return returnBox;
}

struct Quadtree
{
public:
    Quadtree();
    ~Quadtree();

private:

};

#endif