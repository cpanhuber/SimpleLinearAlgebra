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

TEST(Unit, Unit_WhenVector)
{
    auto v = MakeVector({6, 9, 2});

    auto unit = Unit(v);

    static_assert(std::is_same<decltype(unit), Vector<3, double>>::value, "unit type check failed");
    double tolerance = 1e-9;
    EXPECT_NEAR(6.0 / 11.0, unit[0], tolerance);
    EXPECT_NEAR(9.0 / 11.0, unit[1], tolerance);
    EXPECT_NEAR(2.0 / 11.0, unit[2], tolerance);
}

TEST(Unit, UnitF_WhenVector)
{
    auto v = MakeVector({6, 9, 2});

    auto unit = UnitF(v);

    static_assert(std::is_same<decltype(unit), Vector<3, float>>::value, "unit type check failed");
    float tolerance = 1e-7;
    EXPECT_NEAR(6.0f / 11.0f, unit[0], tolerance);
    EXPECT_NEAR(9.0f / 11.0f, unit[1], tolerance);
    EXPECT_NEAR(2.0f / 11.0f, unit[2], tolerance);
}

TEST(Unit, Unit_WhenMatrix)
{
    auto m = MakeMatrix({{6}, {9}, {2}});

    auto unit = Unit(m);

    static_assert(std::is_same<decltype(unit), Vector<3, double>>::value, "unit type check failed");
    double tolerance = 1e-9;
    EXPECT_NEAR(6.0 / 11.0, unit[0], tolerance);
    EXPECT_NEAR(9.0 / 11.0, unit[1], tolerance);
    EXPECT_NEAR(2.0 / 11.0, unit[2], tolerance);
}

TEST(Unit, UnitF_WhenMatrix)
{
    auto m = MakeMatrix({{6}, {9}, {2}});

    auto unit = UnitF(m);

    static_assert(std::is_same<decltype(unit), Vector<3, float>>::value, "unit type check failed");
    float tolerance = 1e-7;
    EXPECT_NEAR(6.0f / 11.0f, unit[0], tolerance);
    EXPECT_NEAR(9.0f / 11.0f, unit[1], tolerance);
    EXPECT_NEAR(2.0f / 11.0f, unit[2], tolerance);
}

TEST(Unit, Unit_WhenTransposedView)
{
    auto m = MakeMatrix({{6, 9, 2}});

    auto unit = Unit(m.TransposedView());

    static_assert(std::is_same<decltype(unit), Vector<3, double>>::value, "unit type check failed");
    double tolerance = 1e-9;
    EXPECT_NEAR(6.0 / 11.0, unit[0], tolerance);
    EXPECT_NEAR(9.0 / 11.0, unit[1], tolerance);
    EXPECT_NEAR(2.0 / 11.0, unit[2], tolerance);
}

TEST(Unit, UnitF_WhenTransposedView)
{
    auto m = MakeMatrix({{6, 9, 2}});

    auto unit = UnitF(m.TransposedView());

    static_assert(std::is_same<decltype(unit), Vector<3, float>>::value, "unit type check failed");
    float tolerance = 1e-7;
    EXPECT_NEAR(6.0f / 11.0f, unit[0], tolerance);
    EXPECT_NEAR(9.0f / 11.0f, unit[1], tolerance);
    EXPECT_NEAR(2.0f / 11.0f, unit[2], tolerance);
}

}  // namespace

}  // namespace silia
