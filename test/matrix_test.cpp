#include <gtest/gtest.h>
#include "matrix.hpp"

#include "fixtures.hpp"


namespace figtree
{


class MatrixTest : public SampleTest
{};


TEST_F(MatrixTest, Min)
{
    std::vector<double> mins = X.get_mins();
    EXPECT_EQ(7, mins.size());
    EXPECT_EQ(0.0534, mins.at(0));
    EXPECT_EQ(0.0395, mins.at(1));
    EXPECT_EQ(0.0009, mins.at(2));
    EXPECT_EQ(0.0263, mins.at(3));
    EXPECT_EQ(0.1059, mins.at(4));
    EXPECT_EQ(0.0589, mins.at(5));
    EXPECT_EQ(0.1133, mins.at(6));
}


}
