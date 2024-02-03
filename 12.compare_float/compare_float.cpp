#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(CompareFloat, Pred)
{
    EXPECT_PRED_FORMAT2(::testing::FloatLE, 0.50, 0.51);
    EXPECT_PRED_FORMAT2(::testing::DoubleLE, 0.50, 0.51);
}

TEST(CompareFloat, ExpectThat)
{
    EXPECT_THAT(0.50, ::testing::Le(0.51));
}
