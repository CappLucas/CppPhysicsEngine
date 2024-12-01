#include "Circle.h"
#include "Constants.h"

#include <numbers>
#include <cmath>


namespace Geometry_Space{
    Circle::Circle(Point newCenter, float newRadius){
        center = newCenter;
        if(newRadius > 0){
            radius = newRadius;
        }
        else{
            radius = 1.0f;
        }
    }
    float Circle::getCircumference() const {
        return getDiameter() * Constants_Space::PI_FLOAT;
    }
    float Circle::getArea() const {
        return Constants_Space::PI_FLOAT * std::pow(radius, 2);
    }
    void Circle::move(const Point displacement){
        center = center + displacement;
    }
    void Circle::setPosition(const Point newPosition){
        center = newPosition;
    }
}