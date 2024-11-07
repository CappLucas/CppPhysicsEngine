#ifndef OBJECT_H
#define OBJECT_H

#pragma once

#include "Types.h"

#include "PhysicsEquations.h"

#include "Circle.h"
#include "Rectangle.h"

#include <string>
#include <iostream>

class Object{
public:
    static float defaultMass;
    static float defaultGravity;

    //constructor for rectangle
    Object(std::string objName, std::string objType, Plane newPlane, Velocity newVelocity = {0,0}, Acceleration newAcceleration = {0,0}, float newMass = 1) : name(objName), type(objType), objectRectangle(new Rectangle(newPlane)),objectVelocity(newVelocity), objectAcceleration(newAcceleration), objectMass(newMass){}

    //constructor for circle
    Object(std::string objName, std::string objType, Cooridinate center, float radius, Velocity newVelocity = {0,0}, Acceleration newAcceleration = {0,0}, float newMass = 1) : name(objName), type(objType), objectCircle(new Circle(center,radius)), objectVelocity(newVelocity), objectAcceleration(newAcceleration), objectMass(newMass){}

    //public variables so that you can change them outside of class
    Circle *objectCircle = nullptr;
    Rectangle *objectRectangle = nullptr;

    //---------------- getters ---------------------
    std::string getName(){return name;}
    std::string getType(){return type;}

    float getMass(){return objectMass;}
    Velocity getVelocity(){return objectVelocity;}
    Acceleration getAcceleration(){return objectAcceleration;}

    bool getIsAffectedByObjects(){return isAffectedByObjects;}
    bool getIsAffectedByGravity(){return isAffectedByGravity;}
    
    //----------------- setters ---------------------
    void setMass(float newMass){if(newMass >= 0){objectMass = newMass;};}
    void setVelocity(Velocity newVelocity){objectVelocity = newVelocity;}
    void setAcceleration(Acceleration newAcceleration){objectAcceleration = newAcceleration;}

    //------------------ methods ----------------------
    //updates position and velocity based on acceleration and stuff
    void updateObject(float deltaTime);

private:
    std::string name;

    std::string type;

    float objectMass;
    Velocity objectVelocity;
    Acceleration objectAcceleration;
        
    bool isAffectedByObjects = true;
    bool isAffectedByGravity = true;

    //reference to the static gravity variable so that when you change the static you change all the others too.
    float &gravity = Object::defaultGravity;
};

#endif