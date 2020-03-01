#ifndef SILIA__OPERATIONS__DETAIL__UNIT_DETAIL_H
#define SILIA__OPERATIONS__DETAIL__UNIT_DETAIL_H

#include <silia/operations/detail/squared_norm_detail.h>
#include <silia/types/types.h>

#include <cstdint>

namespace silia
{

namespace detail
{

template <size_t N, typename T, typename W, typename R>
R UnitImpl(T const& vector_like)
{
    W norm = std::sqrt(SquaredNormImpl<N, T, W>(vector_like));
    R result{};
    for (size_t i = 0; i < N; ++i)
    {
        result[i][0] = static_cast<W>(vector_like[i][0]) / norm;
    }
    return result;
}

}  // namespace detail

}  // namespace silia

#endif  // SILIA__OPERATIONS__DETAIL__UNIT_DETAIL_H
