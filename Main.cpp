//file used for testing the features

#include "Header/Object.h"
#include "Header/ObjectManager.h"

#include <iostream>

int main(){
    ObjectManager myManager;
    myManager.addObject("myName");

    Object* myObject = myManager.getObjectByName("myName");

    std::cout << myObject->getName();

    myManager.removeObjectByName("myName");
    

    return 0;
}