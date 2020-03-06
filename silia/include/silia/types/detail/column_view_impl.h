#ifndef SILIA__TYPES__DETAIL__COLUMN_VIEW_IMPL_H
#define SILIA__TYPES__DETAIL__COLUMN_VIEW_IMPL_H

#include <silia/types/detail/factory_fwd.h>
#include <silia/types/detail/indexable_scalar.h>
#include <silia/types/detail/types_fwd.h>

namespace silia
{

namespace detail
{

template <size_t N, typename T, typename Raw>
class ColumnViewImpl : public ColumnView<N, T, Raw>
{
  public:
    using base_type = ColumnView<N, T, Raw>;
    using value_type = T;
    using result_type = Vector<N, T>;
    using index_type = typename base_type::index_type;

    using base_type::operator=;

    IndexableScalar<N, T> operator[](typename base_type::index_type index)
    {
        return IndexableScalar<N, T>(base_type::matrix_[index][column_index_]);
    }

    IndexableScalarConst<N, T> operator[](typename base_type::index_type index) const
    {
        return IndexableScalarConst<N, T>(base_type::matrix_[index][column_index_]);
    }

    ColumnViewImpl(Raw raw, typename base_type::index_type column_index) : base_type{raw}, column_index_{column_index}
    {
    }

    constexpr bool IsView() const
    {
        return true;
    }

    detail::TransposedViewImpl<1, N, ColumnView<N, T, Raw>, T> GetTransposedView()
    {
        return detail::TransposedViewImpl<1, N, ColumnView<N, T, Raw>, T>(*this);
    }

    detail::RowViewImpl<1, T, ColumnView<N, T, Raw>> GetRowView(index_type index)
    {
        return detail::RowViewImpl<1, T, ColumnView<N, T, Raw>>(*this, index);
    }

    detail::ColumnViewImpl<N, T, Raw> GetColumnView(index_type index)
    {
        assert(index == 0);
        return *this;
    }

    detail::DiagonalViewImpl<1, T, ColumnView<N, T, Raw>> GetDiagonalView()
    {
        return detail::DiagonalViewImpl<1, T, ColumnView<N, T, Raw>>(*this);
    }

  private:
    typename base_type::index_type column_index_;
};

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__COLUMN_VIEW_IMPL_H
