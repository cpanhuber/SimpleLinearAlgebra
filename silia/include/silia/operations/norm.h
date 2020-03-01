#ifndef SILIA__OPERATIONS__NORM_H
#define SILIA__OPERATIONS__NORM_H

#include <silia/operations/detail/squared_norm_detail.h>
#include <silia/types/types.h>

#include <cmath>

namespace silia
{

template <size_t N, typename T, typename MatrixType>
double SquaredNorm(detail::MatrixType<N, 1, MatrixType, T> const& vector_like)
{
    return detail::SquaredNormImpl<N, detail::MatrixType<N, 1, MatrixType, T>, double>(vector_like);
}

template <size_t N, typename T>
double SquaredNorm(detail::TransposedMatrixImpl<N, 1, T> const& vector_like)
{
    return detail::SquaredNormImpl<N, detail::TransposedMatrixImpl<N, 1, T>, double>(vector_like);
}

template <size_t N, typename T, typename MatrixType>
double Norm(detail::MatrixType<N, 1, MatrixType, T> const& vector_like)
{
    return std::sqrt(SquaredNorm(vector_like));
}

template <size_t N, typename T>
double Norm(detail::TransposedMatrixImpl<N, 1, T> const& vector_like)
{
    return std::sqrt(SquaredNorm(vector_like));
}

template <size_t N, typename T, typename MatrixType>
float SquaredNormF(detail::MatrixType<N, 1, MatrixType, T> const& vector_like)
{
    return detail::SquaredNormImpl<N, detail::MatrixType<N, 1, MatrixType, T>, float>(vector_like);
}

template <size_t N, typename T>
float SquaredNormF(detail::TransposedMatrixImpl<N, 1, T> const& vector_like)
{
    return detail::SquaredNormImpl<N, detail::TransposedMatrixImpl<N, 1, T>, float>(vector_like);
}

template <size_t N, typename T, typename MatrixType>
float NormF(detail::MatrixType<N, 1, MatrixType, T> const& vector_like)
{
    return std::sqrt(SquaredNormF(vector_like));
}

template <size_t N, typename T>
float NormF(detail::TransposedMatrixImpl<N, 1, T> const& vector_like)
{
    return std::sqrt(SquaredNormF(vector_like));
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__NORM_H
