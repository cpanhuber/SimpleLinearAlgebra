#ifndef SILIA__TYPES__FACTORIES_H
#define SILIA__TYPES__FACTORIES_H

#include <silia/types/detail/matrix_detail.h>

namespace silia
{
template <size_t N, size_t M, typename T>
Matrix<N, M, detail::MatrixImpl<N, M, T>, T> MakeMatrix()
{
    return detail::MatrixImpl<N, M, T>{};
}

template <size_t N, size_t M, typename T>
Matrix<N, M, detail::MatrixImpl<N, M, T>, T> MakeMatrix(T const (&list)[N][M])
{
    return detail::MatrixImpl<N, M, T>{list};
}

template <size_t N, typename T>
Matrix<N, 1, detail::VectorImpl<N, T>, T> MakeVector()
{
    return detail::VectorImpl<N, T>{};
}

template <size_t N, typename T>
Matrix<N, 1, detail::VectorImpl<N, T>, T> MakeVector(T const (&list)[N])
{
    return detail::VectorImpl<N, T>{list};
}

}  // namespace silia

#endif  // SILIA__TYPES__FACTORIES_H
