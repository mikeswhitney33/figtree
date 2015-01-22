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


}
