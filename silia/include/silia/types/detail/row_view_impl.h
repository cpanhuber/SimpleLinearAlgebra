#ifndef SILIA__TYPES__DETAIL__ROW_VIEW_IMPL_H
#define SILIA__TYPES__DETAIL__ROW_VIEW_IMPL_H

#include <silia/types/detail/factory_fwd.h>
#include <silia/types/detail/indexable_scalar.h>
#include <silia/types/detail/types_fwd.h>

namespace silia
{

namespace detail
{

template <size_t N, typename T, typename Raw>
class RowViewImpl : public RowView<N, T, Raw>
{
  public:
    using base_type = RowView<N, T, Raw>;
    using value_type = T;
    using result_type = Vector<N, T>;
    using index_type = typename base_type::index_type;

    IndexableScalar<N, T> operator[](typename base_type::index_type index)
    {
        return IndexableScalar<N, T>(base_type::matrix_[row_index_][index]);
    }

    IndexableScalarConst<N, T> operator[](typename base_type::index_type index) const
    {
        return IndexableScalarConst<N, T>(base_type::matrix_[row_index_][index]);
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

  private:
    typename base_type::index_type row_index_;
};

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__ROW_VIEW_IMPL_H
