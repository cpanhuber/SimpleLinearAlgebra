#ifndef SILIA__OPERATIONS__CROSS_PRODUCT_H
#define SILIA__OPERATIONS__CROSS_PRODUCT_H

#include <silia/operations/detail/cross_product_detail.h>
#include <silia/types/types.h>

#include <array>

namespace silia
{

template <typename T, typename RawLeft, typename RawRight, typename MatrixTypeLeft, typename MatrixTypeRight>
Vector<3, T> Cross(detail::MatrixType<3, 1, RawLeft, MatrixTypeLeft, T> const& left,
                   detail::MatrixType<3, 1, RawRight, MatrixTypeRight, T> const& right)
{
    return detail::CrossImpl<detail::MatrixType<3, 1, RawLeft, MatrixTypeLeft, T>,
                             detail::MatrixType<3, 1, RawRight, MatrixTypeRight, T>,
                             Vector<3, T>>(left, right);
}

}  // namespace silia

#endif  // SILIA__OPERATIONS__CROSS_PRODUCT_H
