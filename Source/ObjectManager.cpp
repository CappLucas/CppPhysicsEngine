#include "ObjectManager.h"

float gravity = 0;

//deletes dynamically stored objects
ObjectManager::~ObjectManager()
{
    for(Object *objIterator : allObjects){
        delete objIterator;
    }
    allObjects.clear();
    std::cout << "Objects deleted." << std::endl;
}

//overloaded for finding with name
std::vector<Object*>::iterator ObjectManager::getObjectIterator(std::string objName){
    auto conditions = [&objName](Object* &objIt){
        return objIt->getName() == objName;
    };

    std::vector<Object*>::iterator objectIterator = std::find_if(allObjects.begin(), allObjects.end(),conditions);
    
    return objectIterator;
}
//overloaded object iterator for finding with ids
std::vector<Object*>::iterator ObjectManager::getObjectIterator(int newId){
    auto conditions = [&newId](Object* &objIt){
        return objIt->getId() == newId;
    };

    std::vector<Object*>::iterator objectIterator = std::find_if(allObjects.begin(), allObjects.end(),conditions);
    
    return objectIterator;
}
//overloaded for name
Object *ObjectManager::getObject(std::string objName){
    std::vector<Object*>::iterator objectIterator = getObjectIterator(objName);
    
    if(objectIterator != allObjects.end()){
        return *objectIterator;
    }
    else{
        return nullptr;
    }
}
//overloaded for id
Object *ObjectManager::getObject(int newId){
    std::vector<Object*>::iterator objectIterator = getObjectIterator(newId);
    
    if(objectIterator != allObjects.end()){
        return *objectIterator;
    }
    else{
        return nullptr;
    }
}

//rectangle object adder
void ObjectManager::addObject(std::string objName, std::string objType, Plane newPlane, Velocity newVelocity, Acceleration newAcceleration, float newMass){
    if(allObjects.empty()){
        
        allObjects.push_back(new Object(objName, objType, newPlane, newVelocity, newAcceleration, newMass));
    }
    else{
        std::vector<Object*>::iterator objectIterator = getObjectIterator(objName);

        if(objectIterator != allObjects.end()){
            allObjects.push_back(new Object(objName, objType, newPlane,newVelocity, newAcceleration, newMass));
        }
        else{
            std::cerr << "Error: Creation failed. Object named " << objName << " already exists." << std::endl;
        }
    }
}

//rectangle object adder
void ObjectManager::addObject(std::string objName, std::string objType, Cooridinate center, float radius, Velocity newVelocity, Acceleration newAcceleration, float newMass){
    if(allObjects.empty()){
        
        allObjects.push_back(new Object(objName, objType, center, radius, newVelocity, newAcceleration, newMass));
    }
    else{
        std::vector<Object*>::iterator objectIterator = getObjectIterator(objName);

        if(objectIterator == allObjects.end()){
            allObjects.push_back(new Object(objName, objType, center, radius, newVelocity, newAcceleration, newMass));
        }
        else{
            std::cerr << "Error: Creation failed. Object named " << objName << " already exists." << std::endl;
        }
    }
}

void ObjectManager::removeObject(std::string objName){
    if(allObjects.empty()){
        std::cerr << "No objects to remove" << std::endl;
    }
    else{

        std::vector<Object*>::iterator objectIterator = getObjectIterator(objName);

        if(objectIterator != allObjects.end()){
            delete *objectIterator;
            allObjects.erase(objectIterator);
        }
        else{
            std::cerr << "Error: Deletion failed. Object named " << objName << " does not exist." << std::endl;
        }
    }
}

void ObjectManager::removeObject(int newId){
    if(allObjects.empty()){
        std::cerr << "No objects to remove" << std::endl;
    }
    else{

        std::vector<Object*>::iterator objectIterator = getObjectIterator(newId);

        if(objectIterator != allObjects.end()){
            delete *objectIterator;
            allObjects.erase(objectIterator);
        }
        else{
            std::cerr << "Error: Deletion failed. Object with id " << newId << " does not exist." << std::endl;
        }
    }
}

void ObjectManager::printObjectInfo(){
    for(Object * objectIterator : allObjects){
        std::cout << "Object Name: " << objectIterator->getName() << std::endl;
        std::cout <<  "\tObject Type: " << objectIterator->getType() << "  Velocity: {" << objectIterator->getVelocity().x << ", " << objectIterator->getVelocity().y << "}  Accelleration: {" << objectIterator->getAcceleration().x << ", " << objectIterator->getAcceleration().x << "}  Mass: " << objectIterator->getMass();

        if(objectIterator->getType() == "Rectangle"){
            //couting corners
            std::cout << "\n\tBottom Left Corner: {" << objectIterator->objectRectangle->getLeftX() << ", " << objectIterator->objectRectangle->getBottomY();
            std::cout << "}  Top Right Corner: {" << objectIterator->objectRectangle->getRightX() << ", " << objectIterator->objectRectangle->getTopY() << "}";
            
            //couting lenght and height
            std::cout << "  Length: " << objectIterator->objectRectangle->getLength() << "  Height: " << objectIterator->objectRectangle->getHeight() << std::endl;
        }
        else if(objectIterator->getType() == "Circle"){
            std::cout << "\n\tCenter: {" << objectIterator->objectCircle->getCenter().x << ", " << objectIterator->objectCircle->getCenter().y << "}";
            std::cout << " Radius: " << objectIterator->objectCircle->getRadius() << std::endl;
        }
        //adds extra line of space between each object
        std::cout << std::endl;
    }
}

void ObjectManager::updateObjects(float deltaTime){
    for(Object * objectIterator: allObjects){
        objectIterator->updateObject(deltaTime);
    }
}