//file used for testing the features

#include "Header/Object.h"
#include "Header/ObjectManager.h"

#include <iostream>

int main(){
    ObjectManager myManager;
    Object::defaultMass = 20;
    myManager.addObject("MyRectangle", "Rectangle", {{100,150},{200,250}}, {20,20},{20,10});

    Object* myObject = myManager.getObjectByName("MyRectangle");

    std::cout << "Velocity {x,y}: {" << myObject->getVelocity().x << ", " <<myObject->getVelocity().y << "}   " << myObject->getAccelleration().x << myObject->getAccelleration().y << myObject->getMass() << std::endl;
    
    std::cout << myObject->getMass() << std::endl;

    myManager.printObjectInfo();

    //TODO: produced errors for some reason, note there was a segmation fault -----------------------
    Object* myCircle = myManager.getObjectByName("MyCircle");
    myCircle->setMass(100);
    std::cout << myCircle->getMass() << std::endl;

    return 0;
}