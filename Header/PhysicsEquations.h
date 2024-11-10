#ifndef PHYSICSEQUATIONS_H
#define PHYSICSEQUATIONS_H

#pragma once

#include "Types.h"

#include <math.h>

//holds the basic equations needed for physic calculations as functions.
//The function name is the variable it is finding and the parameters are what it is finding it with.

//returns force from mass and acceleration
//float force(float objectMass, Acceleration objectAcceleration);    

//-------------- kinematics --------------

        //v=u+at         
float findVelocity(float deltaTime, float objectVelocity,float objectAcceleration);

        //x = ut + (1/2)a(sqaure(t))      displacement = initial velocity * time, plus .5 * acceleration * (time squared)
float findDisplacement(float deltaTime, float objectVelocity, float objectAcceleration);    

        // d = v*t
float findDisplacement(float deltaTime, float objectVelocity);                               


#endif