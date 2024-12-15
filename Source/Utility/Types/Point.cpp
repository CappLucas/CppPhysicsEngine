#include "Point.h"
#include "ProgramVariables.h"

#include <cmath>

using namespace Program_Variables_Space;

namespace Geometry_Space{
    Point Point::operator + (const Point p) const {
        return Point(x + p.x, y + p.y);
    }
    Point Point::operator - (const Point p) const {
        return Point(x - p.x, y - p.y);
    }
    Point Point::operator * (const Point p) const {
        return Point(x * p.x, y * p.y);
    }
    Point Point::operator / (const Point p) const {
        return Point(x / p.x, y / p.y);
    }
    bool Point::operator == (const Point p) const {
        //if less than a certain distance (COMPARISON_PRECISION), they are equal
        return std::abs(x - p.x) <= COMPARISON_PRECISION && std::abs(y - p.y) <= COMPARISON_PRECISION;
    };

    bool Point::operator != (const Point p) const {
        return std::abs(x - p.x) > COMPARISON_PRECISION || std::abs(y - p.y) > COMPARISON_PRECISION;
    };
    bool Point::operator >= (const Point p) const {
        return x >= p.x && y >= p.y;
    }
    bool Point::operator <= (const Point p) const {
        return x <= p.x && y <= p.y;
    }
    bool Point::operator > (const Point p) const {
        return x > p.x && y > p.y;
    }
    bool Point::operator < (const Point p) const {
        return x < p.x && y < p.y;
    }
    void Point::move(const Point displacement){
        x += displacement.x;
        y += displacement.y;
    }
    void Point::setPosition(const Point position){
        x = position.x;
        y = position.y;
    }
    Point Point::calculateNewPosition(const Point displacement) const {
        return Point(displacement + Point(x, y));
    }
    float Point::distanceTo(const Point point) const {
        return std::sqrt(std::pow(point.x - x, 2) + std::pow(point.y - y, 2));
    }
}