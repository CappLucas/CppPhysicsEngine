#include "PhysicsEquations.h"

//assumes you already 
float PhysicsEquations::findDisplacement(float deltaTime, float objectVelocity, float objectAcceleration){
    //         velocity*time + (.5 * acceleration * square(time))
    return (objectVelocity*deltaTime) + (0.5f*objectAcceleration*(std::pow(deltaTime, 2.0f)));
};
float PhysicsEquations::findDisplacement(float deltaTime, float objectVelocity){
    return objectVelocity*deltaTime;
}
float PhysicsEquations::findVelocity(float deltaTime, float objectVelocity, float objectAcceleration){
    return objectVelocity + (objectAcceleration*deltaTime);
}