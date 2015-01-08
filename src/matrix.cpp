#include "matrix.hpp"

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


}
