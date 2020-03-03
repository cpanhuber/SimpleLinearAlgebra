#ifndef SILIA__OPERATIONS__UNIT_H
#define SILIA__OPERATIONS__UNIT_H

#include <silia/operations/detail/unit_detail.h>
#include <silia/types/types.h>

#include <cmath>

namespace silia
{

template <size_t N, typename T, typename Raw, typename MatrixType>
Vector<N, double> Unit(detail::MatrixType<N, 1, Raw, MatrixType, T> const& vector_like)
{
    return detail::UnitImpl<N, detail::MatrixType<N, 1, Raw, MatrixType, T>, double, Vector<N, double>>(vector_like);
}

template <size_t N, typename T, typename Raw, typename MatrixType>
Vector<N, float> UnitF(detail::MatrixType<N, 1, Raw, MatrixType, T> const& vector_like)
{
    return detail::UnitImpl<N, detail::MatrixType<N, 1, Raw, MatrixType, T>, float, Vector<N, float>>(vector_like);
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__UNIT_H
