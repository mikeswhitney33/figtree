#include <gtest/gtest.h>
#include "nchoosek.hpp"


namespace figtree
{


TEST(NChooseK, Int)
{
    EXPECT_EQ(1, nchoosek<int>(1, 1));
    EXPECT_EQ(2, nchoosek<int>(2, 1));
    EXPECT_EQ(120, nchoosek<int>(10, 3));
}


TEST(NChooseK, Double)
{
    EXPECT_DOUBLE_EQ(1, nchoosek<double>(1, 1));
    EXPECT_DOUBLE_EQ(2, nchoosek<double>(2, 1));
    EXPECT_DOUBLE_EQ(126, nchoosek<double>(9, 4));
}


}
