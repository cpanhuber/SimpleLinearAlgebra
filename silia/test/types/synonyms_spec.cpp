#include <silia/types/types.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <type_traits>

namespace silia
{
namespace
{
using namespace testing;

TEST(Synonyms, Synonym_Matrix4d)
{
    Matrix4d m{};
    static_assert(std::is_same<decltype(m), Matrix<4, 4, double>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Matrix4f)
{
    Matrix4f m{};
    static_assert(std::is_same<decltype(m), Matrix<4, 4, float>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Matrix4i)
{
    Matrix4i m{};
    static_assert(std::is_same<decltype(m), Matrix<4, 4, int>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Matrix3d)
{
    Matrix3d m{};
    static_assert(std::is_same<decltype(m), Matrix<3, 3, double>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Matrix3f)
{
    Matrix3f m{};
    static_assert(std::is_same<decltype(m), Matrix<3, 3, float>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Matrix3i)
{
    Matrix3i m{};
    static_assert(std::is_same<decltype(m), Matrix<3, 3, int>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Matrix2d)
{
    Matrix2d m{};
    static_assert(std::is_same<decltype(m), Matrix<2, 2, double>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Matrix2f)
{
    Matrix2f m{};
    static_assert(std::is_same<decltype(m), Matrix<2, 2, float>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Matrix2i)
{
    Matrix2i m{};
    static_assert(std::is_same<decltype(m), Matrix<2, 2, int>>::value, "synonym yielded unexpected type");
    SUCCEED();
}

TEST(Synonyms, Synonym_Vector4d)
{
    Vector4d m{};
    static_assert(std::is_same<decltype(m), Vector<4, double>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Vector4f)
{
    Vector4f m{};
    static_assert(std::is_same<decltype(m), Vector<4, float>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Vector4i)
{
    Vector4i m{};
    static_assert(std::is_same<decltype(m), Vector<4, int>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Vector3d)
{
    Vector3d m{};
    static_assert(std::is_same<decltype(m), Vector<3, double>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Vector3f)
{
    Vector3f m{};
    static_assert(std::is_same<decltype(m), Vector<3, float>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Vector3i)
{
    Vector3i m{};
    static_assert(std::is_same<decltype(m), Vector<3, int>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Vector2d)
{
    Vector2d m{};
    static_assert(std::is_same<decltype(m), Vector<2, double>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Vector2f)
{
    Vector2f m{};
    static_assert(std::is_same<decltype(m), Vector<2, float>>::value, "synonym yielded unexpected type");
    SUCCEED();
}
TEST(Synonyms, Synonym_Vector2i)
{
    Vector2i m{};
    static_assert(std::is_same<decltype(m), Vector<2, int>>::value, "synonym yielded unexpected type");
    SUCCEED();
}

}  // namespace

}  // namespace silia

