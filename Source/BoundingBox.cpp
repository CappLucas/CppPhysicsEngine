#include "BoundingBox.h"
#include "Object.h"

void BoundingBox::mergeBox(BoundingBox mergingBox){
    //expands the box if any value is greater than the current.
    border.setLeftX(std::min(border.getLeftX(), mergingBox.border.getLeftX()));
    border.setBottomY(std::min(border.getBottomY(), mergingBox.border.getBottomY()));
    border.setRightX(std::max(border.getRightX(), mergingBox.border.getRightX()));
    border.setTopY(std::max(border.getTopY(), mergingBox.border.getTopY()));
}

BoundingBox BoundingBox::findBoundingBox(ObjectVector::iterator begginning, ObjectVector::iterator end){
    BoundingBox returnBox;

    while(begginning != end){
        Object* obj = *begginning;
        returnBox.mergeBox(obj->getBoundingBox());
        begginning += 1;
    }
    return returnBox;
}