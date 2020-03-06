#ifndef SILIA__TYPES__DETAIL__DIAGONAL_VIEW_IMPL_H
#define SILIA__TYPES__DETAIL__DIAGONAL_VIEW_IMPL_H

#include <silia/types/detail/factory_fwd.h>
#include <silia/types/detail/indexable_scalar.h>
#include <silia/types/detail/types_fwd.h>

namespace silia
{

namespace detail
{

template <size_t N, typename T, typename Raw>
class DiagonalViewImpl : public DiagonalView<N, T, Raw>
{
  public:
    using base_type = DiagonalView<N, T, Raw>;
    using value_type = T;
    using result_type = Vector<N, T>;
    using index_type = typename base_type::index_type;

    using base_type::operator=;

    IndexableScalar<N, T> operator[](typename base_type::index_type index)
    {
        return IndexableScalar<N, T>(base_type::matrix_[index][index]);
    }

    IndexableScalarConst<N, T> operator[](typename base_type::index_type index) const
    {
        return IndexableScalarConst<N, T>(base_type::matrix_[index][index]);
    }

    constexpr bool IsView() const
    {
        return true;
    }

    DiagonalViewImpl(Raw raw) : base_type{raw} {}

    detail::TransposedViewImpl<1, N, DiagonalView<N, T, Raw>, T> GetTransposedView()
    {
        return detail::TransposedViewImpl<1, N, DiagonalView<N, T, Raw>, T>(*this);
    }

    detail::RowViewImpl<1, T, DiagonalView<N, T, Raw>> GetRowView(index_type index)
    {
        return detail::RowViewImpl<1, T, DiagonalView<N, T, Raw>>(*this, index);
    }

    detail::ColumnViewImpl<1, T, DiagonalView<N, T, Raw>> GetColumnView(index_type index)
    {
        return detail::ColumnViewImpl<1, T, DiagonalView<N, T, Raw>>(*this, index);
    }

    detail::DiagonalViewImpl<N, T, Raw> GetDiagonalView()
    {
        return *this;
    }
};

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__DIAGONAL_VIEW_IMPL_H
