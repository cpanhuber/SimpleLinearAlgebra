#include <silia/types/factories.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <type_traits>

namespace silia
{
namespace
{
using namespace testing;

TEST(Factories, MakeMatrix)
{
    auto matrix = MakeMatrix<3, 4, double>();
    static_assert(std::is_same<decltype(matrix), Matrix<3, 4, double>>::value);
}

TEST(Factories, MakeVector)
{
    auto vector = MakeVector<3, double>();
    static_assert(std::is_same<decltype(vector), Vector<3, double>>::value);
}

TEST(Factories, MakeMatrixFromArray3x2)
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

TEST(Factories, MakeMatrixFromArray1x2)
{
    auto matrix = MakeMatrix({{3, 2}});

    static_assert(std::is_same<decltype(matrix), Matrix<1, 2, int>>::value);
    EXPECT_EQ(3, matrix[0][0]);
    EXPECT_EQ(2, matrix[0][1]);
}

TEST(Factories, MakeVectorFromArray)
{
    auto vector = MakeVector<3, int>({0, 1, 2});

    static_assert(std::is_same<decltype(vector), Vector<3, int>>::value);
    EXPECT_EQ(0, vector[0]);
    EXPECT_EQ(1, vector[1]);
    EXPECT_EQ(2, vector[2]);
}

}  // namespace

}  // namespace silia
