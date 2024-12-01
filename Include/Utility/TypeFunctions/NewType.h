#pragma once

#include "Point.h"
#include "Vector.h"
#include "LineSegment.h"
#include "Ray.h"
#include "Region.h"
#include "CenterRegion.h"

namespace Geometry_Space{
    Point newPoint(const Point newPoint);
    Point newPoint(const float x, const float y);

    Vector newVector(const Vector newVector);
    Vector newVector(float x, float y);

    Ray newRay(const Ray newRay);
    Ray newRay(const Point start, const Point direction);

    LineSegment newLineSegment(const LineSegment newLineSegment);
    LineSegment newLineSegment(const Point start, const Point end);
    
    Region newRegion(const Region newRegion);
    Region newRegion(const Point bottomLeft, const Point topRight);

    CenterRegion newCenterRegion(const CenterRegion newCenterRegion);
    CenterRegion newCenterRegion(const Point newCenter, const float width, const float height);
}