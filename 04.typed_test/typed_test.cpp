#include <cstdint>
#include <gtest/gtest-typed-test.h>
#include <gtest/gtest.h>

// 1. 定义模板类
template <typename T>
class TypedTestDemo : public testing::Test {};

// 2. 实例化模板类
using MyTypes = ::testing::Types<int, double, float>;
TYPED_TEST_SUITE(TypedTestDemo, MyTypes);

// 3. 定义测试用例
TYPED_TEST(TypedTestDemo, TypedTest) {
    TypeParam x = 5;
    TypeParam y = 10;
    TypeParam z = x + y;
    EXPECT_EQ(z, 15);
}


struct A {
    char a;
    short b;
};

template <typename T>
class TypeSizeTest : public testing::Test {};

using MyTypes2 = ::testing::Types<int, unsigned int, int32_t, A>;

TYPED_TEST_SUITE(TypeSizeTest, MyTypes2);

TYPED_TEST(TypeSizeTest, TypeSizeTest) {
    EXPECT_EQ(sizeof(TypeParam), 4);
}
