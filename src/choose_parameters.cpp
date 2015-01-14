#include "choose_parameters.hpp"

#include <algorithm>
#include <cmath>
#include <limits>

#include "nchoosek.hpp"


namespace figtree
{


namespace
{
    int PUpperLimit = 100;
}


Parameters choose_parameters_uniform(int d, double h, double epsilon, int k_limit, double max_range)
{
    double R = max_range * std::sqrt(double(d));
    double h2 = h * h;
    double complexity_min = std::numeric_limits<double>::max();
    Parameters params = {1,
                         PUpperLimit,
                         std::min(R, h * std::sqrt(std::log(1 / epsilon))),
                         epsilon + 1};

    for (int i = 0; i < k_limit; ++i)
    {
        double rx = max_range * std::pow(double(i) + 1, -1.0 / double(d));
        double rx2 = rx * rx;
        double n = std::min(double(i + 1),
                std::pow(params.r / rx, double(d)));
        double error = epsilon + 1;
        double temp = 1;
        int p = 0;
        while ((error > epsilon) and (p <= PUpperLimit))
        {
            ++p;
            double b = std::min((rx + std::sqrt(rx2 + 2 * p * h2)) / 2, rx + params.r);
            double c = rx - b;
            temp = 1;
            for (int j = 1; j <= p; ++j)
            {
                temp *= 2.0 * rx * b / h2 / j;
            }
            error = temp * std::exp(-(c * c) / h2);
        }
        double complexity = (i + 1) + std::log(double(i) + 1) +
                (1 + n) * nchoosek<double>(p - 1 + d, d);
        if (complexity < complexity_min)
        {
            complexity_min = complexity;
            params.k_max = i + 1;
            params.p_max = p;
            params.error_bound = error;
        }
    }

    // TODO should this be an exception?
    if (params.error_bound > epsilon)
    {
        params.k_max = k_limit;
    }

    return params;
}


}
