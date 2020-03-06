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

    EXPECT_EQ(5, m.GetTransposedView()[0][0]);
    EXPECT_EQ(3, m.GetTransposedView()[0][1]);
    EXPECT_EQ(1, m.GetTransposedView()[0][2]);
    EXPECT_EQ(4, m.GetTransposedView()[1][0]);
    EXPECT_EQ(2, m.GetTransposedView()[1][1]);
    EXPECT_EQ(0, m.GetTransposedView()[1][2]);
    EXPECT_EQ(&(m[0][0]), &(m.GetTransposedView()[0][0]));
}

TEST(Types, CopylessTranspose_WhenMatrix2x3)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    EXPECT_EQ(0, m.GetTransposedView()[0][0]);
    EXPECT_EQ(3, m.GetTransposedView()[0][1]);
    EXPECT_EQ(1, m.GetTransposedView()[1][0]);
    EXPECT_EQ(4, m.GetTransposedView()[1][1]);
    EXPECT_EQ(2, m.GetTransposedView()[2][0]);
    EXPECT_EQ(5, m.GetTransposedView()[2][1]);
    EXPECT_EQ(&(m[0][0]), &(m.GetTransposedView()[0][0]));
}

TEST(Types, CopylessTranspose_WhenVector)
{
    auto v = MakeVector({5, 4, 3});

    EXPECT_EQ(5, v.GetTransposedView()[0][0]);
    EXPECT_EQ(4, v.GetTransposedView()[0][1]);
    EXPECT_EQ(3, v.GetTransposedView()[0][2]);
    EXPECT_EQ(&(v[0][0]), &(v.GetTransposedView()[0][0]));
}

TEST(Types, ChainedCopylessTranspose)
{
    auto m1 = MakeMatrix({{1, 2, 3}, {4, 5, 6}});

    auto m2 = m1.GetTransposedView().GetTransposedView();

    EXPECT_EQ(m1[0][0], m2[0][0]);
    EXPECT_EQ(m1[0][1], m2[0][1]);
    EXPECT_EQ(m1[0][2], m2[0][2]);
    EXPECT_EQ(m1[1][0], m2[1][0]);
    EXPECT_EQ(m1[1][1], m2[1][1]);
    EXPECT_EQ(m1[1][2], m2[1][2]);
}

TEST(Types, ChainedCopylessTranspose_WhenModify)
{
    auto m1 = MakeMatrix({{1, 2, 3}, {4, 5, 6}});
    auto m2 = m1.GetTransposedView().GetTransposedView();

    m2[0][0] = 0;

    EXPECT_EQ(0, m1[0][0]);
}

TEST(Types, RowView_WhenMatrix)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    EXPECT_EQ(3, m.GetRowView(1)[0]);
    EXPECT_EQ(4, m.GetRowView(1)[1]);
    EXPECT_EQ(5, m.GetRowView(1)[2]);
}

TEST(Types, RowView_WhenModify)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    m.GetRowView(1)[1] = 9;

    EXPECT_EQ(9, m[1][1]);
}

TEST(Types, RowView_WhenTransposedView)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    auto r = m.GetTransposedView().GetRowView(2);

    EXPECT_EQ(2, r[0]);
    EXPECT_EQ(5, r[1]);
}

TEST(Types, RowView_WhenChainedWhenModify)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    m.GetTransposedView().GetRowView(0)[1] = 9;

    EXPECT_EQ(9, m[1][0]);
}

TEST(Types, ColumnView_WhenMatrix)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    auto c = m.GetColumnView(1);

    EXPECT_EQ(1, c[0]);
    EXPECT_EQ(4, c[1]);
}

TEST(Types, ColumnView_WhenTransposedView)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    auto c = m.GetTransposedView().GetColumnView(1);

    EXPECT_EQ(3, c[0]);
    EXPECT_EQ(4, c[1]);
    EXPECT_EQ(5, c[2]);
}

TEST(Types, ColumnView_WhenWriteToMatrix)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});
    auto v = MakeVector({9, 10, 11});

    m.GetColumnView(1) = v;

    EXPECT_EQ(0, m[0][0]);
    EXPECT_EQ(9, m[0][1]);
    EXPECT_EQ(2, m[0][2]);
    EXPECT_EQ(3, m[1][0]);
    EXPECT_EQ(10, m[1][1]);
    EXPECT_EQ(5, m[1][2]);
    EXPECT_EQ(6, m[2][0]);
    EXPECT_EQ(11, m[2][1]);
    EXPECT_EQ(8, m[2][2]);
}

