#ifndef NED_ECEF__ALGEBRA__TYPES_H
#define NED_ECEF__ALGEBRA__TYPES_H

#include <ned_ecef/algebra/detail/types_detail.h>

#include <cstddef>
#include <type_traits>

namespace ned_ecef
{
namespace algebra
{

template <size_t N, size_t M, typename Derived, typename V>
class Matrix
{
  public:
    using index_type = size_t;

    template <typename T = Derived>
    auto operator[](index_type index) -> typename std::result_of<decltype (&T::operator[])(T, index_type)>::type&
    {
        static_assert(std::is_same<T, Derived>::value,
                      "Only the default template argument is allowed for Matrix::operator[]");

        return static_cast<T*>(this)->operator[](index);
    }

  protected:
    detail::RawMatrix<N, M, V> matrix_;
};

}  // namespace algebra

}  // namespace ned_ecef

#endif  // NED_ECEF__ALGEBRA__TYPES_H
