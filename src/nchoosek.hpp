#pragma once


namespace figtree
{


template <typename T>
T nchoosek(int n, int k)
{
    int n_k = n - k;
    if (k < n_k)
    {
        k = n_k;
        n_k = n - k;
    }

    T output = 1;
    for (int i = 1; i <= n_k; ++i)
    {
        output *= ++k;
        output /= i;
    }

    return output;
}


}
