#ifndef SILIA__OPERATIONS__SCALAR_DIVISION_H
#define SILIA__OPERATIONS__SCALAR_DIVISION_H

#include <silia/types/types.h>

#include <array>

namespace silia
{

template <size_t I, size_t J, typename T, typename MatrixType>
detail::MatrixType<I, J, MatrixType, T> operator/(detail::MatrixType<I, J, MatrixType, T> left, T const& right)
{
    left /= right;
    return left;
}

template <size_t I, size_t J, typename T>
Matrix<I, J, T> operator/(detail::TransposedMatrixImpl<I, J, T> const& left, T const& right)
{
    Matrix<I, J, T> m = left;
    m /= right;
    return m;
}

template <size_t I, size_t J, typename T, typename MatrixType>
detail::MatrixType<I, J, MatrixType, T> operator/(T const& left, detail::MatrixType<I, J, MatrixType, T> right)
{
    right /= left;
    return right;
}

template <size_t I, size_t J, typename T>
Matrix<I, J, T> operator/(T const& left, detail::TransposedMatrixImpl<I, J, T> const& right)
{
    Matrix<I, J, T> m = right;
    m /= left;
    return m;
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__SCALAR_DIVISION_H
