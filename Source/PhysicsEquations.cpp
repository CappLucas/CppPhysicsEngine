#include "PhysicsEquations.h"

//factor in acceleration like the kinematic equation.
float findDisplacement(float deltaTime, float objectVelocity, float objectAcceleration){
    //         velocity*time + (.5 * acceleration * square(time))
    return (objectVelocity*deltaTime) + (0.5f*objectAcceleration*(std::pow(deltaTime, 2.0f)));
};
//assumes accelleration was already added to objectsVelocity
float findDisplacement(float deltaTime, float objectVelocity){
    return objectVelocity*deltaTime;
}
//returns a new velocity based on time, acceleration, and velocity
float findVelocity(float deltaTime, float objectVelocity, float objectAcceleration){
    return objectVelocity + (objectAcceleration*deltaTime);
}