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

TEST(Norm, SquaredNorm_WhenVector)
{
    auto v = MakeVector({2, 3, 1});

    auto norm = SquaredNorm(v);

    static_assert(std::is_same<decltype(norm), double>::value, "norm type check failed");
    double tolerance = 1e-9;
    EXPECT_NEAR(14.0, norm, tolerance);
}

TEST(Norm, SquaredNormF_WhenVector)
{
    auto v = MakeVector({2, 3, 1});

    auto norm = SquaredNormF(v);

    static_assert(std::is_same<decltype(norm), float>::value, "norm type check failed");
    float tolerance = 1e-7f;
    EXPECT_NEAR(14.0f, norm, tolerance);
}

TEST(Norm, Norm_WhenVector)
{
    auto v = MakeVector({2, 3, 1});

    auto norm = Norm(v);

    static_assert(std::is_same<decltype(norm), double>::value, "norm type check failed");
    double tolerance = 1e-9;
    EXPECT_NEAR(3.7416573868, norm, tolerance);
}

TEST(Norm, NormF_WhenVector)
{
    auto v = MakeVector({2, 3, 1});

    auto norm = NormF(v);

    static_assert(std::is_same<decltype(norm), float>::value, "norm type check failed");
    float tolerance = 1e-7f;
    EXPECT_NEAR(3.7416573868f, norm, tolerance);
}

TEST(Norm, SquaredNorm_WhenMatrix)
{
    auto m = MakeMatrix({{2}, {3}, {1}});

    auto norm = SquaredNorm(m);

    static_assert(std::is_same<decltype(norm), double>::value, "norm type check failed");
    double tolerance = 1e-9;
    EXPECT_NEAR(14.0, norm, tolerance);
}

TEST(Norm, SquaredNormF_WhenMatrix)
{
    auto m = MakeMatrix({{2}, {3}, {1}});

    auto norm = SquaredNormF(m);

    static_assert(std::is_same<decltype(norm), float>::value, "norm type check failed");
    float tolerance = 1e-7f;
    EXPECT_NEAR(14.0f, norm, tolerance);
}

TEST(Norm, Norm_WhenMatrix)
{
    auto m = MakeMatrix({{2}, {3}, {1}});

    auto norm = Norm(m);

    static_assert(std::is_same<decltype(norm), double>::value, "norm type check failed");
    double tolerance = 1e-9;
    EXPECT_NEAR(3.7416573868, norm, tolerance);
}

TEST(Norm, NormF_WhenMatrix)
{
    auto m = MakeMatrix({{2}, {3}, {1}});

    auto norm = NormF(m);

    static_assert(std::is_same<decltype(norm), float>::value, "norm type check failed");
    float tolerance = 1e-7f;
    EXPECT_NEAR(3.7416573868f, norm, tolerance);
}

TEST(Norm, SquaredNorm_WhenTransposedView)
{
    auto m = MakeMatrix({{2, 3, 1}});

    auto norm = SquaredNorm(m.TransposedView());

    static_assert(std::is_same<decltype(norm), double>::value, "norm type check failed");
    double tolerance = 1e-9;
    EXPECT_NEAR(14.0, norm, tolerance);
}

TEST(Norm, SquaredNormF_WhenTransposedView)
{
    auto m = MakeMatrix({{2, 3, 1}});

    auto norm = SquaredNormF(m.TransposedView());

    static_assert(std::is_same<decltype(norm), float>::value, "norm type check failed");
    float tolerance = 1e-7f;
    EXPECT_NEAR(14.0f, norm, tolerance);
}

TEST(Norm, Norm_WhenTransposedView)
{
    auto m = MakeMatrix({{2, 3, 1}});

    auto norm = Norm(m.TransposedView());

    static_assert(std::is_same<decltype(norm), double>::value, "norm type check failed");
    double tolerance = 1e-9;
    EXPECT_NEAR(3.7416573868, norm, tolerance);
}

TEST(Norm, NormF_WhenTransposedView)
{
    auto m = MakeMatrix({{2, 3, 1}});

    auto norm = NormF(m.TransposedView());

    static_assert(std::is_same<decltype(norm), float>::value, "norm type check failed");
    float tolerance = 1e-7f;
    EXPECT_NEAR(3.7416573868f, norm, tolerance);
}

}  // namespace

}  // namespace silia
