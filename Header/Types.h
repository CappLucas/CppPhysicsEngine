#ifndef TYPES_H
#define TYPES_H

#pragma once

#include <utility>
#include <vector>
#include <limits>

namespace TypesSpace{

    namespace PositionSpace{

        struct CoordStruct{
            CoordStruct(){}
            CoordStruct(float newX, float newY) : x(newX), y(newY){}

            float x;
            float y;

            CoordStruct operator + (CoordStruct &c);
            CoordStruct operator - (CoordStruct &c);
            CoordStruct operator * (CoordStruct &c);
            CoordStruct operator / (CoordStruct &c);
        };

        struct CornerStruct{
            CornerStruct(){}
            CornerStruct(CoordStruct newBottomLeft, CoordStruct newTopRight) : bottomLeft(newBottomLeft), topRight(newTopRight){}

            CoordStruct bottomLeft;
            CoordStruct topRight;
        };
    };
    
    //holds everything for vectors even functions
    namespace VectorSpace{
        struct VectorStruct{
            VectorStruct(){}
            VectorStruct(float newX, float newY) : x(newX), y(newY){}

            float x;
            float y;

            VectorStruct operator + (VectorStruct &v);
            VectorStruct operator - (VectorStruct &v);
            VectorStruct operator * (VectorStruct &v);
            VectorStruct operator / (VectorStruct &v);

            void normalize();
        };

        VectorStruct normalize(VectorStruct v);
    };

    namespace ConstantSpace{
        extern const float INFINITY_FLOAT; 
    };

    namespace EnumSpace{
        enum class OBJECTTYPE{
            RECTANGLE,
            CIRCLE,
            TRIANGLE
        };
    };

    using Cooridinate = PositionSpace::CoordStruct;
    using Corner = PositionSpace::CornerStruct;
    using Plane = PositionSpace::CornerStruct;

    using Velocity = PositionSpace::CoordStruct;
    using Acceleration = PositionSpace::CoordStruct;

    using Vector = VectorSpace::VectorStruct;

    class Object;
    
    using ObjectVector = std::vector<Object*>;
    using CollisionObjectVector = std::vector<ObjectVector>;
};
#endif