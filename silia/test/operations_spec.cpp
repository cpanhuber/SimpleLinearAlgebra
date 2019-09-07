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

}  // namespace

}  // namespace silia
