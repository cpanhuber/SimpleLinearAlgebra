#ifndef SILIA__TYPES__DETAIL__MEMBER_OPERATIONS__MATRIX_ADDITION_ASSIGNMENT_H
#define SILIA__TYPES__DETAIL__MEMBER_OPERATIONS__MATRIX_ADDITION_ASSIGNMENT_H

#include <cstddef>

namespace silia
{

namespace detail
{
template <size_t N, size_t M, typename MatrixLikeLeft, typename MatrixLikeRight>
void MatrixAddAssignImpl(MatrixLikeLeft& left, MatrixLikeRight const& right)
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            left[i][j] += right[i][j];
        }
    }
}

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__MEMBER_OPERATIONS__MATRIX_ADDITION_ASSIGNMENT_H
