#pragma once

#include <vector>


namespace figtree
{


struct TruncationRanges
{
    std::vector<double> min;
    std::vector<double> max;
};


std::vector<double> source_truncation_ranges(double r, double rx, double h, double epsilon, 
        double p_max);
TruncationRanges target_truncation_ranges(double r, double rx, double h, double epsilon,
        double p_max);


}
