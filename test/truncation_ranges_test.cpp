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


TEST(TargetTruncationRanges, General)
{
    TruncationRanges ranges = target_truncation_ranges(10, 2, 0.8, 0.01, 6);
    EXPECT_EQ(6, ranges.min.size());
    EXPECT_DOUBLE_EQ(18.111296566116284, ranges.min.at(0));
    EXPECT_DOUBLE_EQ(18.111296566116284, ranges.min.at(1));
    EXPECT_DOUBLE_EQ(18.111296566116284, ranges.min.at(2));
    EXPECT_DOUBLE_EQ(18.111296566116284, ranges.min.at(3));
    EXPECT_DOUBLE_EQ(18.111296566116284, ranges.min.at(4));
    EXPECT_DOUBLE_EQ(0.0, ranges.min.at(5));

    EXPECT_EQ(6, ranges.max.size());
    EXPECT_DOUBLE_EQ(7.046241849693622e-5, ranges.max.at(0));
    EXPECT_DOUBLE_EQ(0.0067906483005697495, ranges.max.at(1));
    EXPECT_DOUBLE_EQ(0.03089904785156251, ranges.max.at(2));
    EXPECT_DOUBLE_EQ(0.06750684345806203, ranges.max.at(3));
    EXPECT_DOUBLE_EQ(0.11340819511655957, ranges.max.at(4));
    EXPECT_DOUBLE_EQ(0.0, ranges.max.at(5));
}


}
