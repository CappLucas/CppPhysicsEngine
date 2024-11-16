//file used for testing the features

#include "Include/Header/Object.h"
#include "Include/Header/ObjectManager.h"

#include <iostream>
#include <vector>

int main(){
    
    ObjectManager myManager;

    Object::defaultMass = 20;
    Object::defaultGravity = -29;

    myManager.addObject("MyRectangle", "Rectangle", {{100,150},{200,250}}, {20,20},{0,10});

    myManager.addObject("MyCircle", "Circle", {100,100}, 20, {100,300}, {10,20}, 100);
    

    std::cout << "Original:  \n\n" << std::endl;
    myManager.printObjectInfo();
    
    for(int i  = 0; i < 20; i++){
        myManager.updateObjects(1);
        std::cout << "Update " << i+1 << ":  \n" << std::endl;
        myManager.printObjectInfo();
        std::cout << "\n";
    }
    
    return 0;
}