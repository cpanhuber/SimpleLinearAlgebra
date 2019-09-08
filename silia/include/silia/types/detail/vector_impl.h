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
    using BaseType = Vector<N, T>;
    using ValueType = T;

    VectorImpl(T const (&list)[N])
    {
        for (size_t i = 0; i < N; ++i)
        {
            BaseType::matrix_[i][0] = list[i];
        }
    }

    IndexableScalar<N, T> operator[](typename BaseType::index_type index)
    {
        return IndexableScalar<N, T>(BaseType::matrix_[index][0]);
    }

    IndexableScalarConst<N, T> operator[](typename BaseType::index_type index) const
    {
        return IndexableScalarConst<N, T>(BaseType::matrix_[index][0]);
    }

  private:
    VectorImpl() {}

    friend Vector<N, T> MakeVector<N, T>();
};

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__VECTOR_IMPL_H
