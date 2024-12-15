#include "LineSegment.h"
#include "Compare.h"

#include <cmath>

namespace Geometry_Space{
    LineSegment::LineSegment(Point newStart, Point newEnd){
        start = newStart;

        if(newEnd != newStart){
            end = newEnd;
        }
        else{
            end = newEnd + Point(1.0f, 1.0f);
        }
    }
    
    Point LineSegment::getSlope() const {
        return Point(getStartX() - getEndX(), getStartY() - getEndY());
    }

    Point LineSegment::getInterceptY() const {
        Point slope = getSlope();
        if(isEqual(slope.x, 0)){
            return Point(-1, 0);
        }
        else{
            return Point(0, getStartY() - ((slope.y / slope.x) * getStartX()));
        }
    }
    //if the slope is undifined, it returns a point of (x-1, 0) else, returns a point of the 
    //given parameter x, and the coorisponding y value from the lines functions.
    Point LineSegment::function(const float x) const {
        Point intercept = getInterceptY();
        Point slope = getSlope();

        if(isEqual(slope.x, -1)){
            return Point(x-1, 0);
        }
        else{
            return Point(x, (slope.y/slope.x)*x + intercept.y);
        }
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