#ifndef SILIA__TYPES__DETAIL__FACTORY_FWD_H
#define SILIA__TYPES__DETAIL__FACTORY_FWD_H

#include <silia/types/detail/types_fwd.h>

namespace silia
{

template <size_t N, typename T = double>
Vector<N, T> MakeVector();

template <size_t N, size_t M, typename T = double>
Matrix<N, M, T> MakeMatrix();

}  // namespace silia

#endif  //  SILIA__TYPES__DETAIL__FACTORY_FWD_H
