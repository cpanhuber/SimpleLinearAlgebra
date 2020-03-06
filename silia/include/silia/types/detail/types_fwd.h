#ifndef SILIA__TYPES__DETAIL__TYPES_FWD_H
#define SILIA__TYPES__DETAIL__TYPES_FWD_H

#include <silia/types/detail/raw_matrix.h>

#include <cstddef>

namespace silia
{

namespace detail
{

template <size_t N, typename T>
class VectorImpl;

template <size_t N, size_t M, typename T>
class MatrixImpl;

template <size_t N, size_t M, typename Raw, typename T>
class TransposedViewImpl;

template <size_t N, typename T, typename Raw>
class RowViewImpl;

template <size_t N, typename T, typename Raw>
class ColumnViewImpl;

template <size_t N, typename T, typename Raw>
class DiagonalViewImpl;

template <size_t N, size_t M, typename R, typename T, typename V>
class MatrixType;

}  // namespace detail

template <size_t N, size_t M, typename T>
using Matrix = detail::MatrixType<N, M, detail::RawMatrix<N, M, T>, detail::MatrixImpl<N, M, T>, T>;

template <size_t N, size_t M, typename Raw, typename T>
using TransposedView = detail::MatrixType<N, M, Raw, detail::TransposedViewImpl<N, M, Raw, T>, T>;

template <size_t N, typename T, typename Raw>
using RowView = detail::MatrixType<1, N, Raw, detail::RowViewImpl<N, T, Raw>, T>;

template <size_t N, typename T, typename Raw>
using ColumnView = detail::MatrixType<N, 1, Raw, detail::ColumnViewImpl<N, T, Raw>, T>;

template <size_t N, typename T, typename Raw>
using DiagonalView = detail::MatrixType<N, 1, Raw, detail::DiagonalViewImpl<N, T, Raw>, T>;

template <size_t N, typename T>
using Vector = detail::MatrixType<N, 1, detail::RawMatrix<N, 1, T>, detail::VectorImpl<N, T>, T>;

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__TYPES_FWD_H
