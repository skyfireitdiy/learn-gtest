#include <gtest/gtest.h>

// 下面是一个错误的函数
int add(int a, int b)
{
    return a - b;
}

// 演示自定义错误信息
TEST(AddTest, Case1)
{
    EXPECT_EQ(add(1, 2), 3) << "add(1, 2) should be 3";
}

::testing::AssertionResult MyAddTest(
    const char *expr_a,
    const char *expr_b,
    const char *expr_result,
    int a,
    int b,
    int result)
{
    if (add(a, b) == result)
    {
        return ::testing::AssertionSuccess();
    }
    else
    {
        return ::testing::AssertionFailure() << "add(" << a << ", " << b << ") should be " << result;
    }
}

// 演示自定义格式化
TEST(AddTest, Case2)
{
    EXPECT_PRED_FORMAT3(MyAddTest, 1, 2, 3);
    EXPECT_PRED_FORMAT3(MyAddTest, 2, 6, 8);
}
