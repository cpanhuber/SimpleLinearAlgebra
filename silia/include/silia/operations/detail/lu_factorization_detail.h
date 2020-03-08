#ifndef SILIA__OPERATIONS__DETAIL__LU_FACTORIZATION_DETAIL_H
#define SILIA__OPERATIONS__DETAIL__LU_FACTORIZATION_DETAIL_H

#include <silia/types/types.h>

#include <cstdint>

namespace silia
{

namespace detail
{

template <size_t N, size_t M, typename MatrixLike, typename ResultMatrix>
void LUFactorization(MatrixLike const& A, ResultMatrix& L, ResultMatrix& U)
{
}

template <typename MatrixLike>
void RowSwap(MatrixLike& A, size_t first_row_index, size_t second_row_index)
{
    auto first_row = A.GetRowView(first_row_index).Copy();
    A.GetRowView(first_row_index) = A.GetRowView(second_row_index);
    A.GetRowView(second_row_index) = first_row;
}

}  // namespace detail

}  // namespace silia

#endif  // SILIA__OPERATIONS__DETAIL__LU_FACTORIZATION_DETAIL_H
