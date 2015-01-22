#include "cluster.hpp"


namespace figtree
{


Cluster::Cluster(const Matrix& x, int k_max)
    : m_x(x)
    , m_k_max(k_max)
    , m_k(k_max)
    , m_rx()
{}


const std::vector<int>& Cluster::get_indices()
{
    return m_indices;
}


}
