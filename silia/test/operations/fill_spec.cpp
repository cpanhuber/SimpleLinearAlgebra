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

TEST(Fill, Fill_WhenMatrix)
{
    auto m = Matrix<3, 2, int>{};

    Fill(m, 1);

    EXPECT_EQ(1, m[0][0]);
    EXPECT_EQ(1, m[1][0]);
    EXPECT_EQ(1, m[2][0]);
    EXPECT_EQ(1, m[0][1]);
    EXPECT_EQ(1, m[1][1]);
    EXPECT_EQ(1, m[2][1]);
}

TEST(Fill, Fill_WhenVector)
{
    auto v = Vector<3, int>{};

    Fill(v, 1);

    EXPECT_EQ(1, v[0]);
    EXPECT_EQ(1, v[1]);
    EXPECT_EQ(1, v[2]);
}

TEST(Fill, Fill_WhenTransposedView)
{
    auto v = Vector<3, int>{};

    Fill(v.TransposedView(), 1);

    EXPECT_EQ(1, v[0]);
    EXPECT_EQ(1, v[1]);
    EXPECT_EQ(1, v[2]);
}

TEST(Fill, FillIdentity_WhenMatrix)
{
    auto m = Matrix<2, 2, int>{};

    FillIdentity(m);

    EXPECT_EQ(1, m[0][0]);
    EXPECT_EQ(0, m[1][0]);
    EXPECT_EQ(0, m[0][1]);
    EXPECT_EQ(1, m[1][1]);
}

TEST(Fill, FillIdentity_WhenTransposedView)
{
    auto m = Matrix<2, 2, int>{};

    FillIdentity(m.TransposedView());

    EXPECT_EQ(1, m[0][0]);
    EXPECT_EQ(0, m[1][0]);
    EXPECT_EQ(0, m[0][1]);
    EXPECT_EQ(1, m[1][1]);
}

}  // namespace

}  // namespace silia
