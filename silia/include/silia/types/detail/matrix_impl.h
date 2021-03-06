#ifndef SILIA__TYPES__DETAIL__MATRIX_IMPL_H
#define SILIA__TYPES__DETAIL__MATRIX_IMPL_H

#include <silia/types/detail/constexpr_min.h>
#include <silia/types/detail/factory_fwd.h>
#include <silia/types/detail/types_fwd.h>

#include <array>
#include <iostream>

namespace silia
{

namespace detail
{
template <size_t N, size_t M, typename T>
class MatrixImpl : public Matrix<N, M, T>
{
  public:
    using base_type = Matrix<N, M, T>;
    using value_type = std::array<T, M>;
    using result_type = base_type;
    using index_type = typename base_type::index_type;

    using base_type::operator=;

    std::array<T, M>& operator[](typename base_type::index_type index)
    {
        return base_type::matrix_[index];
    }

    std::array<T, M> const& operator[](typename base_type::index_type index) const
    {
        return base_type::matrix_[index];
    }

    MatrixImpl(T const (&list)[N][M]) : base_type(list) {}

    constexpr bool IsView() const
    {
        return false;
    }

    detail::TransposedViewImpl<M, N, Matrix<N, M, T>&, T> GetTransposedView()
    {
        return detail::TransposedViewImpl<M, N, Matrix<N, M, T>&, T>(*this);
    }

    detail::RowViewImpl<M, T, Matrix<N, M, T>&> GetRowView(index_type index)
    {
        return detail::RowViewImpl<M, T, Matrix<N, M, T>&>(*this, index);
    }

    detail::ColumnViewImpl<N, T, Matrix<N, M, T>&> GetColumnView(index_type index)
    {
        return detail::ColumnViewImpl<N, T, Matrix<N, M, T>&>(*this, index);
    }

    detail::DiagonalViewImpl<detail::constexpr_min(N, M), T, Matrix<N, M, T>&> GetDiagonalView()
    {
        return detail::DiagonalViewImpl<detail::constexpr_min(N, M), T, Matrix<N, M, T>&>(*this);
    }

  private:
    MatrixImpl() {}

    friend Matrix<N, M, T> MakeMatrix<N, M, T>();
};
}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__MATRIX_IMPL_H
