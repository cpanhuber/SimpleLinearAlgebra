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

TEST(Types, CopylessTranspose_WhenMatrix3x2)
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

TEST(Types, CopylessTranspose_WhenMatrix2x3)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    EXPECT_EQ(0, m.TransposedView()[0][0]);
    EXPECT_EQ(3, m.TransposedView()[0][1]);
    EXPECT_EQ(1, m.TransposedView()[1][0]);
    EXPECT_EQ(4, m.TransposedView()[1][1]);
    EXPECT_EQ(2, m.TransposedView()[2][0]);
    EXPECT_EQ(5, m.TransposedView()[2][1]);
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

TEST(Types, RowView_WhenMatrix)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    EXPECT_EQ(3, m.RowView(1)[0]);
    EXPECT_EQ(4, m.RowView(1)[1]);
    EXPECT_EQ(5, m.RowView(1)[2]);
}

TEST(Types, RowView_WhenTransposedView)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    EXPECT_EQ(2, m.TransposedView().RowView(2)[0]);
    EXPECT_EQ(5, m.TransposedView().RowView(2)[1]);

TEST(Types, ColumnView_WhenMatrix)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    auto c = m.ColumnView(1);

    EXPECT_EQ(1, c[0]);
    EXPECT_EQ(4, c[1]);
}

TEST(Types, ColumnView_WhenTransposedView)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    auto t = m.GetTransposedView();
    auto c = t.ColumnView(1);

    EXPECT_EQ(3, c[0]);
    EXPECT_EQ(4, c[1]);
    EXPECT_EQ(5, c[2]);
}

TEST(Types, CopyConstructTransposedToMatrix)
{
    Matrix<2, 3, int> m2 = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    Matrix<3, 2, int> m1 = m2.TransposedView();

    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(3, m1[0][1]);
    EXPECT_EQ(1, m1[1][0]);
    EXPECT_EQ(4, m1[1][1]);
    EXPECT_EQ(2, m1[2][0]);
    EXPECT_EQ(5, m1[2][1]);
}

TEST(Types, CopyAssignTransposedToMatrix)
{
    Matrix<3, 2, int> m1 = MakeMatrix({{0, 0}, {0, 0}, {0, 0}});
    Matrix<2, 3, int> m2 = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    m1 = m2.TransposedView();

    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(3, m1[0][1]);
    EXPECT_EQ(1, m1[1][0]);
    EXPECT_EQ(4, m1[1][1]);
    EXPECT_EQ(2, m1[2][0]);
    EXPECT_EQ(5, m1[2][1]);
}

}  // namespace

}  // namespace silia
