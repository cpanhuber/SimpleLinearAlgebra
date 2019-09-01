#ifndef NED_ECEF__ALGEBRA__FACTORIES_H
#define NED_ECEF__ALGEBRA__FACTORIES_H

#include <ned_ecef/algebra/detail/types_detail.h>

namespace ned_ecef
{
namespace algebra
{

template <size_t N, size_t M, typename T>
detail::MatrixImpl<N, M, T> MakeMatrix()
{
    return detail::MatrixImpl<N, M, T>{};
}

template <size_t N, typename T>
detail::VectorImpl<N, T> MakeVector()
{
    return detail::VectorImpl<N, T>{};
}

}  // namespace algebra
}  // namespace ned_ecef

#endif  // NED_ECEF__ALGEBRA__FACTORIES_H
