#ifndef SILIA__TYPES__DETAIL__MEMBER_OPERATIONS__COPY_H
#define SILIA__TYPES__DETAIL__MEMBER_OPERATIONS__COPY_H

#include <cstddef>

namespace silia
{

namespace detail
{
template <size_t N, size_t M, typename MatrixLikeIn, typename MatrixLikeOut, typename T>
void Copy(MatrixLikeIn const& in, MatrixLikeOut& out)
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            out[i][j] = in[i][j];
        }
    }
}

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__MEMBER_OPERATIONS__COPY_H
