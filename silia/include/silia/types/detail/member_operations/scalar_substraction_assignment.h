#ifndef SILIA__TYPES__DETAIL__MEMBER_OPERATIONS__SCALAR_SUBSTRACTION_ASSIGNMENT_H
#define SILIA__TYPES__DETAIL__MEMBER_OPERATIONS__SCALAR_SUBSTRACTION_ASSIGNMENT_H

#include <cstddef>

namespace silia
{

namespace detail
{
template <size_t N, size_t M, typename MatrixLike, typename T>
void ScalarSubstractAssignImpl(MatrixLike& matrix, T const& summand)
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            matrix[i][j] -= summand;
        }
    }
}

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__MEMBER_OPERATIONS__SCALAR_SUBSTRACTION_ASSIGNMENT_H
