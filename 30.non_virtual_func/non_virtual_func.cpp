#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Adder
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
};

class MockAdder // 没有继承
{
public:
    MOCK_METHOD(int, add, (int a, int b), ()); // 没有override
};

template <typename AdderType>
int UseAdder(AdderType &adder, int a, int b)
{
    return adder.add(a, b);
};

using testing::Return;

TEST(TestAdder, Case1)
{
    MockAdder adder;
    EXPECT_CALL(adder, add).WillOnce(Return(10));

    EXPECT_EQ(UseAdder(adder, 4, 1), 10);
}
