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
    
    Each object has a class  representing a shape it could possibly be
    ex:
        Object{
            public:
                //overloaded constructors for each object type

                //circle
                Object(std::string objType, std::pair<float,float> newPosition, float newRadius, std::pair<float,float> newVelocity = 0, 
                                std::pair<float,float> newAcceleration = 0, float newMass = 1) 

                                : objType(newObjType), objectCircle(new Circle(newPosition,newRadius), volicity(newVelocity), acceleration(newAcceleration), mass(newMass)){};

                //rectangle constructor
                Object(std::string newObjType, Plane newCorners, std::pair<float,float> newVelocity, std::pair<float,float> newAcceleration, float newMass)
                                : objType(newObjType), objectRectangle(new Rectangle(newCorners), velocity(newVelocity), acceleration(newAcceleration), mass(newMass)){};

                //triangle constructor
                    ---------------------Not sure on triangles yet ----------------
                //destructor
                ~Object{
                    delete objectCircle
                    delete objectRectangle
                    delete ObjectTriangle
                }
                
                //getters and setters

            private:
                std::string type

                float mass
                std::pair<float,float> accelleration
                std::pair<float,float> velocity
        
                bool affectedByObjects
                bool affectedByGravity

                Circle *objectCircle = nullptr;
                Rectangle *objectRectangle = nullptr;
                Triangle *objectTriangle = nullptr;
        }
        
---------------Example circle class ------------------
    Circle{
        public:
            -------------- constructor --------------
            Circle(std::pair<float,float> newCenter, float newradius) : radius(newRadius), center(newCenter){}

            ------------ getters --------------
            float getRadius(){}
            std::pair<float,float> getCenter(){}

            float getDiameter(){return radius*2}
            ------------ setters -------------
            void setradius
        private:
            //circle attributes
            float radius
            std::pair<float,float> center
    }
--------------- Example rectangle class ----------------
    Rectangle{
        public:
            ------------constructor----------------
            Rectangle(Plane newCorners) : plane(newCorners){}

            ----------- getters --------------------
            std::pair<float,float> getLength(){return plane.first.first - plane.second.first}
            sdt::pair<float,float> getHeight(){return plane.first.second - plane.second.first}

            float getXCenter(){return (plane.first.first + plane.second.first)/2}
            float getXCenter(){return (plane.first.second + plane.second.second)/2}

            std::pair<float,float> getCenter(){return {getXCenter(),getYCenter()}

            // ------------ setters -------------
            void changeLeftX(){}
            void changeRightX(){}
            void changeTopY(){}
            void changeBottomY(){}

            void move(){}
            
            void setMass();
            void setVelocity();
            void setAcceleration();

        private:
            // ------ rectangle attributes -------------
            std::pair<std::pair<float,float>,std::pair<float,float>> plane = {bottonLeftCorner,topRightCorner}
    }

        

        }
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
     * @brief Creates object of given object constructor parameters.
     * @param objName name of object to create.
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