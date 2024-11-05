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
    Object(std::string objName, std::string objType, Plane newPlane, Velocity newVelocity = {0,0}, Accelleration newAccelleration = {0,0}, float newMass = 1) : name(objName), type(objType), objectRectangle(new Rectangle(newPlane)),velocity(newVelocity), accelleration(newAccelleration), mass(newMass){};

    //constructor for circle
    Object(std::string objName, std::string objType, Cooridinate center, float radius, Velocity newVelocity = {0,0}, Accelleration newAccelleration = {0,0}, float newMass = 1) : name(objName), type(objType), objectCircle(new Circle(center,radius)), velocity(newVelocity), accelleration(newAccelleration), mass(newMass){};
    ~Object();

    //---------------- getters ---------------------
    std::string getName(){return name;}
    std::string getType(){return type;}

    float getMass(){return mass;}
    Velocity getVelocity(){return velocity;}
    Accelleration getAccelleration(){return accelleration;}

    bool getIsAffectedByObjects(){return isAffectedByObjects;}
    bool getIsAffectedByGravity(){return isAffectedByGravity;}
    
    //----------------- setters ---------------------
    void setMass(float newMass){if(newMass >= 0){mass = newMass;};}
    void setVelocity(Velocity newVelocity){velocity = newVelocity;}
    void setAcceleration(Accelleration newAccelleration){accelleration = newAccelleration;}

private:
    std::string name;

    std::string type;

    float mass;
    Velocity velocity;
    Accelleration accelleration;
        
    bool isAffectedByObjects = true;
    bool isAffectedByGravity = true;

    Circle *objectCircle = nullptr;
    Rectangle *objectRectangle = nullptr;
};

#endif