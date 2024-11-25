#include "Types.h"

//there are errors
namespace TypeSpace{
    namespace PositionSpace{
        
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
    }
    namespace VectorSpace{
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
    }
}




