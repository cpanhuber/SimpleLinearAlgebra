#ifndef SILIA__TYPES__TYPES_H
#define SILIA__TYPES__TYPES_H

#include <silia/types/matrix.h>

namespace silia
{
using Matrix4d = Matrix<4, 4, detail::MatrixImpl<4, 4, double>, double>;
using Matrix4f = Matrix<4, 4, detail::MatrixImpl<4, 4, float>, float>;
using Matrix4i = Matrix<4, 4, detail::MatrixImpl<4, 4, int>, int>;

using Matrix3d = Matrix<3, 3, detail::MatrixImpl<3, 3, double>, double>;
using Matrix3f = Matrix<3, 3, detail::MatrixImpl<3, 3, float>, float>;
using Matrix3i = Matrix<3, 3, detail::MatrixImpl<3, 3, int>, int>;

using Matrix2d = Matrix<2, 2, detail::MatrixImpl<2, 2, double>, double>;
using Matrix2f = Matrix<2, 2, detail::MatrixImpl<2, 2, float>, float>;
using Matrix2i = Matrix<2, 2, detail::MatrixImpl<2, 2, int>, int>;

using Vector4d = Matrix<4, 1, detail::VectorImpl<4, double>, double>;
using Vector4f = Matrix<4, 1, detail::VectorImpl<4, float>, float>;
using Vector4i = Matrix<4, 1, detail::VectorImpl<4, int>, int>;

using Vector3d = Matrix<3, 1, detail::VectorImpl<3, double>, double>;
using Vector3f = Matrix<3, 1, detail::VectorImpl<3, float>, float>;
using Vector3i = Matrix<3, 1, detail::VectorImpl<3, int>, int>;

using Vector2d = Matrix<2, 1, detail::VectorImpl<2, double>, double>;
using Vector2f = Matrix<2, 1, detail::VectorImpl<2, float>, float>;
using Vector2i = Matrix<2, 1, detail::VectorImpl<2, int>, int>;
}  // namespace silia

#endif  // SILIA__TYPES__TYPES_H

