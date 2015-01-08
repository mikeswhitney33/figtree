#include <iostream>

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

    return 0;
}
