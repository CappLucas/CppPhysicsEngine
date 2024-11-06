#include "Object.h"
float Object::defaultMass = 1.0;
float Object::defaultGravity = 0;

void Object::updateObject(float deltaTime){
    //update position using velocity, accelleration, and more.
    float gravityHolder = (isAffectedByGravity ? Object::defaultGravity : 1);

    //updating y acceleration
    objectAccelleration.y = objectAccelleration.y + gravity;
    if(type == "Rectangle"){
        Cooridinate displacement;
        
        //finding displacment with d = v*t + a*t
        displacement.x = displacement.x + (objectVelocity.x * deltaTime) + (objectAccelleration.x * deltaTime);
        displacement.y = displacement.y + (objectVelocity.y * deltaTime) + (objectAccelleration.y * deltaTime);

        objectRectangle->move({displacement.x,displacement.y});
    }
    else if(type == "Circle"){

    }
}