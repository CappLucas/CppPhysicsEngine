#pragma once

#include "Point.h"
#include "Vector.h"

namespace Geometry_Space{
    class Line{
        private:
            Point center{0.0f, 0.0f};
            Point direction{1.0f, 1.0f};
    };
}