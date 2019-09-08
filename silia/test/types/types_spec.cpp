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

TEST(Types, CopylessTranspose_WhenMatrix)
{
    auto m = MakeMatrix({{5, 4}, {3, 2}, {1, 0}});

    EXPECT_EQ(5, m.TransposedView()[0][0]);
    EXPECT_EQ(3, m.TransposedView()[0][1]);
    EXPECT_EQ(1, m.TransposedView()[0][2]);
    EXPECT_EQ(4, m.TransposedView()[1][0]);
    EXPECT_EQ(2, m.TransposedView()[1][1]);
    EXPECT_EQ(0, m.TransposedView()[1][2]);
    EXPECT_EQ(&(m[0][0]), &(m.TransposedView()[0][0]));
}

TEST(Types, CopylessTranspose_WhenVector)
{
    auto v = MakeVector({5, 4, 3});

    EXPECT_EQ(5, v.TransposedView()[0][0]);
    EXPECT_EQ(4, v.TransposedView()[0][1]);
    EXPECT_EQ(3, v.TransposedView()[0][2]);
    EXPECT_EQ(&(v[0][0]), &(v.TransposedView()[0][0]));
}

}  // namespace

}  // namespace silia
