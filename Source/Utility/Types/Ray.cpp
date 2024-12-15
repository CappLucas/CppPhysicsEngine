#include "Ray.h"

#include "Compare.h"
#include "PhysicsEquations.h"

namespace Geometry_Space{
    Ray::Ray(Point newStart, Point newDirection){
        start = newStart;
        
        if(newDirection != newStart){
            direction = newDirection;
        }
        else{
            direction = newDirection + Point(1.0f, 1.0f);
        }
    }
    Point Ray::getSlope() const {
        return Point(getDirectionX()-getStartX(), getDirectionY()-getStartY());
    }
    Point Ray::getInterceptY() const {
        Point slope = getSlope();
        if(isEqual(slope.x, 0)){
            return Point(-1, 0);
        }
        else{
            return Point(0, getStartY() - (slope.x*getStartX()));
        }
    }
    Point Ray::function(float x) const {
        Point slope = getSlope();
        if(isEqual(slope.x, -1)){
            return Point(x-1, 0);
        }
        else{
            return Point(0, (slope.y/slope.x)*x + getInterceptY().y);
        }
    }
    //sets the start to (0, y-intercept) and direction accordingly
    void Ray::setEquation(float m, float b){
        //set start as y intercept and then set direction according to the slope and start
        start = Point(0, b);
        //sets direction as the what ever point falls on the new line and is on x = 1.
        direction = Point(1, lineFunction(m, 1, b));
    }
    void Ray::setSlope(float slope){
        direction = Point(start.x+1, lineFunction(slope, 1, getInterceptY().y));
    }
    void Ray::setInterceptY(float intercept){
        //set start to intercept and then set the direction accordingly
        float slope = getSlope().y;
        start = Point(0, intercept);

        direction = Point(1, lineFunction(slope, 1, intercept));
    }
    void Ray::setStart(Point newStart){
        if(newStart != direction){
            start = newStart;
        }
    }
    void Ray::setDirection(Point newDirection){
        if(newDirection != start){
            direction = newDirection;
        }
    }
    void Ray::move(const Point displacement){
        start = start + displacement;
    }
    void Ray::setPosition(const Point position){
        start = position;
    }
        
    void Ray::addVector(const Vector v){
        direction.x += v.x;
        direction.y += v.y;
    }
    void Ray::changeSlope(const Point slope){
        direction = (start) * slope;
    }
    void Ray::changeDirection(const Point newDirection){
        direction = newDirection;
    }
    
}