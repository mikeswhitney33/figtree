#include <gtest/gtest.h>
#include "radius_bounds.hpp"


namespace figtree
{


TEST(FindRadiusBounds, General)
{
    RadiusBounds bounds = find_radius_bounds(0, 1, 2, 3, 4, 5, 0.01, 100);
    EXPECT_DOUBLE_EQ(bounds.lo, 0.69588330581188718);
    EXPECT_DOUBLE_EQ(bounds.hi, 0.69588330581188718);
}


}
