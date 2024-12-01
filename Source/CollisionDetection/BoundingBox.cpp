#include "BoundingBox.h"
#include "Object.h"

void BoundingBoxSpace::BoundingBox::mergeBox(BoundingBox mergingBox){
    //expands the box if any value is greater than the current.
    border.setLeftX(std::min(border.getLeftX(), mergingBox.border.getLeftX()));
    border.setBottomY(std::min(border.getBottomY(), mergingBox.border.getBottomY()));
    border.setRightX(std::max(border.getRightX(), mergingBox.border.getRightX()));
    border.setTopY(std::max(border.getTopY(), mergingBox.border.getTopY()));
}

BoundingBoxSpace::BoundingBox BoundingBoxSpace::findBoundingBox(ObjectSpace::ObjectVector &objects){
    BoundingBoxSpace::BoundingBox returnBox;

    for(ObjectSpace::Object* object : objects){
        returnBox.mergeBox(object->getBoundingBox());
    }
    return returnBox;
}
