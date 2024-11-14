#ifndef QUADTREE_H
#define QUADTREE_H

#pragma once

#include "Types.h"
#include "Object.h"

#include "BoundingBox.h"
#include "Rectangle.h"

#include <cmath>

//each quadtree has 4 other quadtrees by default set to a nullptr and has the objects, or leaf nodes.
struct Quadtree{
    static int MAX_CAPACITY;
    static int MAX_DEPTH;

    Quadtree(BoundingBox newBox,  int parentLevel) : box(newBox),  level(parentLevel){level += 1;}
    ~Quadtree();
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
    bool contains(Object* &object);
    bool overlaps(Object* &object);

    void subdivide(ObjectVector &parentObjects);
    void insert(Object* &object);

    //loops through objects to insert them.
    void insertObjects(ObjectVector &allObjects);
};

#endif