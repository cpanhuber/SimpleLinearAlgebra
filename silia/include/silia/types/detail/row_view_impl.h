#ifndef SILIA__TYPES__DETAIL__ROW_VIEW_IMPL_H
#define SILIA__TYPES__DETAIL__ROW_VIEW_IMPL_H

#include <silia/types/detail/factory_fwd.h>
#include <silia/types/detail/indexable_scalar.h>
#include <silia/types/detail/types_fwd.h>

namespace silia
{

namespace detail
{

template <typename RowView, typename V>
class TemporaryRowValue
{
  public:
    using index_type = size_t;

    V& operator[](index_type index)
    {
        return row_view_.At(index);
    }

    V operator[](index_type index) const
    {
        return row_view_.At(index);
    }

    TemporaryRowValue& operator=(V const& v)
    {
        row_view_.At(index_) = v;
        return *this;
    }

    operator V()
    {
        return row_view_.At(index_);
    }

    operator V() const
    {
        return row_view_.At(index_);
    }

    TemporaryRowValue(RowView& row_view, index_type index) : row_view_{row_view}, index_{index} {}

  private:
    RowView& row_view_;
    index_type index_;
};

template <size_t N, typename T, typename Raw>
class RowViewImpl : public RowView<N, T, Raw>
{
  public:
    using base_type = RowView<N, T, Raw>;
    using value_type = T;
    using result_type = Matrix<1, N, T>;
    using index_type = typename base_type::index_type;

    TemporaryRowValue<RowViewImpl<N, T, Raw>, T> operator[](typename base_type::index_type index)
    {
        return TemporaryRowValue<RowViewImpl<N, T, Raw>, T>(*this, index);
    }

    TemporaryRowValue<RowViewImpl<N, T, Raw> const, T> const operator[](typename base_type::index_type index) const
    {
        return TemporaryRowValue<RowViewImpl<N, T, Raw> const, T>(*this, index);
    }

    T& At(index_type index)
    {
        return base_type::matrix_[row_index_][index];
    }

    T At(index_type index) const
    {
        return base_type::matrix_[row_index_][index];
    }

    constexpr bool IsView() const
    {
        return true;
    }

    RowViewImpl(Raw raw, typename base_type::index_type row_index) : base_type{raw}, row_index_{row_index} {}

    detail::TransposedViewImpl<N, 1, RowView<N, T, Raw>, T> GetTransposedView()
    {
        return detail::TransposedViewImpl<N, 1, RowView<N, T, Raw>, T>(*this);
    }

    detail::RowViewImpl<N, T, Raw> GetRowView(index_type index)
    {
        assert(index == 0);
        return *this;
    }

    detail::ColumnViewImpl<1, T, RowView<N, T, Raw>> GetColumnView(index_type index)
    {
        return detail::ColumnViewImpl<1, T, RowView<N, T, Raw>>(*this, index);
    }

    detail::DiagonalViewImpl<1, T, RowView<N, T, Raw>> GetDiagonalView()
    {
        return detail::DiagonalViewImpl<1, T, RowView<N, T, Raw>>(*this);
    }

  private:
    typename base_type::index_type row_index_;
};

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__ROW_VIEW_IMPL_H
