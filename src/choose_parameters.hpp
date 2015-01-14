#pragma once


namespace figtree
{


struct Parameters
{
    int k_max;
    int p_max;
    double r;
    double error_bound;
};


Parameters choose_parameters_uniform(int d, double h, double epsilon, int k_limit, double max_range);


}
