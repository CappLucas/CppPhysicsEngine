#include "LineSegment.h"
#include "NewType.h"
#include "Compare.h"

#include <cmath>

namespace Geometry_Space{
    LineSegment::LineSegment(Point newStart, Point newEnd){
        start = newStart;

        if(newEnd != newStart){
            end = newEnd;
        }
        else{
            end = newEnd + newPoint(1.0f, 1.0f);
        }
    }
    
    Point LineSegment::getSlope() const {
        return newPoint(getStartX() - getEndX(), getStartY() - getEndY());
    }

    Point LineSegment::getInterceptY() const {
        Point slope = getSlope();
        if(isEqual(slope.x, 0)){
            return newPoint(-1, -1);
        }
        else{
            return newPoint(0, getStartY() - ((getSlope().y / getSlope().x) * getStartX()));
        }
    }
    float LineSegment::function(const float x) const {
        
    }
    void LineSegment::addVector(const Vector v){
        end.x += v.x;
        end.y += v.y;
    }
    void LineSegment::move(const Point displacement){
        start = start + displacement;
        end = end + displacement;
    }
    void LineSegment::setStart(const Point startPosition){
        // end = end + displacement.
        end = end + (startPosition - start);
        start = startPosition;
    }
    void LineSegment::moveStart(const Point displacement){
        start = start + displacement;
    }
    void LineSegment::moveEnd(const Point displacement){
        end = end + displacement;
    }
    //gets magnitude
    float LineSegment::getMagnitude() const {
        return std::sqrt(std::pow(end.x - start.x, 2) + std::pow(end.y - end.y, 2));
    }
    void LineSegment::setMagnitude(const float newMagnitude){
        float currentMagnitude = getMagnitude();
        //you have to set multily by the displacement instead of the end point to change the end relative to start
        end.x = ((end.x - start.x) * (newMagnitude / currentMagnitude) + start.x);
        end.y = ((end.y - start.y) * (newMagnitude / currentMagnitude) + start.y);
    }
    //changes the magnitude by changing end point
    void LineSegment::normalize(){
        float currentMagnitude = getMagnitude();
        //translate to origin, find new pos, and move back
        end.x = ((end.x - start.x) / currentMagnitude) + start.x;
        end.y = ((end.y - start.y) / currentMagnitude) + start.y;
    }
}