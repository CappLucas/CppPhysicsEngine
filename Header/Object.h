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
    static int objects;

    static float defaultMass;
    static float defaultGravity;

    //constructor for rectangle
    Object(std::string newName, std::string objType, Plane newPlane, Velocity newVelocity = {0,0}, Acceleration newAcceleration = {0,0}, float newMass = 1) : name(newName), type(objType), objectRectangle(new Rectangle(newPlane)),objectVelocity(newVelocity), objectAcceleration(newAcceleration), objectMass(newMass){
        id = objects;
        objects++;
    }

    //constructor for circle
    Object(std::string newName, std::string objType, Cooridinate center, float radius, Velocity newVelocity = {0,0}, Acceleration newAcceleration = {0,0}, float newMass = 1) : name(newName), type(objType), objectCircle(new Circle(center,radius)), objectVelocity(newVelocity), objectAcceleration(newAcceleration), objectMass(newMass){
        id = objects;
        objects++;
    }

    //public variables so that you can change them outside of class
    Circle *objectCircle = nullptr;
    Rectangle *objectRectangle = nullptr;

    //---------------- getters ---------------------
    std::string getName(){return name;}

    int getId(){return id;}
    
    std::string getType(){return type;}

    float getMass(){return objectMass;}
    Velocity getVelocity(){return objectVelocity;}
    Acceleration getAcceleration(){return objectAcceleration;}

    bool getIsAffectedByObjects(){return isAffectedByObjects;}
    bool getIsAffectedByGravity(){return isAffectedByGravity;}
    
    float getGravity(){return gravity;}
    float getElasticity(){return elasticity;}

    //----------------- setters ---------------------
    void setMass(float newMass){if(newMass >= 0){objectMass = newMass;};}
    void setVelocity(Velocity newVelocity){objectVelocity = newVelocity;}
    void setAcceleration(Acceleration newAcceleration){objectAcceleration = newAcceleration;}
    
    void setGravity(float newGravity){gravity = newGravity;}
    void setElasticity(float newElasticity){if(newElasticity >= 0 && newElasticity <= 1){elasticity = newElasticity;}}

    void setIsAffectedByObjects(bool newBool){isAffectedByObjects = newBool;}
    void setIsAffectedByGravity(bool newBool){isAffectedByGravity = newBool;}

    //------------------ methods ----------------------
    //updates the position of the object based on the current velocity, acceleration, mass, gravity, elasticity, and other boolean values.
    //no collision detection takes place.
    void updateObject(float deltaTime);

private:
    int id;

    std::string name;
    
    std::string type;

    float objectMass;
    Velocity objectVelocity;
    Acceleration objectAcceleration;
        
    bool isAffectedByObjects = true;
    bool isAffectedByGravity = true;

    //reference to the static gravity variable so that when you change the static you change all the others too.
    float gravity = Object::defaultGravity;

    float elasticity = 1; //perfectly elastic, and zero is perfectly inelastic.
};

#endif