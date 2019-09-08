#ifndef SILIA__TYPES__DETAIL__TYPES_FWD_H
#define SILIA__TYPES__DETAIL__TYPES_FWD_H

#include <cstddef>

namespace silia
{

namespace detail
{

template <size_t N, typename T = double>
class VectorImpl;

template <size_t N, size_t M, typename T = double>
class MatrixImpl;

template <size_t N, size_t M, typename T, typename V = double>
class MatrixType;

}  // namespace detail

template <size_t N, size_t M, typename T = double>
using Matrix = detail::MatrixType<N, M, detail::MatrixImpl<N, M, T>, T>;

template <size_t N, typename T = double>
using Vector = detail::MatrixType<N, 1, detail::VectorImpl<N, T>, T>;

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__TYPES_FWD_H
