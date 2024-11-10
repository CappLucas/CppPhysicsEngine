#ifndef COLLISIONDECTECTIONMANAGER_H
#define COLLISIONDECTECTIONMANAGER_H

#pragma once

#include "Object.h"
#include "Types.h"

#include <vector>

class CollisionDectectionManager
{
public:
    CollisionDectectionManager(ObjectVector &allObjectsReference) : allObjects(allObjectsReference){};
    ~CollisionDectectionManager();

    void findCollisions();

    void resolveCollisions();

    void runAll();

private:
    //reference to all of the objects in the game
    ObjectVector &allObjects;

    CollisionObjectVector collisions;
};

#endif