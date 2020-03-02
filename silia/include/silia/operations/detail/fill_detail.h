#ifndef SILIA__OPERATIONS__DETAIL__FILL_DETAIL_H
#define SILIA__OPERATIONS__DETAIL__FILL_DETAIL_H

#include <silia/types/types.h>

#include <cstdint>

namespace silia
{

namespace detail
{

template <size_t N, size_t M, typename T, typename U>
void FillImpl(T& matrix_like, U const& value)
{
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            matrix_like[i][j] = value;
        }
    }
}

template <size_t N, typename T, typename U>
void FillIdentityImpl(T& matrix_like)
{
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < N; ++j)
        {
            matrix_like[i][j] = (i == j ? static_cast<U>(1) : static_cast<U>(0));
        }
    }
}

}  // namespace detail

}  // namespace silia

#endif  // SILIA__OPERATIONS__DETAIL__FILL_DETAIL_H
