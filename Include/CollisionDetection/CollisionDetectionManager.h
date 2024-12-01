#pragma once

#include "Object.h"
#include "Types.h"
#include "Quadtree.h"
#include <vector>

class CollisionDetectionManager{
    public:
        Quadtree *myQuadtree;

        CollisionDetectionManager(ObjectVector &allObjectsReference) : allObjects(allObjectsReference){};
        ~CollisionDetectionManager();
    
        //builds the quadtree using a reference to the game objects.
        void buildTree(ObjectVector &allObjects);

        void findBroadPhaseCollisions();

        void findNarrowPhaseCollisions(CollisionObjectVector &objects);

        void resolveCollisions(CollisionObjectVector &objects);

        void update();

private:
    //reference to all of the objects in the game
    ObjectVector &allObjects;

    CollisionObjectVector broadPhaseCollisions;
    CollisionObjectVector narrowPhaseCollisions;
};