#ifndef OBJECT_H
#define OBJECT_H

#pragma once

#include <string>
#include <iostream>

class Object{
public:
    Object(std::string objName);
    ~Object();

    std::string getName(){return name; }

private:
    std::string name;
};

#endif