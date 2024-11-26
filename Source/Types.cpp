#include "Types.h"
using namespace TypeSpace;
using namespace PositionSpace;
using namespace VectorSpace;
//there are errors


CoordStruct CoordStruct::operator + (CoordStruct &c){
    return {x + c.x, y + c.y};
}
CoordStruct CoordStruct::operator - (CoordStruct &c){
    return {x - c.x, y - c.y};
}
CoordStruct CoordStruct::operator * (CoordStruct &c){
    return {x * c.x, y * c.y};
}
CoordStruct CoordStruct::operator / (CoordStruct &c){
    return {x / c.x, y / c.y};
}
float CoordStruct::distanceTo(CoordStruct &c){
    return std::sqrt(std::pow(c.x - x, 2) + std::pow(c.y - y, 2));
};
float CornerStruct::diagnal(){
    return std::sqrt(std::pow(topRight.x - bottomLeft.x, 2) + std::pow(topRight.y - bottomLeft.y, 2));
}
float PositionSpace::distance(CoordStruct &c1, CoordStruct &c2){
    return std::sqrt(std::pow(c2.x - c1.x, 2) + std::pow(c2.y - c1.y, 2));
}
float PositionSpace::diagnal(CornerStruct &corners){
    return std::sqrt(std::pow(corners.topRight.x - corners.bottomLeft.x, 2) + std::pow(corners.topRight.y - corners.bottomLeft.y, 2));
}

VectorStruct VectorStruct::operator + (VectorStruct &v){
    return {x + v.x, y + v.y};
}
VectorStruct VectorStruct::operator - (VectorStruct &v){
    return {x - v.x, y - v.y};
}
VectorStruct VectorStruct::operator * (VectorStruct &v){
    return {x * v.x, y * v.y};
}
VectorStruct VectorStruct::operator / (VectorStruct &v){
    return {x / v.x, y / v.y};
}
void VectorStruct::magnitude(){
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
};

void VectorStruct::normalize(){

}

VectorStruct VectorSpace::normalize(VectorStruct v){
    //returns a copied vector but normalized
    v.normalize();
    return v;
}




