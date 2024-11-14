#include "Quadtree.h"

int Quadtree::MAX_CAPACITY = 2;
int Quadtree::MAX_DEPTH = 10;

Quadtree::~Quadtree(){
    //deletes children
    delete bottomLeft;
    delete bottomRight;
    delete topLeft;
    delete topRight;
}

bool Quadtree::contains(Object* &object){
    Rectangle objectBorder = object->getBoundingBox().border;

    return (objectBorder.getLeftX() >= box.border.getLeftX() && 
        objectBorder.getRightX() <= box.border.getRightX() &&
        objectBorder.getBottomY() >= box.border.getBottomY() && 
        objectBorder.getTopY() <= box.border.getTopY());
};

bool Quadtree::overlaps(Object* &object){
    Rectangle objectBorder = object->getBoundingBox().border;

    // Check if the object is completely outside the quadtree node's bounds
    return !(objectBorder.getRightX() <= box.border.getLeftX() ||  // Object is to the left of the node
             objectBorder.getLeftX() >= box.border.getRightX() ||  // Object is to the right of the node
             objectBorder.getTopY() <= box.border.getBottomY() ||  // Object is below the node
             objectBorder.getBottomY() >= box.border.getTopY());
}

void Quadtree::subdivide(ObjectVector &parentObjects){
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

    //transfers the objects to the children and clears vector, not that calling insert for each of these objects starts the cycle again.
    bottomLeft->insertObjects(objects);
    bottomRight->insertObjects(objects);
    topLeft->insertObjects(objects);
    topRight->insertObjects(objects);

    objects.clear();
};

void Quadtree::insert(Object* &object){
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

void Quadtree::insertObjects(ObjectVector &allObjects){
    for(Object* &object : allObjects){
        insert(object);
    }
}