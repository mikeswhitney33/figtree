#include <gtest/gtest.h>
#include "center_monomials.hpp"


namespace figtree
{


class ComputeSourceCenterMonomials : public ::testing::Test
{
public:

    ComputeSourceCenterMonomials()
        : h(0.8)
        , dx{0.2, 0.6}
    {}

    double h;
    std::vector<double> dx;

};


TEST_F(ComputeSourceCenterMonomials, One)
{
    std::vector<double> output = compute_source_center_monomials(1, 1, h, dx);
    EXPECT_EQ(1, output.size());
    EXPECT_DOUBLE_EQ(1.0, output.at(0));
}


TEST_F(ComputeSourceCenterMonomials, Six)
{
    std::vector<double> output = compute_source_center_monomials(2, 3, h, dx);
    EXPECT_EQ(6, output.size());
    EXPECT_DOUBLE_EQ(1.0, output.at(0));
    EXPECT_DOUBLE_EQ(0.25, output.at(1));
    EXPECT_DOUBLE_EQ(0.75, output.at(2));
    EXPECT_DOUBLE_EQ(0.0625, output.at(3));
    EXPECT_DOUBLE_EQ(0.1875, output.at(4));
    EXPECT_DOUBLE_EQ(0.5625, output.at(5));
}


}
