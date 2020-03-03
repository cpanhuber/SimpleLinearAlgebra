#ifndef SILIA__OPERATIONS__DETAIL__LU_FACTORIZATION_DETAIL_H
#define SILIA__OPERATIONS__DETAIL__LU_FACTORIZATION_DETAIL_H

#include <silia/types/types.h>

#include <cstdint>

namespace silia
{

namespace detail
{

template <size_t N, size_t M, typename T, typename U>
void LUFactorization(T const& M, U& L, U& U)
{
}

}  // namespace detail

}  // namespace silia

#endif  // SILIA__OPERATIONS__DETAIL__LU_FACTORIZATION_DETAIL_H
