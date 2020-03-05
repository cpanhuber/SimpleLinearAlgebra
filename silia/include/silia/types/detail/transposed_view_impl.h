#ifndef SILIA__TYPES__DETAIL__TRANSPOSED_VIEW_IMPL_H
#define SILIA__TYPES__DETAIL__TRANSPOSED_VIEW_IMPL_H

#include <silia/types/detail/index_swap.h>
#include <silia/types/detail/member_operations/matrix_addition_assignment.h>
#include <silia/types/detail/member_operations/matrix_member_division_assignment.h>
#include <silia/types/detail/member_operations/matrix_member_multiplication_assignment.h>
#include <silia/types/detail/member_operations/matrix_substraction_assignment.h>
#include <silia/types/detail/member_operations/scalar_addition_assignment.h>
#include <silia/types/detail/member_operations/scalar_division_assignment.h>
#include <silia/types/detail/member_operations/scalar_multiplication_assignment.h>
#include <silia/types/detail/member_operations/scalar_substraction_assignment.h>
#include <silia/types/detail/raw_matrix.h>
#include <silia/types/detail/types_fwd.h>

#include <type_traits>

namespace silia
{

namespace detail
{

template <size_t N, size_t M, typename Raw, typename T>
class TransposedViewImpl : public TransposedView<N, M, Raw, T>
{
  public:
    using base_type = TransposedView<N, M, Raw, T>;
    using index_type = typename base_type::index_type;
    using result_type = Matrix<N, M, T>;

    IndexSwap<M, N, Raw, T> operator[](index_type index)
    {
        return IndexSwap<M, N, Raw, T>(base_type::matrix_, index);
    }

    IndexSwap<M, N, Raw, T> operator[](index_type index) const
    {
        return IndexSwap<M, N, Raw, T>(base_type::matrix_, index);
    }

    constexpr bool IsView() const
    {
        return true;
    }

    detail::TransposedViewImpl<M, N, TransposedView<N, M, Raw, T>, T> GetTransposedView()
    {
        return detail::TransposedViewImpl<M, N, TransposedView<N, M, Raw, T>, T>(*this);
    }

    detail::RowViewImpl<M, T, TransposedView<N, M, Raw, T>> GetRowView(index_type index)
    {
        return detail::RowViewImpl<M, T, TransposedView<N, M, Raw, T>>(*this, index);
    }

    TransposedViewImpl(Raw matrix) : base_type{matrix} {}
};

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__TRANSPOSED_VIEW_IMPL_H
