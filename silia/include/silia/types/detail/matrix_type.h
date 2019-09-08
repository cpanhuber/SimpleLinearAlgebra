#ifndef SILIA__TYPES__DETAIL_MATRIX_TYPE_H
#define SILIA__TYPES__DETAIL_MATRIX_TYPE_H

#include <silia/types/detail/transposed_matrix_impl.h>

#include <cstddef>
#include <type_traits>

namespace silia
{

namespace detail
{

template <size_t N, size_t M, typename Derived, typename V>
class MatrixType
{
  public:
    using index_type = size_t;

    template <typename T = Derived>
    auto operator[](index_type index) -> decltype(std::declval<T>()[0])
    {
        static_assert(std::is_same<T, Derived>::value,
                      "Only the default template argument is allowed for Matrix::operator[]");

        return static_cast<T*>(this)->operator[](index);
    }

    template <typename T = Derived>
    auto operator[](index_type index) const -> decltype(std::declval<T const>()[0])
    {
        static_assert(std::is_same<T, Derived>::value,
                      "Only the default template argument is allowed for Matrix::operator[]");

        return static_cast<T const*>(this)->operator[](index);
    }

    detail::TransposedMatrixImpl<M, N, V> TransposedView()
    {
        return detail::TransposedMatrixImpl<M, N, V>(matrix_);
    }

    MatrixType(V const (&list)[N][M]) : matrix_{}
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                matrix_[i][j] = list[i][j];
            }
        }
    }

    MatrixType() : matrix_{} {}

  protected:
    detail::RawMatrix<N, M, V> matrix_;
};

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__MATRIX_TYPE_H