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

    Quadtree(BoundingBox newBox,  int parentLevel) : box(newBox),  level(parentLevel){
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

    //border, objects, and more.
    BoundingBox box;
    ObjectVector objects;

    int capacity;
    int level;

    bool divided = false;

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

        //settin the new widths and lengths of the new quadtrees.
        Rectangle bottomLeftBox({box.border.getBottomLeftCorner(),{box.border.getCenter()}});
        // makes the bottom right box my making a copy of the bottomLeft and moving over by the width of the bottomLeftCorner
        Rectangle bottomRightBox = bottomLeftBox.showMove({bottomLeftBox.getLength(), 0});
        Rectangle topRightBox({{box.border.getCenter()},box.border.getTopRightCorner()});
        // makes the bottom right box my making a copy of the bottomLeft and moving left by the width of the topRightCorner
        Rectangle topLeftBox = bottomLeftBox.showMove({-topRightBox.getLength(),0});
        

        bottomLeft = new Quadtree(BoundingBox{bottomLeftBox}, level);
        bottomRight = new Quadtree(BoundingBox{bottomRightBox}, level);
        topLeft = new Quadtree(BoundingBox{topLeftBox}, level);
        topRight = new Quadtree(BoundingBox{topRightBox}, level);

        //TODO: loop through the trees, and insert -------------------------------------------------------- start here!!!!!!!!!!!!!!!!!!!!
    };

    void insert(Object* &object){
        //if the capacity is not exceeded, and the quadtree contains or overlaps with the object, insert the object into the quadtree.
        //after this insert if the objects is overlapping other nodes add it to them.
        //if the capacity is exceeded and the depth isn't, subdivide the quadtree and then
        //call the insert function on those quadtrees.

        //if doesn't contain, just end function, you can't insert.
        if(!contains(object) || !overlaps(object)){
            return;
        }
        //if this is already divided, try inserting the object into the devided regions.
        if(divided){
            bottomLeft->insert(object);
            bottomRight->insert(object);
            topLeft->insert(object);
            topRight->insert(object);
            return;
        }
        //if object is contained by or overlaps the tree and the capicty is less than the max, just insert into tree.
        if(capacity < MAX_CAPACITY){
            objects.push_back(object);
            return;
        }
        //if object is contained by or overlaps the tree and the capicty is GREATER than the max, push the object 
        //into the tree and then call the subdivide function, that will insert the new objects into the tree.
        else{
            //if the quadtree needs divided, add the object and then the subdivide 
            //function will automatically distribute the objects amoung the children
            objects.push_back(object);
            subdivide(objects);
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