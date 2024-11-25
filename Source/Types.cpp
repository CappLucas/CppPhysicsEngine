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
float PositionSpace::distance(CoordStruct &c1, CoordStruct &c2){
    return std::sqrt(std::pow(c2.x - c1.x, 2) + std::pow(c2.y - c1.y, 2));
}
//TODO
float PositionSpace::diagnal(CornerStruct &corners){
    return std::sqrt(std::pow(c2.x - c1.x, 2) + std::pow(c2.y - c1.y, 2));
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

VectorStruct VectorSpace::normalize(VectorStruct v){
    //returns a copied vector but normalized
    v.normalize();
    return v;
}




