#ifndef SILIA__OPERATIONS__FILL_H
#define SILIA__OPERATIONS__FILL_H

#include <silia/operations/detail/fill_detail.h>
#include <silia/types/types.h>

namespace silia
{

template <size_t N, size_t M, typename T, typename Raw, typename MatrixType>
void Fill(detail::MatrixType<N, M, Raw, MatrixType, T>& matrix_like, T const& value)
{
    detail::FillImpl<N, M, detail::MatrixType<N, M, Raw, MatrixType, T>, T>(matrix_like, value);
}

template <size_t N, typename T, typename Raw, typename MatrixType>
void FillIdentity(detail::MatrixType<N, N, Raw, MatrixType, T>& matrix_like)
{
    detail::FillIdentityImpl<N, detail::MatrixType<N, N, Raw, MatrixType, T>, T>(matrix_like);
}

template <size_t N, size_t M, typename T, typename Raw, typename MatrixType>
void Fill(detail::MatrixType<N, M, Raw, MatrixType, T>&& matrix_like, T const& value)
{
    detail::FillImpl<N, M, detail::MatrixType<N, M, Raw, MatrixType, T>, T>(matrix_like, value);
}

template <size_t N, typename T, typename Raw, typename MatrixType>
void FillIdentity(detail::MatrixType<N, N, Raw, MatrixType, T>&& matrix_like)
{
    detail::FillIdentityImpl<N, detail::MatrixType<N, N, Raw, MatrixType, T>, T>(matrix_like);
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__FILL_H
