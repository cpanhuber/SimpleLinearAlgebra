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

TEST(ScalarDivision, ScalarWithMatrix)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int denominator = 2;

    auto m2 = denominator / m1;

    static_assert(std::is_same<decltype(m2), Matrix<3, 2, int>>::value, "scalar multiplication type check failed");
    EXPECT_EQ(0, m2[0][0]);
    EXPECT_EQ(0, m2[0][1]);
    EXPECT_EQ(1, m2[1][0]);
    EXPECT_EQ(1, m2[1][1]);
    EXPECT_EQ(2, m2[2][0]);
    EXPECT_EQ(2, m2[2][1]);
}

TEST(ScalarDivision, MatixWithScalar)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int denominator = 2;

    auto m2 = m1 / denominator;

    static_assert(std::is_same<decltype(m2), Matrix<3, 2, int>>::value, "scalar multiplication type check failed");
    EXPECT_EQ(0, m2[0][0]);
    EXPECT_EQ(0, m2[0][1]);
    EXPECT_EQ(1, m2[1][0]);
    EXPECT_EQ(1, m2[1][1]);
    EXPECT_EQ(2, m2[2][0]);
    EXPECT_EQ(2, m2[2][1]);
}

TEST(ScalarDivision, ScalarWithVector)
{
    auto v1 = MakeVector({0, 1, 2});
    int denominator = 2;

    auto v2 = denominator / v1;

    static_assert(std::is_same<decltype(v2), Vector<3, int>>::value, "scalar multiplication type check failed");
    EXPECT_EQ(0, v2[0][0]);
    EXPECT_EQ(0, v2[1][0]);
    EXPECT_EQ(1, v2[2][0]);
}

TEST(ScalarDivision, VectorWithScalar)
{
    auto v1 = MakeVector({0, 1, 2});
    int denominator = 2;

    auto v2 = v1 / denominator;

    static_assert(std::is_same<decltype(v2), Vector<3, int>>::value, "scalar multiplication type check failed");
    EXPECT_EQ(0, v2[0][0]);
    EXPECT_EQ(0, v2[1][0]);
    EXPECT_EQ(1, v2[2][0]);
}

TEST(ScalarDivision, ScalarWithTransposed)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int denominator = 2;

    auto m2 = denominator / m1.TransposedView();

    static_assert(std::is_same<decltype(m2), Matrix<2, 3, int>>::value, "scalar multiplication type check failed");
    EXPECT_EQ(0, m2[0][0]);
    EXPECT_EQ(1, m2[0][1]);
    EXPECT_EQ(2, m2[0][2]);
    EXPECT_EQ(0, m2[1][0]);
    EXPECT_EQ(1, m2[1][1]);
    EXPECT_EQ(2, m2[1][2]);
}

TEST(ScalarDivision, TransposedWithScalar)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int denominator = 2;

    auto m2 = m1.TransposedView() / denominator;

    static_assert(std::is_same<decltype(m2), Matrix<2, 3, int>>::value, "scalar multiplication type check failed");
    EXPECT_EQ(0, m2[0][0]);
    EXPECT_EQ(1, m2[0][1]);
    EXPECT_EQ(2, m2[0][2]);
    EXPECT_EQ(0, m2[1][0]);
    EXPECT_EQ(1, m2[1][1]);
    EXPECT_EQ(2, m2[1][2]);
}
}  // namespace

}  // namespace silia
