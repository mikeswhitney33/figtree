#include <gtest/gtest.h>
#include "error_bound.hpp"


namespace figtree
{


TEST(OneSidedErrorBound, General)
{
    double result = one_sided_error_bound(2, 3, 4, 5, 6);
    EXPECT_DOUBLE_EQ(9.7788677159952151, result);
}


}
