#ifndef SILIA__OPERATIONS__CROSS_PRODUCT_H
#define SILIA__OPERATIONS__CROSS_PRODUCT_H

#include <silia/operations/detail/cross_product_detail.h>
#include <silia/types/types.h>

#include <array>

namespace silia
{

template <typename T, typename MatrixTypeLeft, typename MatrixTypeRight>
Vector<3, T> Cross(detail::MatrixType<3, 1, MatrixTypeLeft, T> const& left,
                   detail::MatrixType<3, 1, MatrixTypeRight, T> const& right)
{
    return detail::CrossImpl<detail::MatrixType<3, 1, MatrixTypeLeft, T>,
                             detail::MatrixType<3, 1, MatrixTypeRight, T>,
                             Vector<3, T>>(left, right);
}

template <typename T, typename MatrixTypeLeft>
Vector<3, T> Cross(detail::MatrixType<3, 1, MatrixTypeLeft, T> const& left,
                   detail::TransposedMatrixImpl<3, 1, T> const& right)
{
    return detail::CrossImpl<detail::MatrixType<3, 1, MatrixTypeLeft, T>,
                             detail::TransposedMatrixImpl<3, 1, T>,
                             Vector<3, T>>(left, right);
}

template <typename T, typename MatrixTypeRight>
Vector<3, T> Cross(detail::TransposedMatrixImpl<3, 1, T> const& left,
                   detail::MatrixType<3, 1, MatrixTypeRight, T> const& right)
{
    return detail::CrossImpl<detail::TransposedMatrixImpl<3, 1, T>,
                             detail::MatrixType<3, 1, MatrixTypeRight, T>,
                             Vector<3, T>>(left, right);
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__CROSS_PRODUCT_H
