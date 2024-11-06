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


std::vector<Object*>::iterator ObjectManager::getObjectIteratorByName(std::string objName){
    auto conditions = [&objName](Object* &objIt){
        return objIt->getName() == objName;
    };

    std::vector<Object*>::iterator objectIterator = std::find_if(allObjects.begin(), allObjects.end(),conditions);
    
    return objectIterator;
}

Object *ObjectManager::getObjectByName(std::string objName){
    std::vector<Object*>::iterator objectIterator = getObjectIteratorByName(objName);
    
    if(objectIterator != allObjects.end()){
        return *objectIterator;
    }
    else{
        return nullptr;
    }
}

//rectangle object adder
void ObjectManager::addObject(std::string objName, std::string objType, Plane newPlane, Velocity newVelocity, Accelleration newAccelleration, float newMass){
    if(allObjects.empty()){
        
        allObjects.push_back(new Object(objName, objType, newPlane, newVelocity, newAccelleration, newMass));
    }
    else{
        std::vector<Object*>::iterator objectIterator = getObjectIteratorByName(objName);

        if(objectIterator != allObjects.end()){
            allObjects.push_back(new Object(objName, objType, newPlane,newVelocity, newAccelleration, newMass));
        }
        else{
            std::cerr << "Error: Creation failed. Object named " << objName << " already exists." << std::endl;
        }
    }
}

//rectangle object adder
void ObjectManager::addObject(std::string objName, std::string objType, Cooridinate center, float radius, Velocity newVelocity, Accelleration newAccelleration, float newMass){
    if(allObjects.empty()){
        
        allObjects.push_back(new Object(objName, objType, center, radius, newVelocity, newAccelleration, newMass));
    }
    else{
        std::vector<Object*>::iterator objectIterator = getObjectIteratorByName(objName);

        if(objectIterator != allObjects.end()){
            allObjects.push_back(new Object(objName, objType, center, radius, newVelocity, newAccelleration, newMass));
        }
        else{
            std::cerr << "Error: Creation failed. Object named " << objName << " already exists." << std::endl;
        }
    }
}

void ObjectManager::removeObjectByName(std::string objName){
    if(allObjects.empty()){
        std::cerr << "No objects to remove" << std::endl;
    }
    else{

        std::vector<Object*>::iterator objectIterator = getObjectIteratorByName(objName);

        if(objectIterator != allObjects.end()){
            delete *objectIterator;
            allObjects.erase(objectIterator);
        }
        else{
            std::cerr << "Error: Deletion failed. Object named " << objName << " does not exist." << std::endl;
        }
    }
}
void ObjectManager::printObjectInfo(){
    for(Object * objectIterator : allObjects){
        std::cout << "Object Name: " << objectIterator->getName() << std::endl;
        std::cout <<  "\tObject Type: " << objectIterator->getType() << "  Velocity: " << objectIterator->getVelocity().x << ", " << objectIterator->getVelocity().y << "   Accelleration: " << objectIterator->getAccelleration().x << ", " << objectIterator->getAccelleration().x << std::endl;
    }
}
void ObjectManager::updateObjects(float deltaTime){
    for(Object * objectIterator: allObjects){
        objectIterator->updateObject(deltaTime);
    }
}