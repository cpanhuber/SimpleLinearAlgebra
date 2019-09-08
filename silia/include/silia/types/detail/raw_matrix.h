#ifndef SILIA__TYPES__DETAIL__RAW_MATRIX_H
#define SILIA__TYPES__DETAIL__RAW_MATRIX_H

#include <array>

namespace silia
{

namespace detail
{
template <size_t N, size_t M, typename T = double>
using RawMatrix = std::array<std::array<T, M>, N>;
}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__RAW_MATRIX_H
