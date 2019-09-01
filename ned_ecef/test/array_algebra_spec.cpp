#include <ned_ecef/algebra/factories.h>
#include <ned_ecef/algebra/operations.h>
#include <ned_ecef/algebra/types.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace ned_ecef
{
namespace algebra
{
namespace
{
using namespace testing;

TEST(Algebra, Matrix_OperatorAt)
{
    auto matrix = MakeMatrix<1, 2, int>();

    matrix[0][0] = 0;
    matrix[0][1] = 1;

    EXPECT_EQ(0, matrix[0][0]);
    EXPECT_EQ(1, matrix[0][1]);
}

}  // namespace

}  // namespace algebra

}  // namespace ned_ecef
