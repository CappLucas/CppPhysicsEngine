#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#pragma once

#include "Object.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*------------------------class Structure ------------------

We have a Object Manager that contains the game objects.

We give the object manager an instance of collision manager that has a reference to all objects.

Each object has certain properties that are used depending on shape type.
    
Each object has a class representing a shape it could be and things like velocity, mass, and accelleration

*/
/**
 * @class ObjectManager
 * @brief Manages game objects, including creation, storage, and deletion.
 * 
 * The ObjectManager class is responsible for handling all game objects
 * within the simulation. It provides methods to add, remove, and retrieve
 * objects by their names, as well as to access the complete list of objects.
 */
class ObjectManager{
public:
    ~ObjectManager();
    
    static float gravity;
    /// @brief returns the allObjects vector
    /// @return returns all objects. type: std::vector<Object*>
    std::vector<Object*> getAllObjects(){return allObjects; };

    /**
    * @details given name, returns an iterator to the object from the allObjects vector. Has no processing  of the iterator, if iterator = allObjects.end() it will return the iterator anyway.
    * 
    * @param objName a string of type std::string
    * @return returns an iterator to object of type: std::vector<Object*>::iterator
    */
    std::vector<Object*>::iterator getObjectIterator(std::string objName);
    std::vector<Object*>::iterator getObjectIterator(int objId);

    /**
     * @details Given name, returns pointer to object in allObjects. if the name given is not found, it returns nullptr.
     * @param objName name of the object to delete.
     * @return returns pointer of type Object.
     */
    Object *getObject(std::string objName);
    Object *getObject(int objId);
    /**
     * @brief Creates object of given object constructor parameters.
     * @param objName name of object to create.
     */
    void addObject(std::string newName, std::string objType, Plane newPlane, Velocity newVelocity = {0,0}, Acceleration newAcceleration = {0,0}, float newMass = 1);
    void addObject(std::string newName, std::string objType, Cooridinate center, float radius, Velocity newVelocity = {0,0}, Acceleration newAcceleration = {0,0}, float newMass = 1);
    /**
     * @details Given name, it deletes the object with that name. Does not delete anything if allObjects is empty or name is not found in allObjects.
     */
    void removeObject(std::string objId);
    void removeObject(int objId);

    void printObjectInfo();
    // updates the position and velocity of the object based on delta time.
    void updateObjects(float deltaTime);
private:
    /// @brief Stores all game objects.
    std::vector<Object*> allObjects;
};

#endif