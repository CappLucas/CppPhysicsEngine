#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#pragma once

#include "Types.h"
#include "Rectangle.h"

#include <cmath>

//box used to represent the bounding boxes of each object 
struct BoundingBox{
    BoundingBox(Rectangle newBorder = Rectangle{{{Infinity,Infinity},{-Infinity, -Infinity}}}) : border(newBorder){};
    //holds the bounding boxes border.
    Rectangle border;
    //given a boundingbox, resizes current if it is bigger than one of the sides.
    void mergeBox(BoundingBox mergingBox);
};

//function that loops through some container and returns a bounding box given an iterator with the right size.
template <class Iterator>
BoundingBox findBoundingBox(Iterator begginning, Iterator end);

#endif