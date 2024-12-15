#include "CenterRegion.h"
#include "Point.h"

#include <cmath>

namespace Geometry_Space{
    CenterRegion::CenterRegion(Point newCenter, float newWidth, float newHeight){
        center = newCenter;
        if(newWidth > 0 && newHeight > 0){
            width = newWidth;
            height = newHeight;
        }
        else{
            width = 1.0f;
            height = 1.0f;
        }
    };

    //getters
    float CenterRegion::getDiagnalLength() const {
        return std::sqrt(std::pow(getWidth(), 2) + std::pow(getHeight(), 2));
    }
    //setters
    void CenterRegion::setWidth(float newWidth){
        if(newWidth > 0){width = newWidth;}
    }
    void CenterRegion::setHeight(float newHeight){
        if(newHeight > 0){height = newHeight;}
    }
    void CenterRegion::setTotalWidth(float newTotalWidth){
        if(newTotalWidth > 0){width = newTotalWidth/2;}
    }
    void CenterRegion::setTotalHeight(float newTotalHeight){
        if(newTotalHeight > 0){height = newTotalHeight/2;}
    }
    //moves the coorid and the center.
    void CenterRegion::setLeftX(float newLeft){
        float right = getRightX();

        if(newLeft < right){
            width = (right - newLeft)/2;
            center = Point(right-width, getCenterY());
        }
    }
    void CenterRegion::setRightX(float newRight){
        float left = getLeftX();

        if(newRight > left){
            width = (newRight - left)/2;
            center = Point(left + width, getCenterY());
        }
    }
    void CenterRegion::setBottomY(float newBottom){
        float top = getTopY();
        
        if(newBottom < top){
            height = (top - newBottom)/2;
            center = Point(getCenterX(), top - height);
        }
    }
    void CenterRegion::setTopY(float newTop){
        float bottom = getBottomY();

        if(newTop > bottom){
            height = (newTop - bottom)/2;
            center = Point(getCenterX(), bottom + height);
        }
    }
    void CenterRegion::setBottomLeft(Point newBottomLeft){
        Point anchor = getTopRight();
        
        if(newBottomLeft.x < anchor.x && newBottomLeft.y < anchor.y){
            width = (anchor.x - newBottomLeft.x)/2;
            height = (anchor.y - newBottomLeft.y)/2;
            center = anchor - Point(width, height);
        }
    }
    void CenterRegion::setTopRight(Point newTopRight){
        Point anchor = getBottomLeft();

        if(newTopRight.x > anchor.x && newTopRight.y > anchor.y){
            width = (newTopRight.x - anchor.x)/2;
            height = (newTopRight.y - anchor.y)/2;
            center = anchor + Point(width, height);
        }
    }
    void CenterRegion::setBottomRight(Point newBottomRight){
        Point anchor = getTopLeft();

        if(newBottomRight.x > anchor.x && newBottomRight.y < anchor.y){
            width = (newBottomRight.x - anchor.x)/2;
            height = (anchor.y - newBottomRight.y)/2;
            center = Point(anchor.x + width, anchor.y - height);
        }
    }
    void CenterRegion::setTopLeft(Point newTopLeft){
        Point anchor = getBottomRight();

        if(newTopLeft.x < anchor.x && newTopLeft.y > anchor.y){
            width = (anchor.x - newTopLeft.x)/2;
            height = (newTopLeft.y - anchor.y)/2;
            center = Point(anchor.x - width, anchor.y + height);
        }
    }
    //methods
    void CenterRegion::move(Point displacement){
        center = center + displacement;
    }
    void CenterRegion::setPosition(Point position){
        center = position;
    }
    void CenterRegion::shiftX(float xDisplacement){
        center.x += xDisplacement;
    }
    void CenterRegion::shiftY(float yDisplacement){
        center.y += yDisplacement;
    }
}