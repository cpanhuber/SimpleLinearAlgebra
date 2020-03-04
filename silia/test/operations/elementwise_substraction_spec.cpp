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

TEST(ElementwiseSubstraction, ElementwiseSubstraction_WhenMatrixMatrix)
{
    auto m1 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});
    auto m2 = MakeMatrix({{0, 1}, {2, 3}, {4, 5}});

    auto m3 = m1 - m2;

    static_assert(std::is_same<decltype(m3), Matrix<3, 2, int>>::value, "matrix addition type check failed");
    EXPECT_EQ(0, m3[0][0]);
    EXPECT_EQ(0, m3[0][1]);
    EXPECT_EQ(0, m3[1][0]);
    EXPECT_EQ(0, m3[1][1]);
    EXPECT_EQ(0, m3[2][0]);
    EXPECT_EQ(0, m3[2][1]);
}

TEST(ElementwiseSubstraction, ElementwiseSubstraction_WhenVectorMatrix)
{
    Vector2i v1 = MakeVector({2, 1});
    auto m = MakeMatrix({{3}, {4}});

    auto v2 = v1 - m;

    static_assert(std::is_same<decltype(v2), Vector<2, int>>::value, "matrix addition type check failed");
    EXPECT_EQ(-1, v2[0]);
    EXPECT_EQ(-3, v2[1]);
}

TEST(ElementwiseSubstraction, ElementwiseSubstraction_WhenMatrixVector)
{
    Vector2i v = MakeVector({2, 1});
    auto m1 = MakeMatrix({{3}, {4}});

    auto m2 = m1 - v;

    static_assert(std::is_same<decltype(m2), Matrix<2, 1, int>>::value, "matrix addition type check failed");
    EXPECT_EQ(1, m2[0][0]);
    EXPECT_EQ(3, m2[1][0]);
}

TEST(ElementwiseSubstraction, ElementwiseSubstraction_WhenVectorVector)
{
    Vector3i v1 = MakeVector({2, 2, 1});
    Vector3i v2 = MakeVector({3, 4, 0});

    auto v3 = v1 - v2;

    static_assert(std::is_same<decltype(v3), Vector<3, int>>::value, "vector addition type check failed");
    EXPECT_EQ(-1, v3[0]);
    EXPECT_EQ(-2, v3[1]);
    EXPECT_EQ(1, v3[2]);
}

TEST(ElementwiseSubstraction, ElementwiseSubstraction_WhenTransposedViewLeft)
{
    auto m1 = MakeMatrix({{5, 4}, {3, 2}});
    auto m2 = MakeMatrix({{0, 1}, {2, 3}});

    auto m3 = m1.GetTransposedView() - m2;
    EXPECT_EQ(5, m3[0][0]);
    EXPECT_EQ(2, m3[0][1]);
    EXPECT_EQ(2, m3[1][0]);
    EXPECT_EQ(-1, m3[1][1]);
}

TEST(ElementwiseSubstraction, ElementwiseSubstraction_WhenTransposedViewRight)
{
    auto m1 = MakeMatrix({{5, 4}, {3, 2}});
    auto m2 = MakeMatrix({{0, 1}, {2, 3}});

    auto m3 = m2 - m1.GetTransposedView();
    EXPECT_EQ(-5, m3[0][0]);
    EXPECT_EQ(-2, m3[0][1]);
    EXPECT_EQ(-2, m3[1][0]);
    EXPECT_EQ(1, m3[1][1]);
}

TEST(ElementwiseSubstraction, ElementwiseSubstraction_WhenTransposedViewLeftVectorRight)
{
    auto m1 = MakeMatrix({{5, 2, 0}});
    auto v = MakeVector({0, 1, 2});

    auto m2 = m1.GetTransposedView() - v;

    static_assert(std::is_same<decltype(m2), Matrix<3, 1, int>>::value, "Matrix addition type check failed");
    EXPECT_EQ(5, m2[0][0]);
    EXPECT_EQ(1, m2[1][0]);
    EXPECT_EQ(-2, m2[2][0]);
}

TEST(ElementwiseSubstraction, ElementwiseSubstraction_WhenTransposedViewRightVectorLeft)
{
    auto m = MakeMatrix({{5, 2, 0}});
    auto v1 = MakeVector({0, 1, 2});

    auto v2 = v1 - m.GetTransposedView();

    static_assert(std::is_same<decltype(v2), Vector<3, int>>::value, "Matrix addition type check failed");
    EXPECT_EQ(-5, v2[0]);
    EXPECT_EQ(-1, v2[1]);
    EXPECT_EQ(2, v2[2]);
}

}  // namespace

}  // namespace silia
