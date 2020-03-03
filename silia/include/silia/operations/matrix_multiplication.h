#ifndef SILIA__OPERATIONS__MATRIX_MULTIPLICATION_H
#define SILIA__OPERATIONS__MATRIX_MULTIPLICATION_H

#include <silia/operations/detail/matrix_multiplication_detail.h>
#include <silia/types/types.h>

#include <array>

namespace silia
{

template <size_t I,
          size_t J,
          size_t K,
          typename T,
          typename RawLeft,
          typename MatrixTypeLeft,
          typename RawRight,
          typename MatrixTypeRight>
Matrix<I, K, T> MMult(detail::MatrixType<I, J, RawLeft, MatrixTypeLeft, T> const& left,
                      detail::MatrixType<J, K, RawRight, MatrixTypeRight, T> const& right)
{
    return detail::MatrixMultiplyImpl<I,
                                      J,
                                      K,
                                      detail::MatrixType<I, J, RawLeft, MatrixTypeLeft, T>,
                                      detail::MatrixType<J, K, RawRight, MatrixTypeRight, T>,
                                      Matrix<I, K, T>,
                                      T>(left, right);
}

template <size_t I, size_t J, typename T, typename RawLeft, typename MatrixTypeLeft>
Vector<I, T> MMult(detail::MatrixType<I, J, RawLeft, MatrixTypeLeft, T> const& left, Vector<J, T> const& right)
{
    return detail::MatrixMultiplyImpl<I,
                                      J,
                                      1,
                                      detail::MatrixType<I, J, RawLeft, MatrixTypeLeft, T>,
                                      Vector<J, T>,
                                      Vector<I, T>,
                                      T>(left, right);
}

template <size_t N, typename T>
T MMult(const Vector<N, T>& left, const Vector<N, T>& right)
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
