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

TEST(CrossProduct, CrossProduct_WhenMatrixMatrix)
{
    auto m1 = MakeMatrix({{1}, {0}, {3}});
    auto m2 = MakeMatrix({{4}, {2}, {6}});

    auto v = Cross(m1, m2);

    static_assert(std::is_same<decltype(v), Vector<3, int>>::value, "Cross product type check failed");
    EXPECT_EQ(-6, v[0]);
    EXPECT_EQ(6, v[1]);
    EXPECT_EQ(2, v[2]);
}

TEST(CrossProduct, CrossProduct_WhenVectorMatrix)
{
    auto v1 = MakeVector({1, 0, 3});
    auto m = MakeMatrix({{4}, {2}, {6}});

    auto v2 = Cross(v1, m);

    static_assert(std::is_same<decltype(v2), Vector<3, int>>::value, "Cross product type check failed");
    EXPECT_EQ(-6, v2[0]);
    EXPECT_EQ(6, v2[1]);
    EXPECT_EQ(2, v2[2]);
}

TEST(CrossProduct, CrossProduct_WhenMatrixVector)
{
    auto m = MakeMatrix({{1}, {0}, {3}});
    auto v1 = MakeVector({4, 2, 6});

    auto v2 = Cross(m, v1);

    static_assert(std::is_same<decltype(v2), Vector<3, int>>::value, "Cross product type check failed");
    EXPECT_EQ(-6, v2[0]);
    EXPECT_EQ(6, v2[1]);
    EXPECT_EQ(2, v2[2]);
}

TEST(CrossProduct, CrossProduct_WhenVectorVector)
{
    auto v1 = MakeVector({1, 0, 3});
    auto v2 = MakeVector({4, 2, 6});

    auto v3 = Cross(v1, v2);

    static_assert(std::is_same<decltype(v3), Vector<3, int>>::value, "Cross product type check failed");
    EXPECT_EQ(-6, v3[0]);
    EXPECT_EQ(6, v3[1]);
    EXPECT_EQ(2, v3[2]);
}

TEST(CrossProduct, CrossProduct_WhenTransposedViewLeft)
{
    auto m1 = MakeMatrix({{1, 0, 3}});
    auto m2 = MakeMatrix({{4}, {2}, {6}});

    auto v = Cross(m1.GetTransposedView(), m2);

    static_assert(std::is_same<decltype(v), Vector<3, int>>::value, "Cross product type check failed");
    EXPECT_EQ(-6, v[0]);
    EXPECT_EQ(6, v[1]);
    EXPECT_EQ(2, v[2]);
}  // namespace

TEST(CrossProduct, CrossProduct_WhenTransposedViewRight)
{
    auto m1 = MakeMatrix({{1}, {0}, {3}});
    auto m2 = MakeMatrix({{4, 2, 6}});

    auto v = Cross(m1, m2.GetTransposedView());

    static_assert(std::is_same<decltype(v), Vector<3, int>>::value, "Cross product type check failed");
    EXPECT_EQ(-6, v[0]);
    EXPECT_EQ(6, v[1]);
    EXPECT_EQ(2, v[2]);
}

TEST(CrossProduct, CrossProduct_WhenTransposedViewLeftVectorRight)
{
    auto m = MakeMatrix({{1, 0, 3}});
    auto v1 = MakeVector({4, 2, 6});

    auto v2 = Cross(m.GetTransposedView(), v1);

    static_assert(std::is_same<decltype(v2), Vector<3, int>>::value, "Cross product type check failed");
    EXPECT_EQ(-6, v2[0]);
    EXPECT_EQ(6, v2[1]);
    EXPECT_EQ(2, v2[2]);
}

TEST(CrossProduct, CrossProduct_WhenVectorLeftTransposedViewRight)
{
    auto v1 = MakeVector({1, 0, 3});
    auto m = MakeMatrix({{4, 2, 6}});

    auto v2 = Cross(v1, m.GetTransposedView());

    static_assert(std::is_same<decltype(v2), Vector<3, int>>::value, "Cross product type check failed");
    EXPECT_EQ(-6, v2[0]);
    EXPECT_EQ(6, v2[1]);
    EXPECT_EQ(2, v2[2]);
}

}  // namespace

}  // namespace silia
