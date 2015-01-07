#include "center_monomials.hpp"

#include "p_max_total.hpp"


namespace figtree
{


std::vector<double> compute_source_center_monomials(int d, int p_max, double h,
        const std::vector<double>& dx)
{
    std::vector<int> heads(d, 0);
    std::vector<double> dxh(dx);
    std::vector<double> output(get_p_max_total(d, p_max), 1.0);

    for (int i = 0; i < d; ++i)
    {
        dxh[i] /= h;
    }

    for (int k = 1, t = 1, tail = 1; k < p_max; ++k, tail = t)
    {
        for (int i = 0; i < d; ++i)
        {
            int head = heads[i];
            heads[i] = t;
            for (int j = head; j < tail; ++j, ++t)
            {
                output[t] = dxh[i] * output[j];
            }
        }
    }

    return output;
}


}
