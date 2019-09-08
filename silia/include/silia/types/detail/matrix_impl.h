#ifndef SILIA__TYPES__DETAIL__MATRIX_IMPL_H
#define SILIA__TYPES__DETAIL__MATRIX_IMPL_H

#include <silia/types/detail/factory_fwd.h>
#include <silia/types/detail/types_fwd.h>

#include <array>

namespace silia
{

namespace detail
{
template <size_t N, size_t M, typename T>
class MatrixImpl : public Matrix<N, M, T>
{
  public:
    using BaseType = Matrix<N, M, T>;
    using ValueType = std::array<T, M>;
    using BaseType::MatrixType;

    std::array<T, M>& operator[](typename BaseType::index_type index)
    {
        return BaseType::matrix_[index];
    }

    std::array<T, M> const& operator[](typename BaseType::index_type index) const
    {
        return BaseType::matrix_[index];
    }

  private:
    MatrixImpl() {}

    friend Matrix<N, M, T> MakeMatrix<N, M, T>();
};
}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__MATRIX_IMPL_H
