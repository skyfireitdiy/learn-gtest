#include <gtest/gtest.h>

void fail_routine()
{
    ASSERT_EQ(1, 2);
}

TEST(TestOnSubroutine, ShouldFail)
{
    ASSERT_NO_FATAL_FAILURE(fail_routine());
    ASSERT_EQ(3, 4);
}
