#ifndef SILIA__OPERATIONS__DETAIL__NORM_DETAIL_H
#define SILIA__OPERATIONS__DETAIL__NORM_DETAIL_H

#include <silia/types/types.h>

#include <cstdint>

namespace silia
{

namespace detail
{

template <size_t N, typename T, typename W>
W SquaredNormImpl(T const& vector_like)
{
    W value{};
    for (size_t i = 0; i < N; ++i)
    {
        value += vector_like[i][0] * vector_like[i][0];
    }
    return value;
}

}  // namespace detail

}  // namespace silia

#endif  // SILIA__OPERATIONS__DETAIL__NORM_DETAIL_H