TEST(Types, ColumnView_WhenWriteDiagonalView)
{
    auto m1 = MakeMatrix({{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});
    auto m2 = MakeMatrix({{10, 11, 12}, {13, 14, 15}, {16, 17, 18}});

    m1.GetColumnView(0) = m2.GetDiagonalView();

    EXPECT_EQ(10, m1[0][0]);
    EXPECT_EQ(1, m1[0][1]);
    EXPECT_EQ(2, m1[0][2]);
    EXPECT_EQ(14, m1[1][0]);
    EXPECT_EQ(4, m1[1][1]);
    EXPECT_EQ(5, m1[1][2]);
    EXPECT_EQ(18, m1[2][0]);
    EXPECT_EQ(7, m1[2][1]);
    EXPECT_EQ(8, m1[2][2]);
}

TEST(Types, DiagonalView_WhenMatrix)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});

    auto c = m.GetDiagonalView();

    EXPECT_EQ(0, c[0]);
    EXPECT_EQ(4, c[1]);
    EXPECT_EQ(8, c[2]);
}

TEST(Types, DiagonalView_WhenTransposedView)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});

    auto c = m.GetTransposedView().GetDiagonalView();

    EXPECT_EQ(0, c[0]);
    EXPECT_EQ(4, c[1]);
    EXPECT_EQ(8, c[2]);
}

TEST(Types, DiagonalView_WhenModify)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});

    m.GetTransposedView().GetDiagonalView()[1] = 9;

    EXPECT_EQ(9, m[1][1]);
}

TEST(Types, DiagonalView_WhenWriteToMatrix)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});

    auto v = MakeVector({9, 10, 11});
    m.GetDiagonalView()[0] = 1;
    m.GetDiagonalView() = v;

    EXPECT_EQ(9, m[0][0]);
    EXPECT_EQ(1, m[0][1]);
    EXPECT_EQ(2, m[0][2]);
    EXPECT_EQ(3, m[1][0]);
    EXPECT_EQ(10, m[1][1]);
    EXPECT_EQ(5, m[1][2]);
    EXPECT_EQ(6, m[2][0]);
    EXPECT_EQ(7, m[2][1]);
    EXPECT_EQ(11, m[2][2]);
}

TEST(Types, DiagonalView_WhenWriteToTransposed)
{
    auto m = MakeMatrix({{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});
    auto v = MakeVector({9, 10, 11});

    m.GetTransposedView().GetDiagonalView() = v;

    EXPECT_EQ(9, m[0][0]);
    EXPECT_EQ(1, m[0][1]);
    EXPECT_EQ(2, m[0][2]);
    EXPECT_EQ(3, m[1][0]);
    EXPECT_EQ(10, m[1][1]);
    EXPECT_EQ(5, m[1][2]);
    EXPECT_EQ(6, m[2][0]);
    EXPECT_EQ(7, m[2][1]);
    EXPECT_EQ(11, m[2][2]);
}

TEST(Types, CopyConstructTransposedToMatrix)
{
    Matrix<2, 3, int> m2 = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    Matrix<3, 2, int> m1 = m2.GetTransposedView();

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

    m1 = m2.GetTransposedView();

    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(3, m1[0][1]);
    EXPECT_EQ(1, m1[1][0]);
    EXPECT_EQ(4, m1[1][1]);
    EXPECT_EQ(2, m1[2][0]);
    EXPECT_EQ(5, m1[2][1]);
}

TEST(Types, IsView)
{
    auto m = MakeMatrix({{0, 1}});
    auto v = MakeVector({0, 1});
    auto t = m.GetTransposedView();
    auto c = m.GetColumnView(1);
    auto r = m.GetRowView(0);
    auto d = m.GetDiagonalView();

    EXPECT_FALSE(m.IsView());
    EXPECT_FALSE(v.IsView());
    EXPECT_TRUE(t.IsView());
    EXPECT_TRUE(c.IsView());
    EXPECT_TRUE(r.IsView());
    EXPECT_TRUE(d.IsView());
}

}  // namespace

}  // namespace silia
