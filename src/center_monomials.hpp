#pragma once

#include <vector>


namespace figtree
{


std::vector<double> compute_center_monomials(int d, int p_max, double h,
        const std::vector<double>& dx);


}
