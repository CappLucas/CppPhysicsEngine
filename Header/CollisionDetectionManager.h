#ifndef COLLISIONDETECTIONMANAGER_H
#define COLLISIONDETECTIONMANAGER_H

#pragma once

#include "Object.h"
#include "Types.h"

#include <vector>

class CollisionDetectionManager
{
public:
    CollisionDetectionManager(ObjectVector &allObjectsReference) : allObjects(allObjectsReference){};
    ~CollisionDetectionManager();

    void findCollisions();

    void resolveCollisions();

    void runAll();

private:
    //reference to all of the objects in the game
    ObjectVector &allObjects;

    CollisionObjectVector collisions;
};

#endif