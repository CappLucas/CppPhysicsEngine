#ifndef QUADTREE_H
#define QUADTREE_H

#pragma once

#include "Types.h"
#include "Object.h"
#include "BoundingBox.h"
#include <cmath>



//each quadtree has 4 other quadtrees by default set to a nullptr and has teh objects, or leaf nodes.
struct Quadtree{
    Quadtree(BoundingBox newBorder){
        border = newBorder;
    }
    ~Quadtree(){
        //deletes all elements in tree and sets their values to nullptr
        for(int i = 0; i < 4; i++){
            delete children[i];
            children[i] = nullptr;
        } 
    }

    //holds children
    Quadtree* children[4] = {nullptr,nullptr,nullptr,nullptr};
    
    BoundingBox border;
};

//builds the quadtree using a reference to the game objects.
void buildTree(ObjectVector &allObjects){
    //loop through items to make a bounding box
    //then start making quadtrees from there?

    for(Object* &object : allObjects){
    }
}
#endif