#include <gtest/gtest.h>
#include "cluster.hpp"

#include "fixtures.hpp"


namespace figtree
{


class ClusterTest : public SampleTest
{};


TEST_F(ClusterTest, Constructor)
{
    Cluster cluster(X, 3);
}


TEST_F(ClusterTest, KAndRX)
{
    Cluster cluster(X, 3);
    EXPECT_EQ(3, cluster.get_k());
    EXPECT_EQ(0.990325, cluster.get_rx());
}


TEST_F(ClusterTest, ClusterIndex)
{
    Cluster cluster(X, 3);
    std::vector<int> indices = cluster.get_indices();
    std::vector<int> expected {2, 2, 1, 2, 1, 1, 0, 0, 2, 1, 0, 0, 0, 1, 2, 1, 2, 1, 0, 1};
    EXPECT_EQ(expected, indices);
}


}
