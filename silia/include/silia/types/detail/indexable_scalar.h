#ifndef SILIA__TYPES__DETAIL__INDEXABLE_SCALAR_H
#define SILIA__TYPES__DETAIL__INDEXABLE_SCALAR_H

#include <silia/types/detail/types_fwd.h>

#include <cassert>

namespace silia
{

namespace detail
{

template <size_t N, typename T = double>
class IndexableScalar
{
  public:
    using index_type = size_t;

    friend VectorImpl<N, T>;

    T& operator[](index_type index)
    {
        assert(index == 0);
        return value_;
    }

    T operator[](index_type index) const
    {
        assert(index == 0);
        return value_;
    }

    operator T() const
    {
        return value_;
    }

    void operator=(const T& value)
    {
        value_ = value;
    }

  private:
    IndexableScalar(T& value) : value_{value} {}

    T& value_;
};

template <size_t N, typename T = double>
class IndexableScalarConst
{
  public:
    using index_type = size_t;

    friend VectorImpl<N, T>;

    T operator[](index_type index) const
    {
        assert(index == 0);
        return value_;
    }

    operator T() const
    {
        return value_;
    }

  private:
    IndexableScalarConst(T const& value) : value_{value} {}

    const T& value_;
};

}  // namespace detail
}  // namespace silia
#endif  //  SILIA__TYPES__DETAIL__INDEXABLE_SCALAR_H
