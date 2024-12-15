#include "Compare.h"
#include "ProgramVariables.h"

#include <cmath>

namespace Geometry_Space{
    bool isEqual(const float val1, const float val2){
        return std::abs(val1 - val2) <= Program_Variables_Space::COMPARISON_PRECISION;
    }
    bool contains(const float rangeStart, const float rangeEnd, const float value){
        if(value > rangeStart){
            return value < rangeEnd && value > rangeStart;
        }
        else if(value < rangeStart){
            return value > rangeEnd && value < rangeStart;
        }
        else{
            return false;
        }
    }

    //----------------------------------------------------Region contain functions-----------------------------------------
    bool contains(const Region container, const Region check){
        return check.getBottomLeft() > container.getBottomLeft() && check.getTopRight() < container.getTopRight();
    }
    bool contains(const Region container, const CenterRegion check){
        return check.getBottomLeft() > container.getBottomLeft() && check.getTopRight() < container.getTopRight();
    }
    bool contains(const Region container, const Point check){
        return check > container.getBottomLeft() && check < container.getTopRight();
    }
    bool contains(const Region container, const LineSegment check){
        //if const region contains both start and end points, it is inside.
        return contains(container, check.getStart()) && contains(container, check.getEnd());
    }
    bool contains(const Region container, const Circle check){
        return check.getBottomLeft() > container.getBottomLeft() && check.getTopRight() < container.getTopRight();
    }
    //----------------------------------------------------CenterRegion contain functions-----------------------------------------

    bool contains(const CenterRegion container, const Region check){
        return check.getBottomLeft() > container.getBottomLeft() && check.getTopRight() < container.getTopRight();
    }
    bool contains(const CenterRegion container, const CenterRegion check){
        return check.getBottomLeft() > container.getBottomLeft() && check.getTopRight() < container.getTopRight();
    }
    bool contains(const CenterRegion container, const Point check){
        return check > container.getBottomLeft() && check < container.getTopRight();
    }
    bool contains(const CenterRegion container, const LineSegment check){
        return contains(container, check.getStart()) && contains(container, check.getEnd());
    }
    bool contains(const CenterRegion container, const Circle check){
        return check.getBottomLeft() > container.getBottomLeft() && check.getTopRight() < container.getTopRight();
    }
    //----------------------------------------------------Circle contain functions-----------------------------------------

    bool contains(const Circle container, const Point check){
        //if distance from point to center is less the the radius, it is contained.
        return check.distanceTo(container.getCenter()) < container.getRadius();
    }
    bool contains(const Circle container, const Region check){
        return contains(container, check.getBottomLeft()) && contains(container, check.getTopLeft()) 
            && contains(container, check.getTopRight()) && contains(container, check.getBottomRight());
    }
    bool contains(const Circle container, const CenterRegion check){
        return contains(container, check.getBottomLeft()) && contains(container, check.getTopLeft()) 
            && contains(container, check.getTopRight()) && contains(container, check.getBottomRight());
    }
    bool contains(const Circle container, const Circle check){
        return check.getLeftX() > container.getLeftX() && check.getRightX() < container.getRightX()
            && check.getBottomY() > container.getBottomY() && check.getTopY() < container.getTopY();
    }
    bool contains(const Circle container, const LineSegment check){
        return contains(container, check.getStart()) && contains(container, check.getEnd());
    }
    //difference between this function and the overlap function is that this 
    //does not return true when the check value is on the start of the ray.
    bool contains(const Ray container, const Point check){
        float addX =  -(container.getStartX());
        float addY = -(container.getStartY());
        //if point is on the line and is on the right side, it contains.
        return isEqual(check.y, container.function(check.x).y)
         && (check.x + addX) * (container.getDirectionX() + addX) > 0 
         && (check.y + addY) * (container.getDirectionY() - addY) > 0;
    }
    bool contains(const LineSegment container, const Point check){
        float addX =  -(container.getStartX());
        float addY = -(container.getStartY());
        return isEqual(check.y, container.function(check.x).y) 
        && contains(container.getStartX(), container.getEndX(), check.x)
        && contains(container.getStartY(), container.getEndY(), check.y);
    }
    bool overlaps(const Region check1, const Point check2){
        return check2 >= check1.getBottomLeft() && check2 <= check1.getTopRight();
    }
    bool overlaps(const CenterRegion check1, const Point check2){
        return check2 >= check1.getBottomLeft() && check2 <= check1.getTopRight();
    }
    bool overlaps(const Circle check1, const Point check2){
        //if the distance from center to point is less than or equal to radius, it overlaps.
        return check2.distanceTo(check1.getCenter()) <= check1.getRadius();
    }
    bool overlaps(const Region check1, const Region check2){
        return check1.getRightX() > check2.getLeftX() && check1.getLeftX() < check2.getRightX()
                && check1.getTopY() > check2.getBottomY() && check1.getBottomY() < check2.getTopY();
    }
    bool overlaps(const Region check1, const CenterRegion check2){
        return check1.getRightX() > check2.getLeftX() && check1.getLeftX() < check2.getRightX()
                && check1.getTopY() > check2.getBottomY() && check1.getBottomY() < check2.getTopY();
    }
    bool overlaps(const Region check1, const Circle check2){
        //if distance from center to closest corner is less than the radius, it is overlapping.
        float closeX = std::abs(check1.getLeftX() - check2.getLeftX()) < std::abs(check1.getRightX() - check2.getRightX()) ? check1.getLeftX() : check1.getRightX();
        float closeY = std::abs(check1.getLeftX() - check2.getLeftX()) < std::abs(check1.getRightX() - check2.getRightX()) ? check1.getLeftX() : check1.getRightX();

        return std::pow(closeX, 2) + std::pow(closeY, 2) <= std::pow(check2.getRadius(), 2);
    }
    bool overlaps(const Region check1, const Ray check2){
        //accout for zero slope
        return isEqual(check2.function(check1.getLeftX()).y, )
    }
    bool overlaps(const Region check1, const LineSegment check2){

    }
}