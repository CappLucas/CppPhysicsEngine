//file used for testing the features

#include "Header/Object.h"
#include "Header/ObjectManager.h"

#include <iostream>

int main(){
    ObjectManager myManager;

    Object::defaultMass = 20;
    Object::defaultGravity = 12;

    myManager.addObject("MyRectangle", "Rectangle", {{100,150},{200,250}}, {20,20},{20,10});

    myManager.addObject("MyCircle", "Circle", {100,100}, 20, {100,300}, {10,20}, 100);
    
    myManager.printObjectInfo();

    myManager.removeObjectByName("MyCircle");

    myManager.printObjectInfo();

    return 0;
}