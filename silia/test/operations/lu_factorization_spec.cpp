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

TEST(LUFactorization, RowSwap)
{
    auto m = MakeMatrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    detail::RowSwap(m, 1, 2);

    EXPECT_EQ(1, m[0][0]);
    EXPECT_EQ(2, m[0][1]);
    EXPECT_EQ(3, m[0][2]);
    EXPECT_EQ(7, m[1][0]);
    EXPECT_EQ(8, m[1][1]);
    EXPECT_EQ(9, m[1][2]);
    EXPECT_EQ(4, m[2][0]);
    EXPECT_EQ(5, m[2][1]);
    EXPECT_EQ(6, m[2][2]);
}

}  // namespace

}  // namespace silia
