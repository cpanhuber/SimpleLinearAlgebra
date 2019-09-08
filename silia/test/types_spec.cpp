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

TEST(Types, MakeMatrix)
{
    auto matrix = MakeMatrix<3, 4, double>();
    static_assert(std::is_same<decltype(matrix), Matrix<3, 4, double>>::value);
}

TEST(Types, MakeVector)
{
    auto vector = MakeVector<3, double>();
    static_assert(std::is_same<decltype(vector), Vector<3, double>>::value);
}

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

TEST(Types, MakeMatrixFromArray3x2)
{
    auto matrix = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});

    static_assert(std::is_same<decltype(matrix), Matrix<3, 2, int>>::value);
    EXPECT_EQ(0, matrix[0][0]);
    EXPECT_EQ(1, matrix[0][1]);
    EXPECT_EQ(2, matrix[1][0]);
    EXPECT_EQ(3, matrix[1][1]);
    EXPECT_EQ(4, matrix[2][0]);
    EXPECT_EQ(5, matrix[2][1]);
}

TEST(Types, MakeMatrixFromArray1x2)
{
    auto matrix = MakeMatrix({{3, 2}});

    static_assert(std::is_same<decltype(matrix), Matrix<1, 2, int>>::value);
    EXPECT_EQ(3, matrix[0][0]);
    EXPECT_EQ(2, matrix[0][1]);
}

TEST(Types, MakeVectorFromArray)
{
    auto vector = MakeVector<3, int>({0, 1, 2});

    static_assert(std::is_same<decltype(vector), Vector<3, int>>::value);
    EXPECT_EQ(0, vector[0]);
    EXPECT_EQ(1, vector[1]);
    EXPECT_EQ(2, vector[2]);
}

TEST(Types, Synonym_Matrix4d)
{
    Matrix4d m{};
    static_assert(std::is_same<decltype(m), Matrix<4, 4, double>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix4f)
{
    Matrix4f m{};
    static_assert(std::is_same<decltype(m), Matrix<4, 4, float>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix4i)
{
    Matrix4i m{};
    static_assert(std::is_same<decltype(m), Matrix<4, 4, int>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix3d)
{
    Matrix3d m{};
    static_assert(std::is_same<decltype(m), Matrix<3, 3, double>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix3f)
{
    Matrix3f m{};
    static_assert(std::is_same<decltype(m), Matrix<3, 3, float>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix3i)
{
    Matrix3i m{};
    static_assert(std::is_same<decltype(m), Matrix<3, 3, int>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix2d)
{
    Matrix2d m{};
    static_assert(std::is_same<decltype(m), Matrix<2, 2, double>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix2f)
{
    Matrix2f m{};
    static_assert(std::is_same<decltype(m), Matrix<2, 2, float>>::value);
    SUCCEED();
}
TEST(Types, Synonym_Matrix2i)
{
    Matrix2i m{};
    static_assert(std::is_same<decltype(m), Matrix<2, 2, int>>::value);
    SUCCEED();
}

}  // namespace

}  // namespace silia
