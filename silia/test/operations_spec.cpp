#include <silia/operations/operations.h>
#include <silia/types/factories.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <type_traits>

namespace silia
{
namespace
{
using namespace testing;

TEST(Operations, Multiplication_WhenMatrixMatrix)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    auto m2 = MakeMatrix({{0, 1}, {2, 3}});

    auto m3 = m1 * m2;

    static_assert(std::is_same<decltype(m3), Matrix<3, 2, detail::MatrixImpl<3, 2, int>, int>>::value);
    EXPECT_EQ(2, m3[0][0]);
    EXPECT_EQ(3, m3[0][1]);
    EXPECT_EQ(6, m3[1][0]);
    EXPECT_EQ(11, m3[1][1]);
    EXPECT_EQ(10, m3[2][0]);
    EXPECT_EQ(19, m3[2][1]);
}

TEST(Operations, Multiplication_WhenVectorMatrix)
{
    Vector2i v = MakeVector({2, 1});
    auto m1 = MakeMatrix({{3, 2}});

    auto m2 = v * m1;

    static_assert(std::is_same<decltype(m2), Matrix<2, 2, detail::MatrixImpl<2, 2, int>, int>>::value);
    EXPECT_EQ(6, m2[0][0]);
    EXPECT_EQ(4, m2[0][1]);
    EXPECT_EQ(3, m2[1][0]);
    EXPECT_EQ(2, m2[1][1]);
}

TEST(Operations, Multiplication_WhenMatrixVector)
{
    Vector2i v1 = MakeVector({2, 1});
    auto m = MakeMatrix({{4, 3}, {1, 2}});

    auto v2 = m * v1;

    static_assert(std::is_same<decltype(v2), Matrix<2, 1, detail::VectorImpl<2, int>, int>>::value);
    EXPECT_EQ(11, v2[0]);
    EXPECT_EQ(4, v2[1]);
}

TEST(Operations, Multiplication_WhenVectorDotProduct)
{
    Vector3i v1 = MakeVector({3, 2, 1});
    Vector3i v2 = MakeVector({2, 1, 0});

    auto v3 = v1 * v2;

    static_assert(std::is_same<decltype(v3), int>::value);
    EXPECT_EQ(8, v3);
}

TEST(Operations, CopylessTranspose_WhenMatrix)
{
    auto m = MakeMatrix({{5, 4}, {3, 2}, {1, 0}});

    EXPECT_EQ(5, m.Transpose()[0][0]);
    EXPECT_EQ(3, m.Transpose()[0][1]);
    EXPECT_EQ(1, m.Transpose()[0][2]);
    EXPECT_EQ(4, m.Transpose()[1][0]);
    EXPECT_EQ(2, m.Transpose()[1][1]);
    EXPECT_EQ(0, m.Transpose()[1][2]);
    EXPECT_EQ(&(m[0][0]), &(m.Transpose()[0][0]));
}

TEST(Operations, CopylessTranspose_WhenVector)
{
    auto v = MakeVector({5, 4, 3});

    EXPECT_EQ(5, v.Transpose()[0][0]);
    EXPECT_EQ(4, v.Transpose()[0][1]);
    EXPECT_EQ(3, v.Transpose()[0][2]);
    EXPECT_EQ(&(v[0][0]), &(v.Transpose()[0][0]));
}

}  // namespace

}  // namespace silia
