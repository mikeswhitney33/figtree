#include <iostream>

#include "ANN/ANN.h"
#include "figtree.h"
#include "figtree_internal.h"
#include <math.h>

// define MAX and MIN if not yet defined
#ifndef MAX
#define MAX(a,b) ((a) > (b) ? (a) : (b) )
#endif

#ifndef MIN
#define MIN(a,b) ((a) < (b) ? (a) : (b) )
#endif


void computeConstantSeries(int, int, int, double *);
void computeSourceCenterMonomials(int, double, double *, int, double *);
void computeTargetCenterMonomials(int, double, double *, int, double *);
double figtreeOneSidedErrorBound( double a, double b_max, double c, double h2, int p )
{
  double b = MIN( b_max, .5*(a + sqrt(a*a + 2*p*h2)) ); // this is the value of at which error(a,b,p) reaches maximum for a given 'a' and 'p'
  double d_ab = a-b;
  return c * pow(a*b/h2,p) * exp( -d_ab*d_ab/h2 );
}
void figtreeFindRadiusBounds( double a_lo, double a_hi, double b_max, 
                              double c, double h2, int p, double epsilon,
                              int max_it, double * lo_out, double * hi_out );
void figtreeSourceTruncationRanges( double r, double rx, double h, double epsilon, int pMax, double * max_source_dists2 );
void figtreeTargetTruncationRanges( double r, double rx, double h, double epsilon, int pMax, double * max_source_dists2, double * min_target_dists2 );
inline
int figtreeSourceTruncationNumber( double dx2, int pMax, double * max_source_dists2 )
{
  return (int)(std::lower_bound( max_source_dists2, max_source_dists2 + pMax - 1, dx2) - max_source_dists2) + 1;  
}
inline
int figtreeTargetTruncationNumber( double dy2, int pMax, double * max_target_dists2, double * min_target_dists2 )
{
  if( dy2 <= max_target_dists2[pMax-2] )
    return (int)(std::lower_bound( max_target_dists2, max_target_dists2 + pMax - 1, dy2) - max_target_dists2) + 1;
  else if( dy2 >= min_target_dists2[pMax-2] )
    return (int)(std::lower_bound( min_target_dists2, min_target_dists2 + pMax - 1, dy2, std::greater<double>() ) - min_target_dists2) + 1;
  else 
    return pMax;
}

typedef struct _FigtreeData
{
//  // general params - not used yet, but will be used when saving data-structured for multiple calls
//  int d;
//  int N;
//  int M;
//  int W;
//  double epsilon;
//  double * x;
//  double h;
//  double * q; 
//  double * y;
  
  // params for IFGT
  int pMax;
  int pMaxTotal;
  int K;
  int * clusterIndex;
  double * clusterCenters;
  double * clusterRadii;
  int * numPoints;
  double r;
  double rx;

  // params for IFGT + Tree
  ANNpointArray annClusters;
  ANNkd_tree * annClustersKdTree;
  
  // params for Direct + Tree
  ANNpointArray annSources;
  ANNkd_tree * annSourcesKdTree;

} FigtreeData;

FigtreeData figtreeCreateData()
{
  FigtreeData data;

  data.pMax = 0;
  data.pMaxTotal = 0;
  data.K = 0;
  data.clusterIndex = NULL;
  data.clusterCenters = NULL;
  data.clusterRadii = NULL;
  data.numPoints = NULL;
  data.r = 0;
  data.rx = 0;

  data.annClusters = NULL;
  data.annClustersKdTree = NULL;

  data.annSources = NULL;
  data.annSourcesKdTree = NULL;

  return data;
}



