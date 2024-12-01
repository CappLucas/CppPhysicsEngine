#include "Ray.h"

#include "NewType.h"

#include "PhysicsEquations.h"

namespace Geometry_Space{
    Ray::Ray(Point newStart, Point newDirection){
        start = newStart;
        
        if(newDirection != newStart){
            direction = newDirection;
        }
        else{
            direction = newDirection + newPoint(1.0f, 1.0f);
        }
    }
    float Ray::getSlope() const {
        return (start.y - direction.y)/(start.x - direction.x);
    }
    float Ray::getInterceptY() const {
        return start.y - (getSlope()*start.x);
    }
    float Ray::function(float x) const {
        return getSlope()*x + getInterceptY();
    }
    //TODO: MAKE SURE NO DEVIDING BY ZERO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //sets the start to (0, y-intercept) and direction accordingly
    void Ray::setEquation(float m, float b){
        //set start as y intercept and then set direction according to the slope and start
        start = newPoint(0, b);
        //sets direction as the what ever point falls on the new line and is on x = 1.
        direction = newPoint(1, lineFunction(m, 1, b));
    }
    void Ray::setSlope(float slope){
        direction = newPoint(start.x+1, lineFunction(slope, 1, getInterceptY()));
    }
    void Ray::setInterceptY(float intercept){
        //set start to intercept and then set the direction accordingly
        float slope = getSlope();
        start = newPoint(0, intercept);

        direction = newPoint(1, lineFunction(slope, 1, intercept));
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