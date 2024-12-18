#pragma once

#include "Object.h"
#include "Types.h"


#include "BoundingBox.h"
#include "Rectangle.h"

#include <cmath>

// each quadtree has 4 other quadtrees by default set to a nullptr and has the
// objects, or leaf nodes.
struct Quadtree {
  static int MAX_CAPACITY;
  static int MAX_DEPTH;

  Quadtree(BoundingBoxSpace::BoundingBox newBox, int parentLevel)
      : box(newBox), level(parentLevel) {
    level += 1;
  }
  ~Quadtree();
  // holds children
  Quadtree *bottomLeft = nullptr;
  Quadtree *bottomRight = nullptr;
  Quadtree *topLeft = nullptr;
  Quadtree *topRight = nullptr;

  // border, objects, and more.
  BoundingBoxSpace::BoundingBox box;

  ObjectSpace::ObjectVector objects;

  int capacity;
  int level;

  bool divided = false;

  // returns true of quadtree completely contains object.
  bool contains(ObjectSpace::Object *&object);
  bool overlaps(ObjectSpace::Object *&object);

  void subdivide(ObjectSpace::ObjectVector &parentObjects);
  void insert(ObjectSpace::Object *&object);

  // loops through objects to insert them.
  void insertObjects(ObjectSpace::ObjectVector &allObjects);
};