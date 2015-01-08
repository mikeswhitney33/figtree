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

inline int source_truncation_number(double dx2, int p_max,
        const std::vector<double>& ranges)
{
    return int(std::lower_bound(ranges.begin(), ranges.end(), dx2) - ranges.begin() + 1);
}


}
