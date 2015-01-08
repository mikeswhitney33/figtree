#pragma once

#include <vector>


namespace figtree
{


class Matrix
{
public:

    Matrix(double * data, int n_rows, int n_cols);

    std::vector<double> get_mins() const;

private:

    double * m_data;
    int m_n_rows;
    int m_n_cols;


};


}
