#include "constant_series.hpp"

#include <limits>

#include "p_max_total.hpp"


namespace figtree
{


std::vector<double> compute_constant_series(int d, int p_max)
{
    std::vector<int> heads(d + 1, 0);
    heads[d] = std::numeric_limits<int>::max();

    int p_max_total = get_p_max_total(d, p_max);
    std::vector<int> cinds(p_max_total, 0);
    std::vector<double> output(p_max_total, 1.0);

    for (int k = 1, t = 1, tail = 1; k < p_max; ++k, tail = t)
    {
        for (int i = 0; i < d; ++i)
        {
            int head = heads[i];
            heads[i] = t;
            for (int j = head; j < tail; ++j, ++t)
            {
                cinds[t] = (j < heads[i + 1]) ? cinds[j] + 1 : 1;
                output[t] = 2.0 * output[j];
                output[t] /= double(cinds[t]);
            }
        }
    }

    return output;
}


}
