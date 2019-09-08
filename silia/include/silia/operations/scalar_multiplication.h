#ifndef SILIA__OPERATIONS__SCALAR_MULTIPLICATION_H
#define SILIA__OPERATIONS__SCALAR_MULTIPLICATION_H

#include <silia/operations/detail/scalar_multiplication_detail.h>
#include <silia/types/types.h>

#include <array>

namespace silia
{

template <size_t I, size_t J, typename T, typename MatrixType>
detail::MatrixType<I, J, MatrixType, T> operator*(detail::MatrixType<I, J, MatrixType, T> const& left, T const& right)
{
    return detail::
        ScalarMultiplyImpl<I, J, T, detail::MatrixType<I, J, MatrixType, T>, detail::MatrixType<I, J, MatrixType, T>>(
            left, right);
}

template <size_t I, size_t J, typename T>
Matrix<I, J, T> operator*(detail::TransposedMatrixImpl<I, J, T> const& left, T const& right)
{
    return detail::ScalarMultiplyImpl<I, J, T, detail::TransposedMatrixImpl<I, J, T>, Matrix<I, J, T>>(left, right);
}

template <size_t I, size_t J, typename T, typename MatrixType>
detail::MatrixType<I, J, MatrixType, T> operator*(T const& left, detail::MatrixType<I, J, MatrixType, T> const& right)
{
    return detail::
        ScalarMultiplyImpl<I, J, T, detail::MatrixType<I, J, MatrixType, T>, detail::MatrixType<I, J, MatrixType, T>>(
            right, left);
}

template <size_t I, size_t J, typename T>
Matrix<I, J, T> operator*(T const& left, detail::TransposedMatrixImpl<I, J, T> const& right)
{
    return detail::ScalarMultiplyImpl<I, J, T, detail::TransposedMatrixImpl<I, J, T>, Matrix<I, J, T>>(right, left);
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__SCALAR_MULTIPLICATION_H
