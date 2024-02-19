#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Calc {
    public:
    virtual int calc(int a) = 0;
    virtual int calc(int a,int b) = 0;
};

int UseCalc(Calc &c, int a)
{
    return c.calc(a);
}

int UseCalc(Calc &c, int a, int b)
{
    return c.calc(a, b);
}

class MockCalc: public Calc 
{
    public:
    MOCK_METHOD(int, calc, (int a), (override));
    MOCK_METHOD(int, calc, (int a, int b), (override));
};

using testing::_;

TEST(TestCalc, Case1)
{
    MockCalc calc;
    EXPECT_CALL(calc, calc(_)).Times(1);
    EXPECT_CALL(calc, calc(_, _)).Times(2);

    UseCalc(calc, 1);
    UseCalc(calc, 2,3);
    UseCalc(calc, 4,5);
}