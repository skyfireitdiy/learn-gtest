#include "gmock/gmock.h"
#include "gtest/gtest.h"

int add(int a, int b)
{
    return a + b;
}

class AddInterface
{
public:
    virtual int add(int a, int b)
    {
        return ::add(a, b);
    };
};

class MockAdd : public AddInterface
{
public:
    MOCK_METHOD(int, add, (int a, int b), (override));
};

int UseAdd(AddInterface &adder, int a, int b)
{
    return adder.add(a, b);
}

using testing::Return;

TEST(TestAdd, Case1)
{
    MockAdd adder;

    EXPECT_CALL(adder, add).WillOnce(Return(10));
    EXPECT_EQ(UseAdd(adder, 4, 2), 10);
}
