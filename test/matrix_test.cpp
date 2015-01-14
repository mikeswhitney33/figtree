#include <gtest/gtest.h>
#include "matrix.hpp"

#include "fixtures.hpp"


namespace figtree
{


class MatrixTest : public SampleTest
{};


TEST_F(MatrixTest, GetMins)
{
    std::vector<double> mins = X.get_mins();
    EXPECT_EQ(7, mins.size());
    EXPECT_DOUBLE_EQ(0.0534, mins.at(0));
    EXPECT_DOUBLE_EQ(0.0395, mins.at(1));
    EXPECT_DOUBLE_EQ(0.0009, mins.at(2));
    EXPECT_DOUBLE_EQ(0.0263, mins.at(3));
    EXPECT_DOUBLE_EQ(0.1059, mins.at(4));
    EXPECT_DOUBLE_EQ(0.0589, mins.at(5));
    EXPECT_DOUBLE_EQ(0.1133, mins.at(6));
}


TEST_F(MatrixTest, GetMaxs)
{
    std::vector<double> maxs = X.get_maxs();
    EXPECT_EQ(7, maxs.size());
    EXPECT_DOUBLE_EQ(0.9692, maxs.at(0));
    EXPECT_DOUBLE_EQ(0.823, maxs.at(1));
    EXPECT_DOUBLE_EQ(0.7911, maxs.at(2));
    EXPECT_DOUBLE_EQ(0.9994, maxs.at(3));
    EXPECT_DOUBLE_EQ(0.9963, maxs.at(4));
    EXPECT_DOUBLE_EQ(0.9164, maxs.at(5));
    EXPECT_DOUBLE_EQ(0.9868, maxs.at(6));
}


TEST_F(MatrixTest, GetMaxRange)
{
    double actual = get_max_range(X, Y);
    EXPECT_DOUBLE_EQ(0.9853, actual);
}


}
