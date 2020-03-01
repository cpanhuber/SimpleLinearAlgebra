#ifndef SILIA__OPERATIONS__DETAIL__CROSS_PRODUCT_DETAIL_H
#define SILIA__OPERATIONS__DETAIL__CROSS_PRODUCT_DETAIL_H

#include <silia/types/types.h>

#include <array>

namespace silia
{

namespace detail
{
template <typename T, typename U, typename V>
V CrossImpl(T const& left, U const& right)
{
    V result{};
    result[0][0] = left[1][0] * right[2][0] - left[2][0] * right[1][0];
    result[1][0] = left[2][0] * right[0][0] - left[0][0] * right[2][0];
    result[2][0] = left[0][0] * right[1][0] - left[1][0] * right[0][0];
    return result;
}

}  // namespace detail

}  // namespace silia

#endif  // SILIA__OPERATIONS__DETAIL__CROSS_PRODUCT_DETAIL_H
