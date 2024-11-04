#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#pragma once

#include "Object.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
    ObjectManager();
    ~ObjectManager();

    /// @brief returns the allObjects vector
    /// @return returns all objects. type: std::vector<Object*>
    std::vector<Object*> getAllObjects(){return allObjects; };

    /**
    * @details given name, returns an iterator to the object from the allObjects vector. Has no processing  of the iterator, if iterator = allObjects.end() it will return the iterator anyway.
    * 
    * @param objName a string of type std::string
    * @return returns an iterator to object of type: std::vector<Object*>::iterator
    */
    std::vector<Object*>::iterator getObjectIteratorByName(std::string objName);

    /**
     * @details Given name, returns pointer to object in allObjects. if the name given is not found, it returns nullptr.
     * @param objName name of the object to delete.
     * @return returns pointer of type Object.
     */
    Object *getObjectByName(std::string objName);
    
    /**
     * @brief Creates object of given object constructor parameters
     */
    void addObject(std::string objName);

    /**
     * @details Given name, it deletes the object with that name. Does not delete anything if allObjects is empty or name is not found in allObjects.
     */
    void removeObjectByName(std::string objName);

private:
    /// @brief Stores all game objects.
    std::vector<Object*> allObjects;
};

#endif