#include "radius_bounds.hpp"

#include <algorithm>

#include "error_bound.hpp"


namespace figtree
{


RadiusBounds find_radius_bounds(double a_lo, double a_hi, double b_max,
        double c, double h2, int p, double epsilon, int max_it)
{
    if (one_sided_error_bound(a_hi, b_max, c, h2, p) <= epsilon)
    {
        return {a_lo, a_hi};
    }
    else if (one_sided_error_bound(a_lo, b_max, c, h2, p) <= epsilon)
    {
        for (int i = 0; i < max_it; ++i)
        {
            double a_mid = 0.5 * (a_lo + a_hi);
            if (one_sided_error_bound(a_mid, b_max, c, h2, p) <= epsilon)
            {
                a_lo = a_mid;
            }
            else
            {
                a_hi = a_mid;
            }
        }
        return {a_lo, a_hi};
    }
    else
    {
        // TODO this is an exceptional case, we should throw an exception
        return {2 * a_lo - a_hi, a_hi};
    }
}


}
