#include <gtest/gtest.h>

int add(int a, int b)
{
    return a + b;
}

TEST(Add, AddTwoNumber)
{
    ASSERT_EQ(add(5, 6), 11);
}
