#include "Rectangle.h"

//default constructor
Rectangle::Rectangle(){};

//constructor by two points
Rectangle::Rectangle(Plane newPlane) : plane(newPlane){};

//constructor by one point and length and width values.
Rectangle::Rectangle(Cooridinate newBottomLeftCorner, float length, float height){
    plane.bottomLeft = newBottomLeftCorner;
    plane.topRight = {newBottomLeftCorner.x + length, newBottomLeftCorner.y + height};
}

void Rectangle::moveTo(Cooridinate newPosition){
    //finds how much the rectangle has to move
    Cooridinate displacement = newPosition - plane.bottomLeft;

    plane.bottomLeft = newPosition;
    plane.topRight = plane.topRight + displacement;
};

void Rectangle::move(Cooridinate displacement){
    plane.bottomLeft = plane.bottomLeft + displacement;
    plane.topRight = plane.topRight + displacement;
};

Plane Rectangle::showMove(Cooridinate displacement){
    Plane movingTo = {{plane.bottomLeft + displacement},{plane.topRight + displacement}};
    return  movingTo;
}