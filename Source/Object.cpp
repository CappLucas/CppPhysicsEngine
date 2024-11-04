#include "Object.h"

Object::Object(std::string objName)
{
    name = objName;
}

Object::~Object()
{
    std::cout << "Destroying..." << std::endl;
}