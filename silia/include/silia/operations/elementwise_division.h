#ifndef SILIA__OPERATIONS__ELEMENTWISE_DIVISION_H
#define SILIA__OPERATIONS__ELEMENTWISE_DIVISION_H

#include <silia/types/types.h>

#include <array>

namespace silia
{

template <size_t I, size_t J, typename T, typename MatrixTypeLeft, typename MatrixTypeRight>
detail::MatrixType<I, J, MatrixTypeLeft, T> operator/(detail::MatrixType<I, J, MatrixTypeLeft, T> left,
                                                      detail::MatrixType<I, J, MatrixTypeRight, T> const& right)
{
    left /= right;
    return left;
}

template <size_t I, size_t J, typename T, typename MatrixTypeRight>
detail::MatrixType<I, J, detail::MatrixImpl<I, J, T>, T> operator/(
    detail::TransposedMatrixImpl<I, J, T> const& left,
    detail::MatrixType<I, J, MatrixTypeRight, T> const& right)
{
    detail::MatrixType<I, J, detail::MatrixImpl<I, J, T>, T> result = left;
    result /= right;
    return result;
}

template <size_t I, size_t J, typename T, typename MatrixTypeLeft>
detail::MatrixType<I, J, MatrixTypeLeft, T> operator/(detail::MatrixType<I, J, MatrixTypeLeft, T> left,
                                                      detail::TransposedMatrixImpl<I, J, T> const& right)
{
    left /= right;
    return left;
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__ELEMENTWISE_DIVISION_H
