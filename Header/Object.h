#ifndef OBJECT_H
#define OBJECT_H

#pragma once

#include "Types.h"

#include "Circle.h"
#include "Rectangle.h"

#include <string>
#include <iostream>

class Object{
public:
    static float defaultMass;
    
    //constructor for rectangle
    Object(std::string objName, std::string objType, Plane newPlane, Velocity newVelocity = {0,0}, Accelleration newAccelleration = {0,0}, float newMass = 1) : name(objName), type(objType), objectRectangle(new Rectangle(newPlane)),objectVelocity(newVelocity), objectAccelleration(newAccelleration), objectMass(newMass){};

    //constructor for circle
    Object(std::string objName, std::string objType, Cooridinate center, float radius, Velocity newVelocity = {0,0}, Accelleration newAccelleration = {0,0}, float newMass = 1) : name(objName), type(objType), objectCircle(new Circle(center,radius)), objectVelocity(newVelocity), objectAccelleration(newAccelleration), objectMass(newMass){};
    ~Object();

    //---------------- getters ---------------------
    std::string getName(){return name;}
    std::string getType(){return type;}

    float getMass(){return objectMass;}
    Velocity getVelocity(){return objectVelocity;}
    Accelleration getAccelleration(){return objectAccelleration;}

    bool getIsAffectedByObjects(){return isAffectedByObjects;}
    bool getIsAffectedByGravity(){return isAffectedByGravity;}
    
    //----------------- setters ---------------------
    void setMass(float newMass){if(newMass >= 0){objectMass = newMass;};}
    void setVelocity(Velocity newVelocity){objectVelocity = newVelocity;}
    void setAcceleration(Accelleration newAccelleration){objectAccelleration = newAccelleration;}

    //------------------ methods ----------------------
    //updates position and velocity based on accelleration and stuff
    void updateObject(float deltaTime);

private:
    std::string name;

    std::string type;

    float objectMass;
    Velocity objectVelocity;
    Accelleration objectAccelleration;
        
    bool isAffectedByObjects = true;
    bool isAffectedByGravity = true;

    Circle *objectCircle = nullptr;
    Rectangle *objectRectangle = nullptr;

    //reference to the static gravity variable so that when you change the static you change all the others too.
    float &gravity = ObjectManager::gravity;
};

#endif