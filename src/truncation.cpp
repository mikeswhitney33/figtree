#include "truncation.hpp"

#include <cmath>

#include "radius_bounds.hpp"


namespace figtree
{


std::vector<double> source_truncation_ranges(double r, double rx, double h, double epsilon, double p_max)
{
    double h2 = h * h;
    std::vector<double> output(p_max, -1);
    output[p_max - 1] = rx;

    double c = 1;
    for (int i = 0; i < p_max - 1; ++i)
    {
        double a_lo = 0;
        double a_hi = rx;
        c *= 2.0 / (i + 1);
        // TODO parameterize max_it
        RadiusBounds bounds = find_radius_bounds(a_lo, a_hi, r + rx, c, h2, i + 1, epsilon, 10);
        output[i] = bounds.lo * bounds.lo;
    }

    return output;
}


TruncationRanges target_truncation_ranges(double r, double rx, double h, double epsilon,
        double p_max)
{
    double h2 = h * h;
    double ry = r + rx;
    TruncationRanges ranges = {std::vector<double>(p_max, ry * ry + 1),
                               std::vector<double>(p_max, -1)};
    ranges.min[p_max - 1] = 0;
    ranges.max[p_max - 1] = 0;

    double c = 1;
    for (int i = 0; i < p_max - 1; ++i)
    {
        double peak_dist = 0.5 * (rx + std::sqrt(rx * rx + 2 * h2 * (i + 1)));
        double a_lo = 0;
        double a_hi = std::min(ry, peak_dist);
        c *= 2.0 / (i + 1);
        RadiusBounds bounds = find_radius_bounds(a_lo, a_hi, rx, c, h2, i + 1, epsilon, 10);
        ranges.max[i] = bounds.lo * bounds.lo;
        
        if (peak_dist <= ry)
        {
            RadiusBounds bounds2 = find_radius_bounds(ry, peak_dist, rx, c, h2, i + 1, epsilon, 10);
            ranges.min[i] = bounds2.lo * bounds2.lo;
        }

        if (i > 0 and ranges.min[i] > ranges.min[i - 1])
        {
            ranges.min[i] = ranges.min[i - 1];
        }
    }

    if (p_max > 1 and ranges.min[p_max - 1] > ranges.min[p_max - 2])
    {
        ranges.min[p_max - 1] = ranges.min[p_max - 2];
    }

    return ranges;
}


}
