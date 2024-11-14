#ifndef QUADTREE_H
#define QUADTREE_H

#pragma once

#include "Types.h"
#include "Object.h"

#include "BoundingBox.h"
#include <cmath>
#include <memory>

//each quadtree has 4 other quadtrees by default set to a nullptr and has teh objects, or leaf nodes.
struct Quadtree{
    Quadtree(BoundingBox newBorder, ObjectVector newObjects, int newLevel) : border(newBorder), objects(std::move(newObjects)), level(newLevel){}

    //holds children
    std::unique_ptr<Quadtree> children[4];
    
    BoundingBox border;
    ObjectVector objects;
    int level;
};

//builds the quadtree using a reference to the game objects.
void buildTree(ObjectVector &allObjects){
    //loop through items to make a bounding box
    //then start making quadtrees from there?

    for(ObjectSmartPointer &object : allObjects){
    
    }
}
#endif