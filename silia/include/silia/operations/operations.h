#ifndef SILIA__OPERATIONS__OPERATIONS_H
#define SILIA__OPERATIONS__OPERATIONS_H

#include <silia/operations/detail/operations_detail.h>
#include <silia/types/types.h>

#include <array>

namespace silia
{

template <size_t I, size_t J, size_t K, typename T, typename MatrixTypeLeft, typename MatrixTypeRight>
Matrix<I, K, detail::MatrixImpl<I, K, T>, T> operator*(Matrix<I, J, MatrixTypeLeft, T> const& left,
                                                       Matrix<J, K, MatrixTypeRight, T> const& right)
{
    return detail::MultiplyImpl<I,
                                J,
                                K,
                                Matrix<I, J, MatrixTypeLeft, T>,
                                Matrix<J, K, MatrixTypeRight, T>,
                                Matrix<I, K, detail::MatrixImpl<I, K, T>, T>,
                                T>(left, right);
}

template <size_t I, size_t J, size_t K, typename T, typename MatrixTypeLeft>
Matrix<I, K, detail::MatrixImpl<I, K, T>, T> operator*(Matrix<I, J, MatrixTypeLeft, T> const& left,
                                                       detail::TransposedMatrixImpl<J, K, T> const& right)
{
    return detail::MultiplyImpl<I,
                                J,
                                K,
                                Matrix<I, J, MatrixTypeLeft, T>,
                                detail::TransposedMatrixImpl<J, K, T>,
                                Matrix<I, K, detail::MatrixImpl<I, K, T>, T>,
                                T>(left, right);
}

template <size_t I, size_t J, size_t K, typename T, typename MatrixTypeRight>
Matrix<I, K, detail::MatrixImpl<I, K, T>, T> operator*(detail::TransposedMatrixImpl<I, J, T> const& left,
                                                       Matrix<J, K, MatrixTypeRight, T> const& right)
{
    return detail::MultiplyImpl<I,
                                J,
                                K,
                                detail::TransposedMatrixImpl<I, J, T>,
                                Matrix<J, K, MatrixTypeRight, T>,
                                Matrix<I, K, detail::MatrixImpl<I, K, T>, T>,
                                T>(left, right);
}

template <size_t I, size_t J, typename T, typename MatrixTypeLeft>
Matrix<I, 1, detail::VectorImpl<I, T>, T> operator*(Matrix<I, J, MatrixTypeLeft, T> const& left,
                                                    Matrix<J, 1, detail::VectorImpl<J, T>, T> const& right)
{
    auto result = MakeVector<I, T>();
    for (size_t i = 0; i < I; ++i)
    {
        result[i] = T{};
        for (size_t j = 0; j < J; ++j)
        {
            result[i] += left[i][j] * right[j];
        }
    }

    return result;
}

template <size_t N, typename T>
T operator*(const Matrix<N, 1, detail::VectorImpl<N, T>, T>& left,
            const Matrix<N, 1, detail::VectorImpl<N, T>, T>& right)
{
    T result{};
    for (size_t i = 0; i < N; ++i)
    {
        result += left[i] * right[i];
    }

    return result;
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__OPERATIONS_H
