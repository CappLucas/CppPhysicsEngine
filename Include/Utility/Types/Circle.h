#pragma once

#include "Point.h"

namespace Geometry_Space{
    class Circle{
        public:
            Circle() = default;
            Circle(Point newCenter, float newRadius);

            Point getCenter() const {return center;}
            float getRadius() const {return radius;}

            float getLeftX() const {return center.x - radius;}
            float getRightX() const {return center.x + radius;}
            float getBottomY() const {return center.y - radius;}
            float getTopY() const {return center.y + radius;}

            Point getLeftPoint() const {return Point(getLeftX(), center.y);}
            Point getRightPoint() const {return Point(getRightX(), center.y);}
            Point getBottomPoint() const {return Point(center.x, getBottomY());}
            Point getTopPoint() const {return Point(center.x, getTopY());}

            Point getBottomLeft() const {return Point(getLeftX(), getBottomY());}
            Point getTopLeft() const {return Point(getLeftX(), getTopY());}
            Point getTopRight() const {return Point(getRightX(), getTopY());}
            Point getBottomRight() const {return Point(getRightX(), getBottomY());}

            float getDiameter() const {return radius*2;}

            float getCircumference() const;
            float getArea() const;

            void setCenter(Point newCenter){center = newCenter;}
            void setRadius(float newRadius){if(newRadius > 0){radius = newRadius;}}

            void move(const Point displacement);
            void setPosition(const Point newPosition);


        private:
            Point center{0.0f, 0.0f};
            float radius{1.0f};
    };
}