#include <gtest/gtest.h>

int throw_func(int a)
{
    if (a == 0){
        throw 0;
    }
    return 0;
}


TEST(ExpectThrowTest, ExpectThrow)
{
    EXPECT_THROW(throw_func(0), int);
}

TEST(ExpectThrowTest, ExpectNoThrow)
{
    EXPECT_NO_THROW(throw_func(1));
}

TEST(ExpectThrowTest, ExpectThrowAndValue)
{
    EXPECT_ANY_THROW(throw_func(0));
}
