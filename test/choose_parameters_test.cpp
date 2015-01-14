#include <gtest/gtest.h>
#include "choose_parameters.hpp"

#include "fixtures.hpp"


namespace figtree
{


class ChooseParametersTest : public SampleTest
{};


TEST_F(ChooseParametersTest, Uniform)
{
    double max_range = get_max_range(X, Y);
    Parameters params = choose_parameters_uniform(d, h, epsilon, N, max_range);
    EXPECT_EQ(17, params.k_max);
    EXPECT_EQ(11, params.p_max);
    EXPECT_DOUBLE_EQ(1.7167728210314779, params.r);
}


}