int main()
{
    double h = 0.8;

    std::cout << "### Constant series test" << std::endl;

    double x0[1];
    computeConstantSeries(1, 1, 1, x0);
    std::cout << "d = 1, pMaxTotal = 1, pMax = 1: " << x0[0] << std::endl;

    double x1[2];
    computeConstantSeries(1, 2, 2, x1);
    std::cout << "d = 1, pMaxTotal = 2, pMax = 2: " << x1[0] << ", " << x1[1] << std::endl;

    double x2[6];
    computeConstantSeries(2, 6, 3, x2);
    std::cout << "d = 1, pMaxTotal = 6, pMax = 4: ";
    for (int i = 0; i < 6; ++i)
    {
        std::cout << x2[i];
        if (i != 5)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    std::cout << std::endl << "### Compute source center monomials" << std::endl;

    double x3[1];
    double dx3[1] = {0.2};
    computeSourceCenterMonomials(1, h, dx3, 1, x3);
    std::cout << "d = 1, pMax = 1: " << x3[0] << std::endl;

    double x4[6];
    double dx4[2] = {0.2, 0.6};
    computeSourceCenterMonomials(2, h, dx4, 3, x4);
    std::cout << "d = 2, pMax = 3: ";
    for (int i = 0; i < 6; ++i)
    {
        std::cout << x4[i];
        if (i != 5)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    std::cout << std::endl << "### Compute target center monomials" << std::endl;

    double x5[1];
    double dx5[1] = {0.2};
    computeSourceCenterMonomials(1, h, dx5, 1, x5);
    std::cout << "d = 1, pMax = 1: " << x5[0] << std::endl;

    double x6[6];
    double dx6[2] = {0.2, 0.6};
    computeTargetCenterMonomials(2, h, dx6, 3, x6);
    std::cout << "d = 2, pMax = 3: ";
    for (int i = 0; i < 6; ++i)
    {
        std::cout << x6[i];
        if (i != 5)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;


    std::cout << std::endl << "### Compute one-sided error bound" << std::endl;
    std::cout << figtreeOneSidedErrorBound(2.0, 3.0, 4.0, 5.0, 6) << std::endl;

    std::cout << std::endl << "### Find radius bounds" << std::endl;
    double lo, hi;
    figtreeFindRadiusBounds(0, 1, 2, 3, 4, 5, 0.01, 100, &lo, &hi);
    std::cout << "lo: " << lo << ", hi: " << hi << std::endl;

    std::cout << std::endl << "### Find source truncation ranges" << std::endl;
    double ranges1[6];
    figtreeSourceTruncationRanges(10, 2, 0.8, 0.01, 6, ranges1);
    for (int i = 0; i < 6; ++i)
    {
        std::cout << ranges1[i];
        if (i != 5)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    std::cout << std::endl << "### Find target truncation ranges" << std::endl;
    double ranges2[6];
    double ranges3[6];
    figtreeTargetTruncationRanges(10, 2, 0.8, 0.01, 6, ranges2, ranges3);
    std::cout << "Mins: ";
    for (int i = 0; i < 6; ++i)
    {
        std::cout << ranges3[i];
        if (i != 5)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    std::cout << "Maxs: ";
    for (int i = 0; i < 6; ++i)
    {
        std::cout << ranges2[i];
        if (i != 5)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    std::cout << "### Source Truncation Number" << std::endl;
    std::cout << figtreeSourceTruncationNumber(2, 6, ranges1) << std::endl;

    std::cout << "### Target Truncation Number" << std::endl;
    std::cout << figtreeTargetTruncationNumber(2, 6, ranges2, ranges3) << std::endl;

    int d = 7;
    int M = 10;
    int N = 20;
    double epsilon = 1e-2;
    double x[] = {0.7165, 0.5113, 0.7764, 0.4893, 0.1859, 0.7006, 0.9827,
        0.8066, 0.7036, 0.4850, 0.1146, 0.6649, 0.3654, 0.1400,
        0.5668, 0.8230, 0.6739, 0.9994, 0.9616, 0.0589, 0.3603,
        0.5485, 0.2618, 0.5973, 0.0493, 0.5711, 0.7009, 0.9623,
        0.7505, 0.7400, 0.4319, 0.6343, 0.8030, 0.0839, 0.9455,
        0.9159, 0.6020, 0.2536, 0.8735, 0.5134, 0.7327, 0.4222,
        0.1959, 0.1059, 0.3923, 0.1003, 0.6930, 0.2069, 0.6094,
        0.1059, 0.0396, 0.2093, 0.9693, 0.1059, 0.3029, 0.3069,
        0.9692, 0.6029, 0.2222, 0.2059, 0.3059, 0.6092, 0.2133,
        0.9614, 0.0721, 0.5534, 0.2920, 0.8580, 0.3358, 0.6802,
        0.2473, 0.3527, 0.1879, 0.4906, 0.4093, 0.4635, 0.6109,
        0.1865, 0.0395, 0.5921, 0.1853, 0.9963, 0.1953, 0.7659,
        0.0534, 0.3567, 0.4983, 0.4344, 0.5625, 0.6166, 0.1133,
        0.8983, 0.7546, 0.7911, 0.8150, 0.6700, 0.2009, 0.2731,
        0.6262, 0.5369, 0.0595, 0.0890, 0.2713, 0.4091, 0.4740,
        0.1332, 0.6926, 0.0009, 0.1532, 0.9632, 0.3521, 0.9692,
        0.9623, 0.3532, 0.7432, 0.0693, 0.2336, 0.6022, 0.2936,
        0.3921, 0.6023, 0.6323, 0.9353, 0.3963, 0.2835, 0.9868,
        0.2362, 0.6682, 0.2026, 0.0263, 0.1632, 0.9164, 0.1153,
        0.9090, 0.5962, 0.3290, 0.4782, 0.5972, 0.1614, 0.8295 };
    double y[] = {0.9561, 0.5955, 0.0287, 0.8121, 0.6101, 0.7015, 0.0922,
        0.4249, 0.3756, 0.1662, 0.8332, 0.8386, 0.4516, 0.9566,
        0.1472, 0.8699, 0.7694, 0.4442, 0.6206, 0.9517, 0.6400,
        0.0712, 0.3143, 0.6084, 0.1750, 0.6210, 0.2460, 0.5874,
        0.5061, 0.4648, 0.5414, 0.9423, 0.3418, 0.4018, 0.3077,
        0.4116, 0.2859, 0.3941, 0.5030, 0.7220, 0.3062, 0.1122,
        0.4433, 0.4668, 0.0147, 0.6641, 0.7241, 0.2816, 0.2618,
        0.7085, 0.7839, 0.9862, 0.4733, 0.9028, 0.4511, 0.8045,
        0.8289, 0.1663, 0.3939, 0.5208, 0.7181, 0.5692, 0.4608,
        0.4453, 0.0877, 0.4435, 0.3663, 0.3025, 0.8518, 0.7595 };
    double q[] = {0.2280, 0.4496, 0.1722, 0.9688, 0.3557, 0.0490, 0.7553, 0.8948, 0.2861, 0.2512, 0.9327, 0.3353, 0.2530, 0.2532, 0.3352, 0.7235, 0.2506, 0.0235, 0.1062, 0.1061, 0.7234, 0.1532};
    int W = 1;

    FigtreeData data = figtreeCreateData();
    double maxRange = 0;
    int kLimit = N;
    int kMax;
    double * mins = new double[d];
    double * maxs = new double[d];

    figtreeCalcMinMax(d, N, x, mins, maxs, 0);
    std::cout << "### Figtree calc min max no update" << std::endl << "Mins: ";
    for (int i = 0; i < 7; ++i)
    {
        std::cout << mins[i] << ", ";
    }
    std::cout << std::endl << "Maxs:";
    for (int i = 0; i < 7; ++i)
    {
        std::cout << maxs[i] << ", ";
    }

    figtreeCalcMinMax(d, M, y, mins, maxs, 1);
    figtreeCalcMaxRange(d, mins, maxs, &maxRange);

    std::cout << std::endl << "Max range: " << maxRange << std::endl;

    std::cout << std::endl << "### Choose parameters uniform" << std::endl;
    figtreeChooseParametersUniform(d, h, epsilon, kLimit, maxRange, &kMax, &data.pMax, &data.r, NULL);
    std::cout << "kMax: " << kMax << std::endl
              << "pMax: " << data.pMax << std::endl
              << "r: " << data.r << std::endl;

    return 0;
}
