#pragma once

namespace Geometry_Space{
    struct Vector{
        Vector() = default;
        Vector(float newX, float newY) : x(newX), y(newY){};

        float x{0.0f};
        float y{0.0f};

        float getMagnitude() const;
        float setMagnitude(float magnitude);

        Vector operator + (const Vector v) const;
        Vector operator - (const Vector v) const;
        Vector operator * (const float scalar) const;
        Vector operator / (const float scalar) const;

        void normalize();
    };
}