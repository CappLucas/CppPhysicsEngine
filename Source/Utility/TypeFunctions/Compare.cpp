#include "Compare.h"
#include "ProgramVariables.h"

#include <cmath>

namespace Geometry_Space{
    bool isEqual(float val1, float val2){
        return std::abs(val1 - val2) <= Program_Variables_Space::COMPARISON_PRECISION;
    }
    //----------------------------------------------------Region contain functions-----------------------------------------
    bool contains(Region container, Region check){
        return check.getBottomLeft() > container.getBottomLeft() && check.getTopRight() < container.getTopRight();
    }
    bool contains(Region container, CenterRegion check){
        return check.getBottomLeft() > container.getBottomLeft() && check.getTopRight() < container.getTopRight();
    }
    bool contains(Region container, Point check){
        return check > container.getBottomLeft() && check < container.getTopRight();
    }
    bool contains(Region container, LineSegment check){
        //if region contains both start and end points, it is inside.
        return contains(container, check.getStart()) && contains(container, check.getEnd());
    }
    bool contains(Region container, Circle check){
        return check.getBottomLeft() > container.getBottomLeft() && check.getTopRight() < container.getTopRight();
    }
    //----------------------------------------------------CenterRegion contain functions-----------------------------------------

    bool contains(CenterRegion container, Region check){
        return check.getBottomLeft() > container.getBottomLeft() && check.getTopRight() < container.getTopRight();
    }
    bool contains(CenterRegion container, CenterRegion check){
        return check.getBottomLeft() > container.getBottomLeft() && check.getTopRight() < container.getTopRight();
    }
    bool contains(CenterRegion container, Point check){
        return check > container.getBottomLeft() && check < container.getTopRight();
    }
    bool contains(CenterRegion container, LineSegment check){
        return contains(container, check.getStart()) && contains(container, check.getEnd());
    }
    bool contains(CenterRegion container, Circle check){
        return check.getBottomLeft() > container.getBottomLeft() && check.getTopRight() < container.getTopRight();
    }
    //----------------------------------------------------Circle contain functions-----------------------------------------

    bool contains(Circle container, Point check){
        //if distance from point to center is less the the radius, it is contained.
        return check.distanceTo(container.getCenter()) < container.getRadius();
    }
    bool contains(Circle container, Region check){
        return contains(container, check.getBottomLeft()) && contains(container, check.getTopLeft()) 
            && contains(container, check.getTopRight()) && contains(container, check.getBottomRight());
    }
    bool contains(Circle container, CenterRegion check){
        return contains(container, check.getBottomLeft()) && contains(container, check.getTopLeft()) 
            && contains(container, check.getTopRight()) && contains(container, check.getBottomRight());
    }
    bool contains(Circle container, Circle check){
        return check.getLeftX() > container.getLeftX() && check.getRightX() < container.getRightX()
            && check.getBottomY() > container.getBottomY() && check.getTopY() < container.getTopY();
    }
    bool contains(Circle container, LineSegment check){
        return contains(container, check.getStart()) && contains(container, check.getEnd());
    }
    //difference between this function and the overlap is that this 
    //does not return true when value is on the start of the ray.
    bool contains(Ray container, Point check){
        float addX =  -(container.getStartX());
        float addY = -(container.getStartY());

        return isEqual(check.y, container.function(check.x))
         && (check.x + addX) * (container.getDirectionX() + addX) > 0 
         && (check.y + addY) * (container.getDirectionY() - addY) > 0;
    }
    bool contains(LineSegment container, Point check){
        return
    }
}