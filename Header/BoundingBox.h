#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#pragma once

#include "Types.h"
#include "Rectangle.h"

#include <cmath>

//box used to represent the bounding boxes of each object 
struct BoundingBox{
    BoundingBox(Rectangle newBorder = Rectangle{{{Infinity,Infinity},{-Infinity, -Infinity}}}) : border(newBorder){};
    //sets the bottom left corner bound to teh farthest opposite point, same with top right corner
    Rectangle border;
    //since default values are infinity, any new box that comes in with shrink the size, 
    //effectively making a bounding box for our quadtree. Also, and new box will resize the bounding box to fit the new stuff
    void mergeBox(BoundingBox mergingBox){
        //expands the box if any value is greater than the current.
        border.setLeftX(std::min(border.getLeftX(), mergingBox.border.getLeftX()));
        border.setBottomY(std::min(border.getBottomY(), mergingBox.border.getBottomY()));
        border.setRightX(std::max(border.getRightX(), mergingBox.border.getRightX()));
        border.setTopY(std::max(border.getTopY(), mergingBox.border.getTopY()));
    }
};

//function that loops through some container and returns a bounding box given an iterator with the right size.
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