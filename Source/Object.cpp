#include "Object.h"

float Object::defaultMass = 1.0;
float Object::defaultGravity = 0;

void Object::updateObject(float deltaTime){
    //include the equations
    PhysicsEquations equations;

    //if gravity is disabled, return 0, else return regular gravity
    float gravityHolder = (isAffectedByGravity ? gravity : 0);

    //updating velocity
     objectVelocity.x = equations.findVelocity(deltaTime, objectVelocity.x, objectAcceleration.x);
     objectVelocity.y = equations.findVelocity(deltaTime, objectVelocity.y, objectAcceleration.y + gravityHolder);

    //finding displacement
    Cooridinate displacement;
    displacement.x = equations.findDisplacement(deltaTime, objectVelocity.x);
    displacement.y = equations.findDisplacement(deltaTime, objectVelocity.y);

    if(type == "Rectangle"){
        objectRectangle->move(displacement);
    }
    else if(type == "Circle"){
        objectCircle->move(displacement);
    }
}