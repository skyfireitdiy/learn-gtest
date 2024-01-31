#include "start.h"
#include <gtest/gtest.h>

TEST(Add, AddTwoNumber)
{
    ASSERT_EQ(add(5, 6), 11);
}
