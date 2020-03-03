#ifndef SILIA__TYPES__DETAIL_MATRIX_TYPE_H
#define SILIA__TYPES__DETAIL_MATRIX_TYPE_H

#include <silia/types/detail/member_operations/copy.h>
#include <silia/types/detail/member_operations/matrix_addition_assignment.h>
#include <silia/types/detail/member_operations/matrix_member_division_assignment.h>
#include <silia/types/detail/member_operations/matrix_member_multiplication_assignment.h>
#include <silia/types/detail/member_operations/matrix_substraction_assignment.h>
#include <silia/types/detail/member_operations/scalar_addition_assignment.h>
#include <silia/types/detail/member_operations/scalar_division_assignment.h>
#include <silia/types/detail/member_operations/scalar_multiplication_assignment.h>
#include <silia/types/detail/member_operations/scalar_substraction_assignment.h>
#include <silia/types/detail/transposed_view_impl.h>

#include <cstddef>
#include <type_traits>

namespace silia
{

namespace detail
{

template <size_t N, size_t M, typename Raw, typename Derived, typename V>
class MatrixType
{
  public:
    using index_type = size_t;

    template <typename T = Derived>
    auto operator[](index_type index) -> decltype(std::declval<T>()[0])
    {
        static_assert(std::is_same<T, Derived>::value,
                      "Only the default template argument is allowed for MatrixType::operator[]");

        return static_cast<T*>(this)->operator[](index);
    }

    template <typename T = Derived>
    auto operator[](index_type index) const -> decltype(std::declval<T const>()[0])
    {
        static_assert(std::is_same<T, Derived>::value,
                      "Only the default template argument is allowed for MatrixType::operator[]");

        return static_cast<T const*>(this)->operator[](index);
    }

    detail::TransposedViewImpl<M, N, MatrixType<N, M, Raw, Derived, V>&, V> TransposedView()
    {
        return detail::TransposedViewImpl<M, N, MatrixType<N, M, Raw, Derived, V>&, V>(*this);
    }

    MatrixType& operator*=(V const& factor)
    {
        ScalarMultiplyAssignImpl<N, M, decltype(*this), V>(*this, factor);
        return *this;
    }

    MatrixType& operator/=(V const& factor)
    {
        ScalarDivideAssignImpl<N, M, decltype(*this), V>(*this, factor);
        return *this;
    }

    MatrixType& operator+=(V const& summand)
    {
        ScalarAddAssignImpl<N, M, decltype(*this), V>(*this, summand);
        return *this;
    }

    MatrixType& operator-=(V const& summand)
    {
        ScalarSubstractAssignImpl<N, M, decltype(*this), V>(*this, summand);
        return *this;
    }

    template <typename OtherRaw, typename OtherDerived, typename T>
    MatrixType& operator+=(MatrixType<N, M, OtherRaw, OtherDerived, T> const& right)
    {
        MatrixAddAssignImpl<N, M, decltype(*this), MatrixType<N, M, OtherRaw, OtherDerived, T>>(*this, right);
        return *this;
    }

    template <typename OtherRaw, typename OtherDerived, typename T>
    MatrixType& operator-=(MatrixType<N, M, OtherRaw, OtherDerived, T> const& right)
    {
        MatrixSubstractAssignImpl<N, M, decltype(*this), MatrixType<N, M, OtherRaw, OtherDerived, T>>(*this, right);
        return *this;
    }

    template <typename OtherRaw, typename OtherDerived, typename T>
    MatrixType& operator*=(MatrixType<N, M, OtherRaw, OtherDerived, T> const& right)
    {
        MatrixMemberMultiplyAssignImpl<N, M, decltype(*this), MatrixType<N, M, OtherRaw, OtherDerived, T>>(*this,
                                                                                                           right);
        return *this;
    }

    template <typename OtherRaw, typename OtherDerived, typename T>
    MatrixType& operator/=(MatrixType<N, M, OtherRaw, OtherDerived, T> const& right)
    {
        MatrixMemberDivideAssignImpl<N, M, decltype(*this), MatrixType<N, M, OtherRaw, OtherDerived, T>>(*this, right);
        return *this;
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

    template <typename OtherRaw, typename OtherDerived>
    MatrixType(MatrixType<N, M, OtherRaw, OtherDerived, V> const& other) : matrix_{}
    {
        Copy<N, M, MatrixType<N, M, OtherRaw, OtherDerived, V>, Raw, V>(other, matrix_);
    }

    template <typename OtherRaw, typename OtherDerived>
    MatrixType& operator=(MatrixType<N, M, OtherRaw, OtherDerived, V> const& other)
    {
        Copy<N, M, MatrixType<N, M, OtherRaw, OtherDerived, V>, Raw, V>(other, matrix_);
        return *this;
    }

    MatrixType() : matrix_{} {}

  protected:
    MatrixType(Raw matrix) : matrix_(matrix) {}
    Raw matrix_;
};

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__MATRIX_TYPE_H
