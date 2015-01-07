#include <gtest/gtest.h>
#include "constant_series.hpp"


namespace figtree
{


TEST(ConstantSeries, OneDOneP)
{
    std::vector<double> output = compute_constant_series(1, 1);
    EXPECT_EQ(1, output.size());
    EXPECT_DOUBLE_EQ(1.0, output.at(0));
}


TEST(ConstantSeries, OneDTwoP)
{
    std::vector<double> output = compute_constant_series(1, 2);
    EXPECT_EQ(2, output.size());
    EXPECT_DOUBLE_EQ(1.0, output.at(0));
    EXPECT_DOUBLE_EQ(2.0, output.at(1));
}


TEST(ConstantSeries, TwoDFourP)
{
    std::vector<double> output = compute_constant_series(2, 3);
    EXPECT_EQ(6, output.size());
    EXPECT_DOUBLE_EQ(1.0, output.at(0));
    EXPECT_DOUBLE_EQ(2.0, output.at(1));
    EXPECT_DOUBLE_EQ(2.0, output.at(2));
    EXPECT_DOUBLE_EQ(2.0, output.at(3));
    EXPECT_DOUBLE_EQ(4.0, output.at(4));
    EXPECT_DOUBLE_EQ(2.0, output.at(5));
}


}
