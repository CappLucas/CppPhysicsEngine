#ifndef TYPES_H
#define TYPES_H

#pragma once

#include <utility>
#include <vector>
#include <limits>
#include <cmath>

namespace{

    struct PointStruct{
        PointStruct(){}
        PointStruct(float newX, float newY) : x(newX), y(newY){}

        float x;
        float y;

        PointStruct operator + (PointStruct v);
        PointStruct operator - (PointStruct v);
        PointStruct operator * (PointStruct v);
        PointStruct operator / (PointStruct v);

        //move methods
        void move(PointStruct displacement);
        void moveTo(PointStruct position);
        PointStruct showMove(PointStruct displacement);

        //getter methods
        float distanceTo(PointStruct &point);
    };

    //represented as two points, the start and the end, like a ray in a videogame
    struct Ray{
        Ray(){}
        Ray(PointStruct newStart, PointStruct newEnd) : start(newStart), end(newEnd){}

        PointStruct start;
        PointStruct end;

        Ray operator + (Ray &v);
        Ray operator - (Ray &v);
        Ray operator * (Ray &v);
        Ray operator / (Ray &v);

        void move(PointStruct displacement);
        void moveStart(PointStruct displacement);
        void moveEnd(PointStruct displacement);

        //gets magnitude
        float magnitude();

        //changes the magnitude by changing end point
        void normalize();
        void normalizeByStart();
    };

    struct CornerStruct{
        CornerStruct(){}
        CornerStruct(PointStruct newBottomLeft, PointStruct newTopRight) : bottomLeft(newBottomLeft), topRight(newTopRight){}

        PointStruct bottomLeft;
        PointStruct topRight;

        float diagnal();
        
        void move(PointStruct displacement);
        void moveTo(PointStruct position);

        void shiftX(float xDisplacement);
        void shiftY(float yDisplacement);

        
    };
}
    
namespace types{
    using Cooridinate = PointStruct;
    using Plane = CornerStruct;

    using Velocity = PointStruct;
    using Acceleration = PointStruct;
}

namespace constant_space{
    extern const float INFINITY_FLOAT;
}

namespace enum_space{
    enum class OBJECTTYPE{
        RECTANGLE,
        CIRCLE,
        TRIANGLE
    };
}

#endif