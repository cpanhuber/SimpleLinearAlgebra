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

TEST(Types, Matrix_OperatorAt)
{
    auto matrix = MakeMatrix<1, 2, int>();

    matrix[0][0] = 0;
    matrix[0][1] = 1;

    EXPECT_EQ(0, matrix[0][0]);
    EXPECT_EQ(1, matrix[0][1]);
}

TEST(Types, Vector_OperatorAt)
{
    auto vector = MakeVector<2, int>();

    vector[0] = 0;
    vector[1] = 1;

    EXPECT_EQ(0, vector[0]);
    EXPECT_EQ(1, vector[1]);
}

}  // namespace

}  // namespace silia
