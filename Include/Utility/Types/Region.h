#pragma once

#include "Point.h"

namespace Geometry_Space{
    class Region{
        public:
            Region() = default;
            Region(Point newBottomLeft, Point newTopRight);

            //getters
            float getWidth() const {return topRight.x - bottomLeft.x;}
            float getHeight() const {return topRight.y - bottomLeft.y;}

            float getLeftX() const {return bottomLeft.x;}
            float getBottomY() const {return bottomLeft.y;}
            float getRightX() const {return topRight.x;}
            float getTopY() const {return topRight.y;}

            float getCenterX() const {return getLeftX() + (getWidth()/2);}
            float getCenterY() const {return getBottomY() + (getWidth()/2);}

            Point getBottomLeft() const {return bottomLeft;}
            Point getBottomRight() const {return Point(getRightX(), getBottomY());}
            Point getTopLeft() const {return Point(getLeftX(), getTopY());}
            Point getTopRight() const {return topRight;}

            Point getCenter() const {return Point(getLeftX() + (getWidth()/2), getBottomY() + (getHeight()/2));}

            Point getBottomCenter() const {return Point(getCenterX(), getBottomY());}
            Point getTopCenter() const {return Point(getCenterX(), getTopY());}
            Point getRightCenter() const {return Point(getRightX(), getCenterY());}
            Point getLeftCenter() const {return Point(getLeftX(), getCenterY());}

            float getDiagnalLength() const;

            float getPerimeter() const {return (getWidth()*2) + (getHeight()*2);}
            float getArea() const {return getWidth() * getHeight();}

            //setters
            void setLeftX(float x);
            void setRightX(float x);
            void setBottomY(float y);
            void setTopY(float y);

            void setBottomLeft(Point bl);
            void setTopRight(Point tp);
            void setBottomRight(Point br);
            void setTopLeft(Point tl);

            void setCenter(Point center);
            //methods
            void move(Point displacement);
            void setPosition(Point position);

            void shiftX(float xDisplacement);
            void shiftY(float yDisplacement);

        private:
            Point bottomLeft;
            Point topRight;
    };
}