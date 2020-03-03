#ifndef SILIA__TYPES__DETAIL__INDEXABLE_SCALAR_H
#define SILIA__TYPES__DETAIL__INDEXABLE_SCALAR_H

#include <silia/types/detail/types_fwd.h>

#include <cassert>

namespace silia
{

namespace detail
{

template <size_t N, typename T>
class IndexableScalar
{
  public:
    using index_type = size_t;

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

    IndexableScalar(T& value) : value_{value} {}

  private:
    T& value_;
};

template <size_t N, typename T>
class IndexableScalarConst
{
  public:
    using index_type = size_t;

    T operator[](index_type index) const
    {
        assert(index == 0);
        return value_;
    }

    operator T() const
    {
        return value_;
    }

    IndexableScalarConst(T const& value) : value_{value} {}

  private:
    const T& value_;
};

}  // namespace detail
}  // namespace silia
#endif  //  SILIA__TYPES__DETAIL__INDEXABLE_SCALAR_H
