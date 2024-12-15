#include "Region.h"
#include <cmath>

namespace Geometry_Space{
    Region::Region(Point newBottomLeft, Point newTopRight){
        bottomLeft = newBottomLeft;

        if(newBottomLeft < newTopRight){
            topRight = newTopRight;
        }
        else{
            topRight = newBottomLeft + Point(1.0f, 1.0f);
        }
    }
    float Region::getDiagnalLength() const {
        return std::sqrt(std::pow(getWidth(), 2) + std::pow(getHeight(), 2));
    }     
    void Region::setLeftX(float x){
        if(x < getRightX()){bottomLeft.x = x;}
    }
    void Region::setRightX(float x){
        if(x > getLeftX()){topRight.x = x;}
    }
    void Region::setBottomY(float y){
        if(y < getTopY()){bottomLeft.y = y;}
    }
    void Region::setTopY(float y){
        if(y > getBottomY()){topRight.y = y;}
    }
    void Region::setBottomLeft(Point bl){
        if(bl.x < getRightX() && bl.y < getTopY()){bottomLeft = bl;}
    }
    void Region::setTopRight(Point tp){
        if(tp.x > getLeftX() && tp.y > getBottomY()){topRight = tp;}
    }
    void Region::setBottomRight(Point br){
        if(br.x > getLeftX() && br.y < getTopY()){bottomLeft = br;}
    }
    void Region::setTopLeft(Point tl){
        if(tl.x < getRightX() && tl.y > getBottomY()){bottomLeft = tl;}
    }
    void Region::setCenter(Point center){
        //gets distance of center from bottom left
        Point centerDistance = getCenter() - bottomLeft;

        bottomLeft = center - centerDistance;
        topRight = center + centerDistance;
    }

    void Region::move(Point displacement){
        bottomLeft = bottomLeft + displacement;
        topRight = topRight + displacement;
    }
    void Region::setPosition(Point position){
        //adjust top right based on the bottom left.
        topRight = position + Point(getWidth(), getHeight());
        bottomLeft = position;
    }
    void Region::shiftX(float xDisplacement){
        bottomLeft.x += xDisplacement;
    }
    void Region::shiftY(float yDisplacement){
        bottomLeft.y += yDisplacement;
    }
}