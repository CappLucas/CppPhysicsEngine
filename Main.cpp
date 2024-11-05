//file used for testing the features

#include "Header/Object.h"
#include "Header/ObjectManager.h"

#include <iostream>

int main(){
    ObjectManager myManager;
    myManager.addObject("myName","Rectangle",);

    Object* myObject = myManager.getObjectByName("myName");

    std::cout << myObject->


    return 0;
}