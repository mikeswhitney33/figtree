#pragma once

#include <vector>


namespace figtree
{


class Matrix
{
public:

    Matrix(double * data, int n_rows, int n_cols);

    std::vector<double> get_mins() const;
    std::vector<double> get_maxs() const;

private:

    double * m_data;
    int m_n_rows;
    int m_n_cols;


};


double get_max_range(const Matrix& X, const Matrix& Y);


}
