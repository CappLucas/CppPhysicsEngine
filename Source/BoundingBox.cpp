#include "BoundingBox.h"

void BoundingBox::mergeBox(BoundingBox mergingBox){
    //expands the box if any value is greater than the current.
    border.setLeftX(std::min(border.getLeftX(), mergingBox.border.getLeftX()));
    border.setBottomY(std::min(border.getBottomY(), mergingBox.border.getBottomY()));
    border.setRightX(std::max(border.getRightX(), mergingBox.border.getRightX()));
    border.setTopY(std::max(border.getTopY(), mergingBox.border.getTopY()));
}

template <class Iterator>
BoundingBox findBoundingBox(Iterator begginning, Iterator end){
    BoundingBox returnBox;

    while(begginning != end){
        returnBox.mergeBox(*begginning);

        begginning += 1;
    }
    return returnBox;
}