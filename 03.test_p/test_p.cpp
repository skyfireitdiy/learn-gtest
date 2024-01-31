#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <tuple>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

class NumberTest : public ::testing::TestWithParam<tuple<int, int, int> >
{
};

TEST_P(NumberTest, AddTwoNumber)
{
    auto param = GetParam();
    EXPECT_EQ(add(get<0>(param), get<1>(param)), get<2>(param));
}

INSTANTIATE_TEST_SUITE_P(AddTestPrefix, NumberTest, ::testing::Values((tuple<int, int, int> {1, 2, 3}), (tuple<int, int, int> {10, 20, 30})));
