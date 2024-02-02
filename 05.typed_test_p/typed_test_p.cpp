#include <gtest/gtest-typed-test.h>
#include <gtest/gtest.h>

// 要测试的两个函数
template <typename T>
T add(T a, T b)
{
    return a + b;
}

template <typename T>
T sub(T a, T b)
{
    return a - b;
}

// 1. 定义模板类
template <typename T>
class TypedTest : public testing::Test
{
};

// 2. 定义参数化测试套件
TYPED_TEST_SUITE_P(TypedTest);

// 3. 测试用例场景1
TYPED_TEST_P(TypedTest, AddTest)
{
    TypeParam a = 5;
    TypeParam b = 6;
    EXPECT_EQ(add(a, b), 11);
}

// 4. 测试用例场景2
TYPED_TEST_P(TypedTest, SubTest)
{
    TypeParam a = 5;
    TypeParam b = 6;
    EXPECT_EQ(sub(a, b), -1);
}

// 5. 注册测试
REGISTER_TYPED_TEST_SUITE_P(TypedTest, AddTest, SubTest);

// 6. 实例化
using MyTypes = ::testing::Types<int, float, double, long>;
INSTANTIATE_TYPED_TEST_SUITE_P(MyPrefix, TypedTest, MyTypes);
