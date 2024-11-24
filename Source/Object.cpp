#include "Object.h"

#include "BoundingBox.h"

int Object::objects = 0;
float Object::defaultMass = 1.0;
float Object::defaultGravity = 0;


void Object::updateObject(float deltaTime){
    //include the equations

    //if gravity is disabled, return 0, else return regular gravity
    float gravityHolder = (isAffectedByGravity ? gravity : 0);

    //updating velocity
     objectVelocity.x = findVelocity(deltaTime, objectVelocity.x, objectAcceleration.x);
     objectVelocity.y = findVelocity(deltaTime, objectVelocity.y, objectAcceleration.y + gravityHolder);

    //finding displacement
    Cooridinate displacement;
    displacement.x = findDisplacement(deltaTime, objectVelocity.x,objectAcceleration.x);
    displacement.y = findDisplacement(deltaTime, objectVelocity.y,objectAcceleration.y + gravityHolder);

    if(type == "Rectangle"){
        objectRectangle->move(displacement);
    }
    else if(type == "Circle"){
        objectCircle->move(displacement);
    }
}

BoundingBox Object::getBoundingBox(){
    BoundingBox box;

    if(type == "Rectangle"){
        box.border = *objectRectangle;
    }
    else if(type == "Circle"){
        //bottomLeft corner cooridinate of circle
        Cooridinate bottomLeft{objectCircle->getLeft().x,objectCircle->getBottom().y};
        Cooridinate topRight{objectCircle->getRight().x,objectCircle->getTop().y};

        Rectangle border({bottomLeft,topRight});

        box.border = border;
    }
    return box;
}