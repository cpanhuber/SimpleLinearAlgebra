#ifndef SILIA__TYPES__DETAIL__MATRIX_DETAIL_H
#define SILIA__TYPES__DETAIL__MATRIX_DETAIL_H

#include <array>
#include <memory>

namespace silia
{

namespace detail
{

template <size_t N, size_t M, typename T = double>
class TransposedMatrixImpl;

template <size_t N, typename T = double>
class VectorImpl;

template <size_t N, size_t M, typename T = double>
class MatrixImpl;
}  // namespace detail

template <size_t N, size_t M, typename T, typename V = double>
class Matrix;

template <size_t N, size_t M, typename T = double>
Matrix<N, M, detail::MatrixImpl<N, M, T>, T> MakeMatrix();

template <size_t N, typename T = double>
Matrix<N, 1, detail::VectorImpl<N, T>, T> MakeVector();

namespace detail
{
template <size_t N, size_t M, typename T = double>
using RawMatrix = std::array<std::array<T, M>, N>;

template <size_t N, size_t M, typename T = double>
class IndexSwap
{
  public:
    using index_type = size_t;

    friend TransposedMatrixImpl<N, M, T>;

    T& operator[](index_type inner_index)
    {
        return matrix_[inner_index][index_];
    }

    T operator[](index_type inner_index) const
    {
        return matrix_[inner_index][index_];
    }

  private:
    IndexSwap(RawMatrix<N, M, T>& matrix, index_type index) : index_{index}, matrix_{matrix} {}

    index_type index_;
    RawMatrix<N, M, T>& matrix_;
};

template <size_t N, size_t M, typename T>
class TransposedMatrixImpl : public Matrix<N, M, TransposedMatrixImpl<N, M, T>, T>
{
  public:
    using BaseType = Matrix<N, M, TransposedMatrixImpl<N, M, T>, T>;
    using BaseType::Matrix;

    IndexSwap<N, M, T> operator[](typename BaseType::index_type index)
    {
        return IndexSwap<N, M, T>(BaseType::matrix_, index);
    }

    IndexSwap<N, M, T> operator[](typename BaseType::index_type index) const
    {
        return IndexSwap<N, M, T>(BaseType::matrix_, index);
    }

  private:
    TransposedMatrixImpl() {}
};

template <size_t N, typename T>
class VectorImpl : public Matrix<N, 1, VectorImpl<N, T>, T>
{
  public:
    using BaseType = Matrix<N, 1, VectorImpl<N, T>, T>;
    using ValueType = T;

    VectorImpl(T const (&list)[N])
    {
        for (size_t i = 0; i < N; ++i)
        {
            BaseType::matrix_[i][0] = list[i];
        }
    }

    T& operator[](typename BaseType::index_type index)
    {
        return BaseType::matrix_[index][0];
    }

    T const& operator[](typename BaseType::index_type index) const
    {
        return BaseType::matrix_[index][0];
    }

  private:
    VectorImpl() {}

    friend Matrix<N, 1, VectorImpl<N, T>, T> MakeVector<N, T>();
};

template <size_t N, size_t M, typename T>
class MatrixImpl : public Matrix<N, M, MatrixImpl<N, M, T>, T>
{
  public:
    using BaseType = Matrix<N, M, MatrixImpl<N, M, T>, T>;
    using ValueType = std::array<T, M>;
    using BaseType::Matrix;

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

    friend Matrix<N, M, MatrixImpl<N, M, T>, T> MakeMatrix<N, M, T>();
};
}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__MATRIX_DETAIL_H
