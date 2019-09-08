#ifndef SILIA__TYPES__DETAIL__INDEX_SWAP_H
#define SILIA__TYPES__DETAIL__INDEX_SWAP_H

#include <silia/types/detail/raw_matrix.h>

namespace silia
{

namespace detail
{
template <size_t N, size_t M, typename T = double>
class TransposedMatrixImpl;

template <size_t N, size_t M, typename T = double>
class IndexSwap
{
  public:
    using index_type = size_t;

    friend TransposedMatrixImpl<M, N, T>;

    T& operator[](index_type inner_index)
    {
        return matrix_[inner_index][index_];
    }

    T operator[](index_type inner_index) const
    {
        return matrix_[inner_index][index_];
    }

  private:
    IndexSwap(RawMatrix<N, M, T>& matrix, index_type index) : index_{index}, matrix_{matrix} {}

    index_type index_;
    RawMatrix<N, M, T>& matrix_;
};

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__INDEX_SWAP_H
