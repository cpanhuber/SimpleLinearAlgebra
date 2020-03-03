#ifndef SILIA__OPERATIONS__NORM_H
#define SILIA__OPERATIONS__NORM_H

#include <silia/operations/detail/squared_norm_detail.h>
#include <silia/types/types.h>

#include <cmath>

namespace silia
{

template <size_t N, typename T, typename Raw, typename MatrixType>
double SquaredNorm(detail::MatrixType<N, 1, Raw, MatrixType, T> const& vector_like)
{
    return detail::SquaredNormImpl<N, detail::MatrixType<N, 1, Raw, MatrixType, T>, double>(vector_like);
}

template <size_t N, typename T, typename Raw, typename MatrixType>
double Norm(detail::MatrixType<N, 1, Raw, MatrixType, T> const& vector_like)
{
    return std::sqrt(SquaredNorm(vector_like));
}

template <size_t N, typename T, typename Raw, typename MatrixType>
float SquaredNormF(detail::MatrixType<N, 1, Raw, MatrixType, T> const& vector_like)
{
    return detail::SquaredNormImpl<N, detail::MatrixType<N, 1, Raw, MatrixType, T>, float>(vector_like);
}

template <size_t N, typename T, typename Raw, typename MatrixType>
float NormF(detail::MatrixType<N, 1, Raw, MatrixType, T> const& vector_like)
{
    return std::sqrt(SquaredNormF(vector_like));
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__NORM_H
