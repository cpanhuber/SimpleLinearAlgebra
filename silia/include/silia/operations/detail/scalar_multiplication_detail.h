#ifndef SILIA__OPERATIONS__DETAIL__SCALAR_MULTIPLICATION_DETAIL_H
#define SILIA__OPERATIONS__DETAIL__SCALAR_MULTIPLICATION_DETAIL_H

#include <silia/types/types.h>

#include <array>

namespace silia
{

namespace detail
{
template <size_t I, size_t J, typename T, typename U, typename V>
V ScalarMultiplyImpl(U const& left, T const& right)
{
    V result{};
    for (size_t i = 0; i < I; ++i)
    {
        for (size_t j = 0; j < J; ++j)
        {
            result[i][j] = left[i][j] * right;
        }
    }

    return result;
}

}  // namespace detail

}  // namespace silia

#endif  // SILIA__OPERATIONS__DETAIL__SCALAR_MULTIPLICATION_DETAIL_H
