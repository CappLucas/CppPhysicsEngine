#ifndef QUADTREE_H
#define QUADTREE_H

#pragma once

#include "Types.h"
#include "Object.h"

#include "BoundingBox.h"
#include "Rectangle.h"

#include <cmath>

/*
-----------------------Notes-------------------
A quadtree needs a boundary, a capacity, objects, 

a boundary will be represented as an object from the BoundingBox class.
when we create the first quad tree that is where we use bounding box to dynamically resize the tree
but once you have the first border defined, you don't need the complext bounding class.


methods:


    insert. Inserst an object into the tree unless it exceeds capacity, if it does, subdivide.

    devide. divides the quadtree into 4 more quadtrees.

*/




//each quadtree has 4 other quadtrees by default set to a nullptr and has teh objects, or leaf nodes.
struct Quadtree{
    static int MAX_CAPACITY;
    static int MAX_DEPTH;

    Quadtree(BoundingBox newBox, ObjectVector newObjects, int newLevel) : box(newBox), objects(newObjects), level(newLevel){
        level += 1;
    }
    ~Quadtree(){
        for(Object* &object : objects){
            delete object;
        }
    }
    //holds children
    Quadtree* bottomLeft = nullptr;
    Quadtree* bottomRight = nullptr;
    Quadtree* topLeft = nullptr;
    Quadtree* topRight = nullptr;

    BoundingBox box;
    ObjectVector objects;

    int capacity;
    int level;

    //returns true of quadtree completely contains object.
    bool contains(Object* &object){
        Rectangle objectBorder = object->getBoundingBox().border;

        return (objectBorder.getLeftX() >= box.border.getLeftX() && 
            objectBorder.getRightX() <= box.border.getRightX() &&
            objectBorder.getBottomY() >= box.border.getBottomY() && 
            objectBorder.getTopY() <= box.border.getTopY());
    };

    bool overlaps(Object* &object){
        Rectangle objectBorder = object->getBoundingBox().border;

        return !(objectBorder.getLeftX() >= box.border.getRightX() || 
            objectBorder.getLeftX() <= box.border.getRightX() ||
            objectBorder.getBottomY() >= box.border.getBottomY() || 
            objectBorder.getTopY() <= box.border.getTopY());
              // Check if the object is completely outside the quadtree node's bounds
    return !(objectBorder.getRightX() <= box.border.getLeftX() ||  // Object is to the left of the node
             objectBorder.getLeftX() >= box.border.getRightX() ||  // Object is to the right of the node
             objectBorder.getTopY() <= box.border.getBottomY() ||  // Object is below the node
             objectBorder.getBottomY() >= box.border.getTopY());
    }
    void subdivide(ObjectVector &parentObjects){
        //split the parent objects among the children, and if the object overlaps a side of the tree, 
        //just share the object in the both children.
        //also transfer all perent objects to children tree nodes.
        
    };

    void insert(Object* &object){
        //if the capacity is not exceeded, and the quadtree contains or overlaps with the object, insert the object into the quadtree.
        //after this insert if the objects is overlapping other nodes add it to them.
        //if the capacity is exceeded and the depth isn't, subdivide the quadtree and then
        //call the insert function on those quadtrees.
        if(!contains(object) || !overlaps(object)){
            return;
        }
        
    };
};

//put this in collision detection class
//builds the quadtree using a reference to the game objects.
void buildTree(ObjectVector &allObjects){
    //loop through items to make a bounding box
    //then start making quadtrees from there?

    for(Object* &object : allObjects){
        //insert points
    }
}
#endif