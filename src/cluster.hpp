#pragma once

#include "matrix.hpp"


namespace figtree
{


class Cluster
{
public:

    Cluster(const Matrix& x, int k_max);

    inline int get_k() const
    {
        return m_k;
    }
    inline double get_rx() const
    {
        return m_rx;
    }
    const std::vector<int>& get_indices();

private:

    const Matrix& m_x;
    int m_k_max;
    int m_k;
    double m_rx;
    std::vector<int> m_indices;

};


}
