#include <gtest/gtest.h>


int add(int a, int b)
{
    return a + b;
}

TEST(SkipTest, Add)
{
    EXPECT_EQ(2, add(1, 1));
}

TEST(SkipTest, Add2)
{
    EXPECT_EQ(3, add(1, 2));
}

TEST(SkipTest, Add3)
{
    GTEST_SKIP() << "Skipping this test";
    EXPECT_EQ(4, add(1, 2));
}

TEST(SkipTest, Add4)
{
    GTEST_FAIL();
    EXPECT_EQ(3, add(1, 2));
}
