#ifndef SILIA__OPERATIONS__FILL_H
#define SILIA__OPERATIONS__FILL_H

#include <silia/operations/detail/fill_detail.h>
#include <silia/types/types.h>

namespace silia
{

template <size_t N, size_t M, typename T, typename MatrixType>
void Fill(detail::MatrixType<N, M, MatrixType, T>& matrix_like, T const& value)
{
    detail::FillImpl<N, M, detail::MatrixType<N, M, MatrixType, T>, T>(matrix_like, value);
}

template <size_t N, size_t M, typename T>
void Fill(detail::TransposedMatrixImpl<N, M, T>& matrix_like, T const& value)
{
    detail::FillImpl<N, M, detail::TransposedMatrixImpl<N, M, T>, T>(matrix_like, value);
}

template <size_t N, typename T, typename MatrixType>
void FillIdentity(detail::MatrixType<N, N, MatrixType, T>& matrix_like)
{
    detail::FillIdentityImpl<N, detail::MatrixType<N, N, MatrixType, T>, T>(matrix_like);
}

template <size_t N, typename T>
void FillIdentity(detail::TransposedMatrixImpl<N, N, T>& matrix_like)
{
    detail::FillIdentityImpl<N, detail::TransposedMatrixImpl<N, N, T>, T>(matrix_like);
}

template <size_t N, size_t M, typename T, typename MatrixType>
void Fill(detail::MatrixType<N, M, MatrixType, T>&& matrix_like, T const& value)
{
    detail::FillImpl<N, M, detail::MatrixType<N, M, MatrixType, T>, T>(matrix_like, value);
}

template <size_t N, size_t M, typename T>
void Fill(detail::TransposedMatrixImpl<N, M, T>&& matrix_like, T const& value)
{
    detail::FillImpl<N, M, detail::TransposedMatrixImpl<N, M, T>, T>(matrix_like, value);
}

template <size_t N, typename T, typename MatrixType>
void FillIdentity(detail::MatrixType<N, N, MatrixType, T>&& matrix_like)
{
    detail::FillIdentityImpl<N, detail::MatrixType<N, N, MatrixType, T>, T>(matrix_like);
}

template <size_t N, typename T>
void FillIdentity(detail::TransposedMatrixImpl<N, N, T>&& matrix_like)
{
    detail::FillIdentityImpl<N, detail::TransposedMatrixImpl<N, N, T>, T>(matrix_like);
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__FILL_H
