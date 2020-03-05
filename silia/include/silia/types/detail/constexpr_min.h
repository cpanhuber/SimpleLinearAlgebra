#ifndef SILIA__TYPES__DETAIL__CONSTEXPR_MIN_H
#define SILIA__TYPES__DETAIL__CONSTEXPR_MIN_H

namespace silia
{
namespace detail
{
template <typename T>
constexpr T const& constexpr_min(T const& left, T const& right)
{
    return left < right ? left : right;
}
}  // namespace detail
}  // namespace silia

#endif  //  SILIA__TYPES__DETAIL__CONSTEXPR_MIN_H
