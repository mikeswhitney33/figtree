#pragma once

#include <cmath>


namespace figtree
{


inline double one_sided_error_bound(double a, double b_max, double c, double h2, int p)
{
    double b = std::min(b_max, 0.5 * (a + std::sqrt(a * a + 2 * p * h2)));
    double d_ab = a - b;
    return c * std::pow(a * b / h2, p) * std::exp(-d_ab * d_ab / h2);
}


}
