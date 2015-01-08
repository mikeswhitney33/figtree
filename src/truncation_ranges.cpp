#include "truncation_ranges.hpp"

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


}
