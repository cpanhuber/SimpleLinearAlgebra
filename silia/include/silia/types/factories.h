#ifndef SILIA__TYPES__FACTORIES_H
#define SILIA__TYPES__FACTORIES_H

#include <silia/types/detail/types_detail.h>

namespace silia
{
template <size_t N, size_t M, typename T>
detail::MatrixImpl<N, M, T> MakeMatrix()
{
    return detail::MatrixImpl<N, M, T>{};
}

template <size_t N, size_t M, typename T>
detail::MatrixImpl<N, M, T> MakeMatrix(T const (&list)[N][M])
{
    return detail::MatrixImpl<N, M, T>{list};
}

template <size_t N, typename T>
detail::VectorImpl<N, T> MakeVector()
{
    return detail::VectorImpl<N, T>{};
}

template <size_t N, typename T>
detail::VectorImpl<N, T> MakeVector(T const (&list)[N])
{
    return detail::VectorImpl<N, T>{list};
}

}  // namespace silia

#endif  // SILIA__TYPES__FACTORIES_H
