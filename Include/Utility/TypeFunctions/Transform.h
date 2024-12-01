#pragma once

#include "Region.h"
#include "CenterRegion.h"

namespace Geometry_Space{
    CenterRegion regionToCenterRegion(Region r);
    Region CenterRegionToRegion(CenterRegion r);
}