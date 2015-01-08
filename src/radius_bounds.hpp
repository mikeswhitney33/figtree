#pragma once


namespace figtree
{


struct RadiusBounds
{
    double lo;
    double hi;
};


RadiusBounds find_radius_bounds(double a_lo, double a_hi, double b_max,
        double c, double h2, int p, double epsilon, int max_it);


}
