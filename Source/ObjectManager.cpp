#include "ObjectManager.h"

ObjectManager::ObjectManager()
{

}
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

void ObjectManager::addObject(std::string objName){
    if(allObjects.empty()){
        allObjects.push_back(new Object(objName));
    }
    else{
        std::vector<Object*>::iterator objectIterator = getObjectIteratorByName(objName);

        if(objectIterator != allObjects.end()){
            allObjects.push_back(new Object(objName));
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