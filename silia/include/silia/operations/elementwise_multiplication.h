#ifndef SILIA__OPERATIONS__ELEMENTWISE_MULTIPLICATION_H
#define SILIA__OPERATIONS__ELEMENTWISE_MULTIPLICATION_H

#include <silia/types/types.h>

#include <array>

namespace silia
{

template <size_t I,
          size_t J,
          typename T,
          typename RawLeft,
          typename RawRight,
          typename MatrixTypeLeft,
          typename MatrixTypeRight>
auto operator*(detail::MatrixType<I, J, RawLeft, MatrixTypeLeft, T> const& left,
               detail::MatrixType<I, J, RawRight, MatrixTypeRight, T> const& right) ->
    typename MatrixTypeLeft::result_type
{
    typename MatrixTypeLeft::result_type result{left};
    result *= right;
    return result;
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__ELEMENTWISE_MULTIPLICATION_H
