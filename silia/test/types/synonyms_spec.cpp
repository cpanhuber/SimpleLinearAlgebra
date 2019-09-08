#include <silia/types/types.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <type_traits>

namespace silia
{
namespace
{
using namespace testing;

TEST(Types, Synonym_Matrix4d)
{
    Matrix4d m{};
    static_assert(std::is_same<decltype(m), Matrix<4, 4, double>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix4f)
{
    Matrix4f m{};
    static_assert(std::is_same<decltype(m), Matrix<4, 4, float>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix4i)
{
    Matrix4i m{};
    static_assert(std::is_same<decltype(m), Matrix<4, 4, int>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix3d)
{
    Matrix3d m{};
    static_assert(std::is_same<decltype(m), Matrix<3, 3, double>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix3f)
{
    Matrix3f m{};
    static_assert(std::is_same<decltype(m), Matrix<3, 3, float>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix3i)
{
    Matrix3i m{};
    static_assert(std::is_same<decltype(m), Matrix<3, 3, int>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix2d)
{
    Matrix2d m{};
    static_assert(std::is_same<decltype(m), Matrix<2, 2, double>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix2f)
{
    Matrix2f m{};
    static_assert(std::is_same<decltype(m), Matrix<2, 2, float>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix2i)
{
    Matrix2i m{};
    static_assert(std::is_same<decltype(m), Matrix<2, 2, int>>::value);
    SUCCEED();
}

}  // namespace

}  // namespace silia

