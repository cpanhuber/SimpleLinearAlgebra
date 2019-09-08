#ifndef SILIA__TYPES__TYPES_H
#define SILIA__TYPES__TYPES_H

#include <silia/types/detail/matrix_impl.h>
#include <silia/types/detail/matrix_type.h>
#include <silia/types/detail/types_fwd.h>
#include <silia/types/detail/vector_impl.h>

namespace silia
{
using Matrix4d = Matrix<4, 4, double>;
using Matrix4f = Matrix<4, 4, float>;
using Matrix4i = Matrix<4, 4, int>;

using Matrix3d = Matrix<3, 3, double>;
using Matrix3f = Matrix<3, 3, float>;
using Matrix3i = Matrix<3, 3, int>;

using Matrix2d = Matrix<2, 2, double>;
using Matrix2f = Matrix<2, 2, float>;
using Matrix2i = Matrix<2, 2, int>;

using Vector4d = Vector<4, double>;
using Vector4f = Vector<4, float>;
using Vector4i = Vector<4, int>;

using Vector3d = Vector<3, double>;
using Vector3f = Vector<3, float>;
using Vector3i = Vector<3, int>;

using Vector2d = Vector<2, double>;
using Vector2f = Vector<2, float>;
using Vector2i = Vector<2, int>;
}  // namespace silia

#endif  // SILIA__TYPES__TYPES_H

