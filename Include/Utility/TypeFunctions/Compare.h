#pragma once

#include "Point.h"
#include "Vector.h"
#include "LineSegment.h"
#include "Ray.h"
#include "Region.h"
#include "CenterRegion.h"
#include "Circle.h"

namespace Geometry_Space{
    bool isEqual(float val1, float val2);

    bool contains(Region container, Region check);
    bool contains(Region container, CenterRegion check);
    bool contains(Region container, Point check);
    bool contains(Region container, LineSegment check);
    bool contains(Region container, Circle check);

    bool contains(CenterRegion container, Region check);
    bool contains(CenterRegion container, CenterRegion check);
    bool contains(CenterRegion container, Point check);
    bool contains(CenterRegion container, LineSegment check);
    bool contains(CenterRegion container, Circle check);

    bool contains(Circle container, Region check);
    bool contains(Circle container, CenterRegion check);
    bool contains(Circle container, Circle check);
    bool contains(Circle container, Point check);
    bool contains(Circle container, LineSegment check);

    bool contains(Ray container, Point check);
    bool contains(LineSegment container, Point check);

    //TODO: make a doesnotcontain function

    bool overlaps(Region check1, Region check2);
    bool overlaps(Region check1, CenterRegion check2);
    bool overlaps(Region check1, Circle check2);
    bool overlaps(Region check1, Ray check2);
    bool overlaps(Region check1, LineSegment check2);
    
    bool overlaps(CenterRegion check1, CenterRegion check2);
    bool overlaps(CenterRegion check1, Circle check2);
    bool overlaps(CenterRegion check1, Ray check2);
    bool overlaps(CenterRegion check1, LineSegment check2);

    bool overlaps(Circle check1, Circle check2);
    bool overlaps(Circle check1, Ray check2);
    bool overlaps(Circle check1, LineSegment check2);   

    bool overlaps(Ray check1, Ray check2);
    bool overlaps(Ray check1, LineSegment check2);

    bool overlaps(LineSegment check1, LineSegment check2);

}