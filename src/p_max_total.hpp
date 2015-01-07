#pragma once

#include "nchoosek.hpp"


namespace figtree
{


inline int get_p_max_total(int d, int p_max)
{
    return nchoosek<int>(p_max - 1 + d, d);
}


}
