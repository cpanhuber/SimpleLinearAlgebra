#include <silia/types/factories.h>
#include <silia/types/types.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <type_traits>

namespace silia
{
namespace
{
using namespace testing;

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
