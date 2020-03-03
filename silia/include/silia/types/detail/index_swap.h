#ifndef SILIA__TYPES__DETAIL__INDEX_SWAP_H
#define SILIA__TYPES__DETAIL__INDEX_SWAP_H

namespace silia
{

namespace detail
{
template <size_t N, size_t M, typename Raw, typename T>
class TransposedViewImpl;

template <size_t N, size_t M, typename Raw, typename T>
class IndexSwap
{
  public:
    using index_type = size_t;

    friend TransposedViewImpl<M, N, Raw, T>;

    T& operator[](index_type inner_index)
    {
        return matrix_[inner_index][index_];
    }

    T operator[](index_type inner_index) const
    {
        return matrix_[inner_index][index_];
    }

  private:
    IndexSwap(Raw matrix, index_type index) : index_{index}, matrix_{matrix} {}

    index_type index_;
    Raw matrix_;
};

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__INDEX_SWAP_H
