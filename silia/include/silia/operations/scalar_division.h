#ifndef SILIA__OPERATIONS__SCALAR_DIVISION_H
#define SILIA__OPERATIONS__SCALAR_DIVISION_H

#include <silia/types/types.h>

#include <array>

namespace silia
{

template <size_t I, size_t J, typename T, typename Raw, typename MatrixType>
auto operator/(detail::MatrixType<I, J, Raw, MatrixType, T> const& left, T const& right) ->
    typename MatrixType::result_type
{
    using result_type = typename MatrixType::result_type;
    result_type result = left;
    result /= right;
    return result;
}

template <size_t I, size_t J, typename T, typename Raw, typename MatrixType>
auto operator/(T const& left, detail::MatrixType<I, J, Raw, MatrixType, T> const& right) ->
    typename MatrixType::result_type
{
    using result_type = typename MatrixType::result_type;
    result_type result = right;
    result /= left;
    return result;
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__SCALAR_DIVISION_H
