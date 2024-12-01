#pragma once

namespace Geometry_Space{
    struct Point{
        Point() = default;
        Point(float newX, float newY) : x(newX), y(newY){};

        float x{0.0f};
        float y{0.0f};

        Point operator + (const Point p) const;
        Point operator - (const Point p) const;
        Point operator * (const Point p) const;
        Point operator / (const Point p) const;

        bool operator == (const Point p) const;
        bool operator != (const Point p) const;

        //only returns true if both points are greater than or equal to the other points.
        bool operator >= (const Point p) const;
        bool operator <= (const Point p) const;
        bool operator > (const Point p) const;
        bool operator < (const Point p) const;

        void move(const Point displacement);
        void setPosition(const Point position);

        Point calculateNewPosition(const Point displacement) const;

        float distanceTo(const Point point) const;
    };
}