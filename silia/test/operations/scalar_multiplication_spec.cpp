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

TEST(ScalarMultiplication, ScalarWithMatrix)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int factor = 2;

    auto m2 = factor * m1;

    static_assert(std::is_same<decltype(m2), Matrix<3, 2, int>>::value);
    EXPECT_EQ(0, m2[0][0]);
    EXPECT_EQ(2, m2[0][1]);
    EXPECT_EQ(4, m2[1][0]);
    EXPECT_EQ(6, m2[1][1]);
    EXPECT_EQ(8, m2[2][0]);
    EXPECT_EQ(10, m2[2][1]);
}

TEST(ScalarMultiplication, MatixWithScalar)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int factor = 2;

    auto m2 = m1 * factor;

    static_assert(std::is_same<decltype(m2), Matrix<3, 2, int>>::value);
    EXPECT_EQ(0, m2[0][0]);
    EXPECT_EQ(2, m2[0][1]);
    EXPECT_EQ(4, m2[1][0]);
    EXPECT_EQ(6, m2[1][1]);
    EXPECT_EQ(8, m2[2][0]);
    EXPECT_EQ(10, m2[2][1]);
}

TEST(ScalarMultiplication, ScalarWithVector)
{
    auto v1 = MakeVector({0, 1, 2});
    int factor = 2;

    auto v2 = factor * v1;

    static_assert(std::is_same<decltype(v2), Vector<3, int>>::value);
    EXPECT_EQ(0, v2[0][0]);
    EXPECT_EQ(2, v2[1][0]);
    EXPECT_EQ(4, v2[2][0]);
}

TEST(ScalarMultiplication, VectorWithScalar)
{
    auto v1 = MakeVector({0, 1, 2});
    int factor = 2;

    auto v2 = v1 * factor;

    static_assert(std::is_same<decltype(v2), Vector<3, int>>::value);
    EXPECT_EQ(0, v2[0][0]);
    EXPECT_EQ(2, v2[1][0]);
    EXPECT_EQ(4, v2[2][0]);
}

TEST(ScalarMultiplication, ScalarWithTransposed)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int factor = 2;

    auto m2 = factor * m1.TransposedView();

    static_assert(std::is_same<decltype(m2), Matrix<2, 3, int>>::value);
    EXPECT_EQ(0, m2[0][0]);
    EXPECT_EQ(4, m2[0][1]);
    EXPECT_EQ(8, m2[0][2]);
    EXPECT_EQ(2, m2[1][0]);
    EXPECT_EQ(6, m2[1][1]);
    EXPECT_EQ(10, m2[1][2]);
}

TEST(ScalarMultiplication, TransposedWithScalar)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int factor = 2;

    auto m2 = m1.TransposedView() * factor;

    static_assert(std::is_same<decltype(m2), Matrix<2, 3, int>>::value);
    EXPECT_EQ(0, m2[0][0]);
    EXPECT_EQ(4, m2[0][1]);
    EXPECT_EQ(8, m2[0][2]);
    EXPECT_EQ(2, m2[1][0]);
    EXPECT_EQ(6, m2[1][1]);
    EXPECT_EQ(10, m2[1][2]);
}

TEST(ScalarMultiplicationAssignment, MatixWithScalarAssignment)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int factor = 2;

    m1 *= factor;

    static_assert(std::is_same<decltype(m1), Matrix<3, 2, int>>::value);
    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(2, m1[0][1]);
    EXPECT_EQ(4, m1[1][0]);
    EXPECT_EQ(6, m1[1][1]);
    EXPECT_EQ(8, m1[2][0]);
    EXPECT_EQ(10, m1[2][1]);
}

TEST(ScalarMultiplicationAssignment, VectorWithScalarAssignment)
{
    auto v1 = MakeVector({0, 1, 2});
    int factor = 2;

    v1 *= factor;

    static_assert(std::is_same<decltype(v1), Vector<3, int>>::value);
    EXPECT_EQ(0, v1[0][0]);
    EXPECT_EQ(2, v1[1][0]);
    EXPECT_EQ(4, v1[2][0]);
}

TEST(ScalarMultiplicationAssignment, TransposedWithScalarAssignment)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int factor = 2;

    m1.TransposedView() *= factor;

    static_assert(std::is_same<decltype(m1), Matrix<3, 2, int>>::value);
    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(2, m1[0][1]);
    EXPECT_EQ(4, m1[1][0]);
    EXPECT_EQ(6, m1[1][1]);
    EXPECT_EQ(8, m1[2][0]);
    EXPECT_EQ(10, m1[2][1]);
}

}  // namespace

}  // namespace silia
