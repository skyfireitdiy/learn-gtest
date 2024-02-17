#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Calc
{
public:
    virtual int Do(int a, int b) = 0;
};

class MockCalc : public Calc
{
public:
    MOCK_METHOD(int, Do, (int a, int b), (override));
};

int UseCalc(Calc &c, int a, int b)
{
    return c.Do(a, b);
}

using testing::_;
using testing::Return;

TEST(Calc, MockCalcTestCase1)
{
    MockCalc calc;
    EXPECT_CALL(calc, Do).WillOnce(Return(10));

    EXPECT_EQ(UseCalc(calc, 5, 10), 10);
}

TEST(Calc, MockCalcTestCase2)
{
    MockCalc calc;

    EXPECT_CALL(calc, Do).Times(3).WillOnce(Return(10)).WillRepeatedly(Return(20));

    EXPECT_EQ(UseCalc(calc, 5, 10), 10);
    EXPECT_EQ(UseCalc(calc, 5, 10), 20);
    EXPECT_EQ(UseCalc(calc, 5, 10), 20);
}
