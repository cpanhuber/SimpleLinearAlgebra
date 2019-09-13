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

    static_assert(std::is_same<decltype(m1), Matrix<3, 2, int>>::value, "scalar multiplication type check failed");
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

    static_assert(std::is_same<decltype(v1), Vector<3, int>>::value, "scalar multiplication type check failed");
    EXPECT_EQ(0, v1[0][0]);
    EXPECT_EQ(2, v1[1][0]);
    EXPECT_EQ(4, v1[2][0]);
}

TEST(ScalarMultiplicationAssignment, TransposedWithScalarAssignment)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    int factor = 2;

    m1.TransposedView() *= factor;

    static_assert(std::is_same<decltype(m1), Matrix<3, 2, int>>::value, "scalar multiplication type check failed");
    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(2, m1[0][1]);
    EXPECT_EQ(4, m1[1][0]);
    EXPECT_EQ(6, m1[1][1]);
    EXPECT_EQ(8, m1[2][0]);
    EXPECT_EQ(10, m1[2][1]);
}

TEST(MatrixAdditionAssignment, MatrixWithMatrix)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    auto m2 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});

    m1 += m2;

    static_assert(std::is_same<decltype(m1), Matrix<3, 2, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(2, m1[0][1]);
    EXPECT_EQ(4, m1[1][0]);
    EXPECT_EQ(6, m1[1][1]);
    EXPECT_EQ(8, m1[2][0]);
    EXPECT_EQ(10, m1[2][1]);
}

