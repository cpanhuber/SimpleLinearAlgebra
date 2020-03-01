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

TEST(ScalarAddition, ScalarWithMatrix)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int summand = 2;

    auto m2 = summand + m1;

    static_assert(std::is_same<decltype(m2), Matrix<3, 2, int>>::value, "scalar addition type check failed");
    EXPECT_EQ(2, m2[0][0]);
    EXPECT_EQ(3, m2[0][1]);
    EXPECT_EQ(4, m2[1][0]);
    EXPECT_EQ(5, m2[1][1]);
    EXPECT_EQ(6, m2[2][0]);
    EXPECT_EQ(7, m2[2][1]);
}

TEST(ScalarAddition, MatixWithScalar)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int summand = 2;

    auto m2 = m1 + summand;

    static_assert(std::is_same<decltype(m2), Matrix<3, 2, int>>::value, "scalar addition type check failed");
    EXPECT_EQ(2, m2[0][0]);
    EXPECT_EQ(3, m2[0][1]);
    EXPECT_EQ(4, m2[1][0]);
    EXPECT_EQ(5, m2[1][1]);
    EXPECT_EQ(6, m2[2][0]);
    EXPECT_EQ(7, m2[2][1]);
}

TEST(ScalarAddition, ScalarWithVector)
{
    auto v1 = MakeVector({0, 1, 2});
    int summand = 2;

    auto v2 = summand + v1;

    static_assert(std::is_same<decltype(v2), Vector<3, int>>::value, "scalar addition type check failed");
    EXPECT_EQ(2, v2[0][0]);
    EXPECT_EQ(3, v2[1][0]);
    EXPECT_EQ(4, v2[2][0]);
}

TEST(ScalarAddition, VectorWithScalar)
{
    auto v1 = MakeVector({0, 1, 2});
    int summand = 2;

    auto v2 = v1 + summand;

    static_assert(std::is_same<decltype(v2), Vector<3, int>>::value, "scalar addition type check failed");
    EXPECT_EQ(2, v2[0][0]);
    EXPECT_EQ(3, v2[1][0]);
    EXPECT_EQ(4, v2[2][0]);
}

TEST(ScalarAddition, ScalarWithTransposed)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int summand = 2;

    auto m2 = summand + m1.TransposedView();

    static_assert(std::is_same<decltype(m2), Matrix<2, 3, int>>::value, "scalar addition type check failed");
    EXPECT_EQ(2, m2[0][0]);
    EXPECT_EQ(4, m2[0][1]);
    EXPECT_EQ(6, m2[0][2]);
    EXPECT_EQ(3, m2[1][0]);
    EXPECT_EQ(5, m2[1][1]);
    EXPECT_EQ(7, m2[1][2]);
}

TEST(ScalarAddition, TransposedWithScalar)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int summand = 2;

    auto m2 = m1.TransposedView() + summand;

    static_assert(std::is_same<decltype(m2), Matrix<2, 3, int>>::value, "scalar addition type check failed");
    EXPECT_EQ(2, m2[0][0]);
    EXPECT_EQ(4, m2[0][1]);
    EXPECT_EQ(6, m2[0][2]);
    EXPECT_EQ(3, m2[1][0]);
    EXPECT_EQ(5, m2[1][1]);
    EXPECT_EQ(7, m2[1][2]);
}
}  // namespace

}  // namespace silia
