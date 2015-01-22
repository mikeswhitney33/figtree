#pragma once

#include "matrix.hpp"


namespace figtree
{


class Cluster
{
public:

    Cluster(const Matrix& x, int k_max);

private:

    const Matrix& m_x;
    int m_k_max;

};


}
