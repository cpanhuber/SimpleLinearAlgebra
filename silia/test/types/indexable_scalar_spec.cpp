#include <silia/types/factories.h>
#include <silia/types/types.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <type_traits>

namespace silia
{
namespace
{

using namespace ::testing;

TEST(IndexableScalar, CastToT_WhenDouble)
{
    Vector3d v = MakeVector({1.0, 2.0, 3.0});

    double d = v[0];

    double tolerance = 1e-9;
    EXPECT_NEAR(1.0, d, tolerance);
}

TEST(IndexableScalar, CastToT_WhenInt)
{
    Vector3i v = MakeVector({1, 2, 3});

    int i = v[0];

    EXPECT_EQ(1, i);
}

TEST(IndexableScalar, AutoCastToT_WhenArithmethic)
{
    Vector3i v = MakeVector({1, 2, 3});
    auto a = v[0];
    auto b = v[1];

    auto c = a + b;

    static_assert(std::is_same<decltype(c), int>::value, "auto cast to value yielded unexpected type");
    EXPECT_EQ(3, c);
}

TEST(IndexableScalar, AutoCastToT_WhenIndex)
{
    Vector3i v = MakeVector({1, 2, 3});
    auto a = v[0];

    auto c = v[a];

    EXPECT_EQ(2, c);
}

}  // namespace
}  // namespace silia
