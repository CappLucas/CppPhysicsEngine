#include "NewType.h"

namespace Geometry_Space{
    Point newPoint(const Point newPoint){
        return newPoint;
    }
    Point newPoint(float x, float y){
        Point newPoint(x, y);
        return newPoint;
    }
    Vector newVector(const Vector newVector){
        return newVector;
    }
    Vector newVector(float x, float y){
        Vector newVector(x, y);
        return newVector;
    }
}