#ifndef SILIA__OPERATIONS__DETAIL__MULTIPLICATION_DETAIL_H
#define SILIA__OPERATIONS__DETAIL__MULTIPLICATION_DETAIL_H

#include <silia/types/types.h>

#include <array>

namespace silia
{

namespace detail
{
template <size_t I, size_t J, size_t K, typename T, typename U, typename V, typename W>
V MultiplyImpl(T const& left, U const& right)
{
    V result{};
    for (size_t i = 0; i < I; ++i)
    {
        for (size_t k = 0; k < K; ++k)
        {
            result[i][k] = W{};
            for (size_t j = 0; j < J; ++j)
            {
                result[i][k] += left[i][j] * right[j][k];
            }
        }
    }

    return result;
}

}  // namespace detail

}  // namespace silia

#endif  // SILIA__OPERATIONS__DETAIL__MULTIPLICATION_DETAIL_H
