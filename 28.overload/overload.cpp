#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Calc
{
public:
    virtual int calc(int a) = 0;
    virtual int calc(int a, int b) = 0;
    virtual int calc(int a) const = 0;
    virtual int calc(double a) = 0;
};

int UseCalc(Calc &c, int a)
{
    return c.calc(a);
}

int UseCalc(Calc &c, double a)
{
    return c.calc(a);
}

int UseCalc(const Calc &c, int a)
{
    return c.calc(a);
}

int UseCalc(Calc &c, int a, int b)
{
    return c.calc(a, b);
}

class MockCalc : public Calc
{
public:
    MOCK_METHOD(int, calc, (int a), (override));
    MOCK_METHOD(int, calc, (int a, int b), (override));
    MOCK_METHOD(int, calc, (int a), (override, const));
    MOCK_METHOD(int, calc, (double a), (override));
};

using testing::_;
using testing::An;
using testing::Const;
using testing::Return;

TEST(TestCalc, Case1)
{
    MockCalc calc;
    EXPECT_CALL(calc, calc(An<int>())).Times(1).WillRepeatedly(Return(1));
    EXPECT_CALL(calc, calc(_, _)).Times(2).WillRepeatedly(Return(2));

    const MockCalc calc2;
    EXPECT_CALL(Const(calc2), calc(_)).Times(1).WillRepeatedly(Return(3));

    EXPECT_CALL(calc, calc(An<double>())).Times(1).WillRepeatedly(Return(4));

    EXPECT_EQ(UseCalc(calc, 1), 1);
    EXPECT_EQ(UseCalc(calc, 2, 3), 2);
    EXPECT_EQ(UseCalc(calc, 4, 5), 2);
    EXPECT_EQ(UseCalc(calc2, 1), 3);
    EXPECT_EQ(UseCalc(calc, 1.0), 4);
}
