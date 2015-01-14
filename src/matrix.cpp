#include "matrix.hpp"

#include <assert.h>
#include <limits>


namespace figtree
{


Matrix::Matrix(double * data, int n_rows, int n_cols)
    : m_data(data)
    , m_n_rows(n_rows)
    , m_n_cols(n_cols)
{}


std::vector<double> Matrix::get_mins() const
{
    std::vector<double> mins(m_n_cols, std::numeric_limits<double>::max());
    // TODO handle no rows
    for (int i = 0; i < m_n_rows; ++i)
    {
        for (int j = 0; j < m_n_cols; ++j)
        {
            mins[j] = std::min(mins[j], m_data[i * m_n_cols + j]);
        }
    }
    return mins;
}


// TODO merge this with get_mins somehow. Templates?
std::vector<double> Matrix::get_maxs() const
{
    std::vector<double> maxs(m_n_cols, std::numeric_limits<double>::min());
    // TODO handle no rows
    for (int i = 0; i < m_n_rows; ++i)
    {
        for (int j = 0; j < m_n_cols; ++j)
        {
            maxs[j] = std::max(maxs[j], m_data[i * m_n_cols + j]);
        }
    }
    return maxs;
}


double get_max_range(const Matrix& X, const Matrix& Y)
{
    std::vector<double> minX = X.get_mins();
    std::vector<double> minY = Y.get_mins();
    std::vector<double> maxX = X.get_maxs();
    std::vector<double> maxY = Y.get_maxs();
    assert(minX.size() == minY.size());
    double max_range = 0;
    for (int i = 0; i < minX.size(); ++i)
    {
        max_range = std::max(
                std::max(maxX[i], maxY[i]) - std::min(minX[i], minY[i]),
                max_range);
    }
    return max_range;
}


}
