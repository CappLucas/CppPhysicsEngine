#include "Vector.h"

#include <cmath>

#include "NewType.h"

namespace Geometry_Space{
    float Vector::getMagnitude() const {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    }
    float Vector::setMagnitude(const float newMagnitude) {
        float currentMagnitude = getMagnitude();
        x = x * (newMagnitude / currentMagnitude);
        y = y * (newMagnitude / currentMagnitude);
    }
    Vector Vector::operator + (const Vector v) const {
        return newVector(x + v.x, y + v.y);
    }
    Vector Vector::operator - (const Vector v) const {
        return newVector(x - v.x, y - v.y);
    }
    Vector Vector::operator * (const float scalar) const {
        return newVector(x * scalar, y * scalar);
    }
    Vector Vector::operator / (const float scalar) const {
        return newVector(x / scalar, y / scalar);
    }
    void Vector::normalize() {
        x = x/getMagnitude();
        y = y/getMagnitude();
    }
}