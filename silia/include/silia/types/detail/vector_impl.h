#ifndef SILIA__TYPES__DETAIL__VECTOR_IMPL_H
#define SILIA__TYPES__DETAIL__VECTOR_IMPL_H

#include <silia/types/detail/factory_fwd.h>
#include <silia/types/detail/indexable_scalar.h>
#include <silia/types/detail/types_fwd.h>

namespace silia
{

template <size_t N, typename T = double>
Vector<N, T> MakeVector();

namespace detail
{

template <size_t N, typename T>
class VectorImpl : public Vector<N, T>
{
  public:
    using base_type = Vector<N, T>;
    using value_type = T;
    using result_type = base_type;
    using index_type = typename base_type::index_type;

    VectorImpl(T const (&list)[N])
    {
        for (size_t i = 0; i < N; ++i)
        {
            base_type::matrix_[i][0] = list[i];
        }
    }

    IndexableScalar<N, T> operator[](typename base_type::index_type index)
    {
        return IndexableScalar<N, T>(base_type::matrix_[index][0]);
    }

    IndexableScalarConst<N, T> operator[](typename base_type::index_type index) const
    {
        return IndexableScalarConst<N, T>(base_type::matrix_[index][0]);
    }

    constexpr bool IsView() const
    {
        return false;
    }

    detail::TransposedViewImpl<1, N, Vector<N, T>&, T> GetTransposedView()
    {
        return detail::TransposedViewImpl<1, N, Vector<N, T>&, T>(*this);
    }

    detail::RowViewImpl<1, T, Vector<N, T>&> GetRowView(index_type index)
    {
        return detail::RowViewImpl<1, T, Vector<N, T>&>(*this, index);
    }

    detail::ColumnViewImpl<N, T, Vector<N, T>&> GetColumnView(index_type index)
    {
        return detail::ColumnViewImpl<N, T, Vector<N, T>&>(*this, index);
    }

    detail::DiagonalViewImpl<N, T, Vector<N, T>&> GetDiagonalView()
    {
        return detail::DiagonalViewImpl<1, T, Vector<N, T>&>(*this);
    }

  private:
    VectorImpl() {}

    friend Vector<N, T> MakeVector<N, T>();
};

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__VECTOR_IMPL_H
