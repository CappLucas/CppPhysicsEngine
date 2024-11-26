#ifndef TYPES_H
#define TYPES_H

#pragma once

#include <utility>
#include <vector>
#include <limits>
#include <cmath>

namespace TypeSpace{

    namespace PositionSpace{

        typedef struct CoordStruct{
            CoordStruct(){}
            CoordStruct(float newX, float newY) : x(newX), y(newY){}

            float x;
            float y;

            CoordStruct operator + (CoordStruct &c);
            CoordStruct operator - (CoordStruct &c);
            CoordStruct operator * (CoordStruct &c);
            CoordStruct operator / (CoordStruct &c);

            float distanceTo(CoordStruct &c);
        };

        typedef struct CornerStruct{
            CornerStruct(){}
            CornerStruct(CoordStruct newBottomLeft, CoordStruct newTopRight) : bottomLeft(newBottomLeft), topRight(newTopRight){}

            CoordStruct bottomLeft;
            CoordStruct topRight;

            float diagnal();
        };

        float distance(CoordStruct &point1, CoordStruct &point2);
        float diagnal(CornerStruct &corner);
    }
    
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
            
            void magnitude();
            void normalize();
        };
        float magnitude(VectorStruct v);
        VectorStruct normalize(VectorStruct v);
    }

    namespace ConstantSpace{
        extern const float INFINITY_FLOAT; 
    }

    namespace EnumSpace{
        enum class OBJECTTYPE{
            RECTANGLE,
            CIRCLE,
            TRIANGLE
        };
    }

    using Cooridinate = PositionSpace::CoordStruct;
    using Corner = PositionSpace::CornerStruct;
    using Plane = PositionSpace::CornerStruct;

    using Velocity = PositionSpace::CoordStruct;
    using Acceleration = PositionSpace::CoordStruct;

    using Vector = VectorSpace::VectorStruct;
};
#endif