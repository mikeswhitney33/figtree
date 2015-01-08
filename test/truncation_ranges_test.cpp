#include <gtest/gtest.h>
#include "truncation_ranges.hpp"


namespace figtree
{


TEST(SourceTruncationRanges, General)
{
    std::vector<double> output = source_truncation_ranges(10, 2, 0.8, 0.01, 6);
    EXPECT_EQ(6, output.size());
    EXPECT_DOUBLE_EQ(6.103515625e-5, output.at(0));
    EXPECT_DOUBLE_EQ(0.007053375244140625, output.at(1));
    EXPECT_DOUBLE_EQ(0.0308990478515625, output.at(2));
    EXPECT_DOUBLE_EQ(0.0684967041015625, output.at(3));
    EXPECT_DOUBLE_EQ(0.11285400390625, output.at(4));
    EXPECT_DOUBLE_EQ(2.0, output.at(5));
}


}
