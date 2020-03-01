#ifndef SILIA__OPERATIONS__MATRIX_MULTIPLICATION_H
#define SILIA__OPERATIONS__MATRIX_MULTIPLICATION_H

#include <silia/operations/detail/multiplication_detail.h>
#include <silia/types/types.h>

#include <array>

namespace silia
{

template <size_t I, size_t J, size_t K, typename T, typename MatrixTypeLeft, typename MatrixTypeRight>
Matrix<I, K, T> operator*(detail::MatrixType<I, J, MatrixTypeLeft, T> const& left,
                          detail::MatrixType<J, K, MatrixTypeRight, T> const& right)
{
    return detail::MatrixMultiplyImpl<I,
                                      J,
                                      K,
                                      detail::MatrixType<I, J, MatrixTypeLeft, T>,
                                      detail::MatrixType<J, K, MatrixTypeRight, T>,
                                      Matrix<I, K, T>,
                                      T>(left, right);
}

template <size_t I, size_t J, size_t K, typename T, typename MatrixTypeLeft>
Matrix<I, K, T> operator*(detail::MatrixType<I, J, MatrixTypeLeft, T> const& left,
                          detail::TransposedMatrixImpl<J, K, T> const& right)
{
    return detail::MatrixMultiplyImpl<I,
                                      J,
                                      K,
                                      detail::MatrixType<I, J, MatrixTypeLeft, T>,
                                      detail::TransposedMatrixImpl<J, K, T>,
                                      Matrix<I, K, T>,
                                      T>(left, right);
}

template <size_t I, size_t J, size_t K, typename T, typename MatrixTypeRight>
Matrix<I, K, T> operator*(detail::TransposedMatrixImpl<I, J, T> const& left,
                          detail::MatrixType<J, K, MatrixTypeRight, T> const& right)
{
    return detail::MatrixMultiplyImpl<I,
                                      J,
                                      K,
                                      detail::TransposedMatrixImpl<I, J, T>,
                                      detail::MatrixType<J, K, MatrixTypeRight, T>,
                                      Matrix<I, K, T>,
                                      T>(left, right);
}

template <size_t I, size_t J, typename T, typename MatrixTypeLeft>
Vector<I, T> operator*(detail::MatrixType<I, J, MatrixTypeLeft, T> const& left, Vector<J, T> const& right)
{
    return detail::
        MatrixMultiplyImpl<I, J, 1, detail::MatrixType<I, J, MatrixTypeLeft, T>, Vector<J, T>, Vector<I, T>, T>(left,
                                                                                                                right);
}

template <size_t I, size_t J, typename T>
Vector<I, T> operator*(detail::TransposedMatrixImpl<I, J, T> const& left, Vector<J, T> const& right)
{
    return detail::MatrixMultiplyImpl<I, J, 1, detail::TransposedMatrixImpl<I, J, T>, Vector<J, T>, Vector<I, T>, T>(
        left, right);
}

template <size_t N, typename T>
T operator*(const Vector<N, T>& left, const Vector<N, T>& right)
{
    T result{};
    for (size_t i = 0; i < N; ++i)
    {
        result += left[i] * right[i];
    }

    return result;
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__MULTIPLICATION_H
