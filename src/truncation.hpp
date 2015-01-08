#pragma once

#include <algorithm>
#include <functional>
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

inline int target_truncation_number(double dy2, int p_max,
        const TruncationRanges& ranges)
{
    if (dy2 <= ranges.max[p_max - 2])
    {
        return int(std::lower_bound(ranges.max.begin(), ranges.max.end(), dy2) -
                ranges.max.begin() + 1);
    }
    else if (dy2 >= ranges.min[p_max - 2])
    {
        return int(std::lower_bound(ranges.min.begin(), ranges.min.end(), dy2, std::greater<double>()) -
                ranges.min.begin() + 1);
    }
    else
    {
        return p_max;
    }
}


}
