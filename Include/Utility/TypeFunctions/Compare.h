#pragma once

#include "Point.h"
#include "Vector.h"
#include "LineSegment.h"
#include "Ray.h"
#include "Region.h"
#include "CenterRegion.h"
#include "Circle.h"

namespace Geometry_Space{
    bool isEqual(const float val1, const float val2);

    //the reason why this is special is that the end can be less than the start and the 
    //function with detect that the check is within the line.
    bool contains(const float rangeStart, const float rangeEnd, const float check);

    bool contains(const Region container, const Region check);
    bool contains(const Region container, const CenterRegion check);
    bool contains(const Region container, const Point check);
    bool contains(const Region container, const LineSegment check);
    bool contains(const Region container, const Circle check);

    bool contains(const CenterRegion container, const Region check);
    bool contains(const CenterRegion container, const CenterRegion check);
    bool contains(const CenterRegion container, const Point check);
    bool contains(const CenterRegion container, const LineSegment check);
    bool contains(const CenterRegion container, const Circle check);

    bool contains(const Circle container, const Region check);
    bool contains(const Circle container, const CenterRegion check);
    bool contains(const Circle container, const Circle check);
    bool contains(const Circle container, const Point check);
    bool contains(const Circle container, const LineSegment check);

    bool contains(const Ray container, const Point check);
    bool contains(const LineSegment container, const Point check);

    //TODO: make a doesnotcontain function

    bool overlaps(const Region check1, const Region check2);
    bool overlaps(const Region check1, const CenterRegion check2);
    bool overlaps(const Region check1, const Circle check2);
    bool overlaps(const Region check1, const Ray check2);
    bool overlaps(const Region check1, const LineSegment check2);
    
    bool overlaps(const CenterRegion check1, const CenterRegion check2);
    bool overlaps(const CenterRegion check1, const Circle check2);
    bool overlaps(const CenterRegion check1, const Ray check2);
    bool overlaps(const CenterRegion check1, const LineSegment check2);

    bool overlaps(const Circle check1, const Circle check2);
    bool overlaps(const Circle check1, const Ray check2);
    bool overlaps(const Circle check1, const LineSegment check2);   

    bool overlaps(const Ray check1, const Ray check2);
    bool overlaps(const Ray check1, const LineSegment check2);

    bool overlaps(const LineSegment check1, const LineSegment check2);
}