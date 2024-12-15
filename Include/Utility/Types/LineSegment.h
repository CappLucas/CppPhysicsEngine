#pragma once

#include "Point.h"
#include "Vector.h"

namespace Geometry_Space{
    class LineSegment{
        public:
            LineSegment() = default;
            LineSegment(Point newStart, Point newEnd);

            Point getStart() const {return start;}
            Point getEnd() const {return end;}
            
            float getStartX() const {return start.x;}
            float getStartY() const {return start.y;}
            float getEndX() const {return end.x;}
            float getEndY() const {return end.y;}

            float getMagnitude() const;
            
            //return points instead of floats. this helps avoid undifined values from deviding by 0.
            Point getSlope() const;
            Point getInterceptY() const;
            Point function(const float x) const;

            void addVector(const Vector v);

            void move(Point displacement);

            void setStart(Point startPosition);
            void setEnd(Point endPosition);
            
            void moveStart(Point displacement);
            void moveEnd(Point displacement);

            void setMagnitude(float magnitude);

            void normalize();

        private:
            Point start{0.0f, 0.0f};
            Point end{1.0f, 1.0f};
    };
}
