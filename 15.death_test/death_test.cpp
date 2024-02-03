#include "gtest/gtest.h"
#include <cstdlib>
#include <cstdio>
#include <gtest/gtest.h>

void abort_func()
{
    abort();
}

void crash_func(int a)
{
    if (a == 0)
    {
        fprintf(stderr, "hello\n");
        int *p = nullptr;
        *p = 0;
    }
    else
    {
        exit(50);
    }
}

TEST(DeathTest, Crash)
{
    ASSERT_DEATH(crash_func(0), "he.*");
}

TEST(DeathTest, Abort)
{
    EXPECT_EXIT(abort_func(), ::testing::KilledBySignal(SIGABRT), ".*");
}

TEST(DeathTest, CrashCode)
{
    EXPECT_EXIT(crash_func(0), ::testing::KilledBySignal(SIGSEGV), ".*");
}

TEST(DeathTest, Normal)
{
    EXPECT_EXIT(crash_func(1), ::testing::ExitedWithCode(50), ".*");
}
