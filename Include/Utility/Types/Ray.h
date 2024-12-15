#pragma once

#include "Point.h"
#include "Vector.h"

namespace Geometry_Space{
    class Ray{
        public:
            Ray() = default;
            Ray(Point newStart, Point newDirection);

            Point getStart() const {return start;}
            Point getDirection() const {return direction;}

            float getStartX() const {return start.x;}
            float getStartY() const {return start.y;}
            float getDirectionX() const {return direction.x;}
            float getDirectionY() const {return direction.y;}

            Point getSlope() const;
            Point getInterceptY() const;
            Point function(float x) const;

            void setEquation(float m, float b);
            void setSlope(float slope);
            void setInterceptY(float intercept);

            void setStart(Point newStart);
            void setDirection(Point newDirection);

            void move(const Point displacement);
            void setPosition(const Point position);

            void addVector(const Vector v);
            void changeSlope(const Point slope);
            void changeDirection(const Point newDirection); 
        private:
            Point start{0.0f, 0.0f};
            Point direction{0.0f, 0.0f};
    };
}