TEST(MatrixAdditionAssignment, MatrixWithVector)
{
    auto m = MakeMatrix({{0}, {2}, {4}});
    auto v = MakeVector({1, 2, 3});

    m += v;

    static_assert(std::is_same<decltype(m), Matrix<3, 1, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(1, m[0][0]);
    EXPECT_EQ(4, m[1][0]);
    EXPECT_EQ(7, m[2][0]);
}

TEST(MatrixAdditionAssignment, MatrixWithTransposed)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    auto m2 = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    m1 += m2.TransposedView();

    static_assert(std::is_same<decltype(m1), Matrix<3, 2, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(4, m1[0][1]);
    EXPECT_EQ(3, m1[1][0]);
    EXPECT_EQ(7, m1[1][1]);
    EXPECT_EQ(6, m1[2][0]);
    EXPECT_EQ(10, m1[2][1]);
}

TEST(MatrixAdditionAssignment, VectorWithMatrix)
{
    auto m = MakeMatrix({{0}, {2}, {4}});
    auto v = MakeVector({1, 2, 3});

    v += m;

    static_assert(std::is_same<decltype(v), Vector<3, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(1, v[0][0]);
    EXPECT_EQ(4, v[1][0]);
    EXPECT_EQ(7, v[2][0]);
}

TEST(MatrixAdditionAssignment, VectorWithVector)
{
    auto v1 = MakeVector({1, 2, 3});
    auto v2 = MakeVector({1, 2, 3});

    v1 += v2;

    static_assert(std::is_same<decltype(v1), Vector<3, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(2, v1[0][0]);
    EXPECT_EQ(4, v1[1][0]);
    EXPECT_EQ(6, v1[2][0]);
}

TEST(MatrixAdditionAssignment, VectorWithTransposed)
{
    auto v = MakeVector({1, 2, 3});
    auto m = MakeMatrix({{1, 2, 3}});

    v += m.TransposedView();

    static_assert(std::is_same<decltype(v), Vector<3, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(2, v[0][0]);
    EXPECT_EQ(4, v[1][0]);
    EXPECT_EQ(6, v[2][0]);
}

TEST(MatrixAdditionAssignment, TransposedWithMatrix)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    auto m2 = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    m1.TransposedView() += m2;

    static_assert(std::is_same<decltype(m1), Matrix<3, 2, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(4, m1[0][1]);
    EXPECT_EQ(3, m1[1][0]);
    EXPECT_EQ(7, m1[1][1]);
    EXPECT_EQ(6, m1[2][0]);
    EXPECT_EQ(10, m1[2][1]);
}

TEST(MatrixAdditionAssignment, TransposedWithVector)
{
    auto m = MakeMatrix({{1, 2, 3}});
    auto v = MakeVector({1, 2, 3});

    m.TransposedView() += v;

    static_assert(std::is_same<decltype(m), Matrix<1, 3, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(2, m[0][0]);
    EXPECT_EQ(4, m[0][1]);
    EXPECT_EQ(6, m[0][2]);
}

TEST(MatrixAdditionAssignment, TransposedWithTransposed)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    auto m2 = MakeMatrix({{0, 3}, {1, 4}, {2, 5}});

    m1.TransposedView() += m2.TransposedView();

    static_assert(std::is_same<decltype(m1), Matrix<3, 2, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(4, m1[0][1]);
    EXPECT_EQ(3, m1[1][0]);
    EXPECT_EQ(7, m1[1][1]);
    EXPECT_EQ(6, m1[2][0]);
    EXPECT_EQ(10, m1[2][1]);
}

TEST(MatrixSubstractionAssignment, MatrixWithMatrix)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    auto m2 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});

    m1 -= m2;

    static_assert(std::is_same<decltype(m1), Matrix<3, 2, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(0, m1[0][1]);
    EXPECT_EQ(0, m1[1][0]);
    EXPECT_EQ(0, m1[1][1]);
    EXPECT_EQ(0, m1[2][0]);
    EXPECT_EQ(0, m1[2][1]);
}

TEST(MatrixSubstractionAssignment, MatrixWithVector)
{
    auto m = MakeMatrix({{0}, {2}, {4}});
    auto v = MakeVector({1, 2, 3});

    m -= v;

    static_assert(std::is_same<decltype(m), Matrix<3, 1, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(-1, m[0][0]);
    EXPECT_EQ(0, m[1][0]);
    EXPECT_EQ(1, m[2][0]);
}

TEST(MatrixSubstractionAssignment, MatrixWithTransposed)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    auto m2 = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    m1 -= m2.TransposedView();

    static_assert(std::is_same<decltype(m1), Matrix<3, 2, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(-2, m1[0][1]);
    EXPECT_EQ(1, m1[1][0]);
    EXPECT_EQ(-1, m1[1][1]);
    EXPECT_EQ(2, m1[2][0]);
    EXPECT_EQ(0, m1[2][1]);
}

TEST(MatrixSubstractionAssignment, VectorWithMatrix)
{
    auto v = MakeVector({1, 2, 3});
    auto m = MakeMatrix({{0}, {2}, {4}});

    v -= m;

    static_assert(std::is_same<decltype(v), Vector<3, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(1, v[0][0]);
    EXPECT_EQ(0, v[1][0]);
    EXPECT_EQ(-1, v[2][0]);
}

TEST(MatrixSubstractionAssignment, VectorWithVector)
{
    auto v1 = MakeVector({1, 2, 3});
    auto v2 = MakeVector({1, 2, 3});

    v1 -= v2;

    static_assert(std::is_same<decltype(v1), Vector<3, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(0, v1[0][0]);
    EXPECT_EQ(0, v1[1][0]);
    EXPECT_EQ(0, v1[2][0]);
}

TEST(MatrixSubstractionAssignment, VectorWithTransposed)
{
    auto v = MakeVector({1, 2, 3});
    auto m = MakeMatrix({{1, 2, 3}});

    v -= m.TransposedView();

    static_assert(std::is_same<decltype(v), Vector<3, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(0, v[0][0]);
    EXPECT_EQ(0, v[1][0]);
    EXPECT_EQ(0, v[2][0]);
}

TEST(MatrixSubstractionAssignment, TransposedWithMatrix)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    auto m2 = MakeMatrix({{0, 1, 2}, {3, 4, 5}});

    m1.TransposedView() -= m2;

    static_assert(std::is_same<decltype(m1), Matrix<3, 2, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(-2, m1[0][1]);
    EXPECT_EQ(1, m1[1][0]);
    EXPECT_EQ(-1, m1[1][1]);
    EXPECT_EQ(2, m1[2][0]);
    EXPECT_EQ(0, m1[2][1]);
}

TEST(MatrixSubstractionAssignment, TransposedWithVector)
{
    auto m = MakeMatrix({{1, 2, 3}});
    auto v = MakeVector({1, 2, 3});

    m.TransposedView() -= v;

    static_assert(std::is_same<decltype(m), Matrix<1, 3, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(0, m[0][0]);
    EXPECT_EQ(0, m[0][1]);
    EXPECT_EQ(0, m[0][2]);
}

TEST(MatrixSubstractionAssignment, TransposedWithTransposed)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    auto m2 = MakeMatrix({{0, 3}, {1, 4}, {2, 5}});

    m1.TransposedView() -= m2.TransposedView();

    static_assert(std::is_same<decltype(m1), Matrix<3, 2, int>>::value, "addition assignment type check failed");
    EXPECT_EQ(0, m1[0][0]);
    EXPECT_EQ(-2, m1[0][1]);
    EXPECT_EQ(1, m1[1][0]);
    EXPECT_EQ(-1, m1[1][1]);
    EXPECT_EQ(2, m1[2][0]);
    EXPECT_EQ(0, m1[2][1]);
}

}  // namespace

}  // namespace silia
