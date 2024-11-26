#include "CollisionDetectionManager.h"

CollisionDetectionManager::~CollisionDetectionManager()
{
    delete myQuadtree;
}

void CollisionDetectionManager::buildTree(ObjectVector &allObjects){
    delete myQuadtree;
    BoundingBoxSpace::BoundingBox rootBox = BoundingBoxSpace::findBoundingBox(allObjects);
    myQuadtree = new Quadtree{rootBox, 0};
}

void CollisionDetectionManager::findBroadPhaseCollisions(){
    buildTree(allObjects);
     myQuadtree->insertObjects(allObjects);
     //TODO: query the built quadtree.
}
void CollisionDetectionManager::findNarrowPhaseCollisions(CollisionObjectVector &objects){

}

void CollisionDetectionManager::resolveCollisions(CollisionObjectVector &objects){

}

void CollisionDetectionManager::update(){
    /* builds quadtree, queries the tree for potential collisions, 
    then passes those collisions to the narrow phase, which finds 
    collisions precisely, then passes those for sure collisions 
    to the collision resolver where the objects are seperated 
    and updated based on collision. */

    findBroadPhaseCollisions();
    findNarrowPhaseCollisions(broadPhaseCollisions);
    resolveCollisions(narrowPhaseCollisions);
}

