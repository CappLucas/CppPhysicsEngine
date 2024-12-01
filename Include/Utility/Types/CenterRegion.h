#pragma once

#include "Point.h"

namespace Geometry_Space{
    class CenterRegion{
        public:
            CenterRegion() = default;
            CenterRegion(Point newCenter, float newWidth, float newHeight);

            float getWidth() const {return width;}
            float getHeight() const {return height;}
            float getTotalWidth() const {return width*2;}
            float getTotalHeight() const {return height*2;}

            float getLeftX() const {return center.x - width;}
            float getBottomY() const {return center.y - height;}
            float getRightX() const {return center.x + width;}
            float getTopY() const {return center.y + height;}

            Point getBottomLeft() const {return newPoint(getLeftX(), getBottomY());}
            Point getBottomRight() const {return newPoint(getRightX(), getBottomY());}
            Point getTopLeft() const {return newPoint(getLeftX(), getTopY());}
            Point getTopRight() const {return newPoint(getRightX(), getTopY());}

            float getCenterX() const {return center.x;}
            float getCenterY() const {return center.y;}
            Point getCenter() const {return center;}

            Point getBottomCenter() const {return newPoint(getCenterX(), getBottomY());}
            Point getTopCenter() const {return newPoint(getCenterX(), getTopY());}
            Point getRightCenter() const {return newPoint(getRightX(), getCenterY());}
            Point getLeftCenter() const {return newPoint(getLeftX(), getCenterY());}

            float getDiagnalLength() const;

            float getPerimeter() const {return (getWidth()*2) + (getHeight()*2);}
            float getArea() const {return getWidth() * getHeight();}

            //setters
            void setCenter(Point newCenter){center = newCenter;}

            void setWidth(float newWidth);
            void setHeight(float newHeight);
            void setTotalWidth(float newTotalWidth);
            void setTotalHeight(float newTotalHeight);

            void setLeftX(float x);
            void setRightX(float x);
            void setBottomY(float y);
            void setTopY(float y);

            void setBottomLeft(Point bl);
            void setTopRight(Point tp);
            void setBottomRight(Point br);
            void setTopLeft(Point tl);

            //methods
            void move(Point displacement);
            void setPosition(Point position);

            void shiftX(float xDisplacement);
            void shiftY(float yDisplacement);
        private:
            Point center{0.0f, 0.0f};

            float width{0.0f};
            float height{0.0f};
    };
}