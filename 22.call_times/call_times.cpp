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

using testing::_;

int UseCalc(Calc &c, int a, int b)
{
    return c.Do(a, b);
}

TEST(Calc, MockCalcTestCase1)
{
    MockCalc calc;
    EXPECT_CALL(calc, Do).Times(0);

    // UseCalc(calc, 0, 0);
}

TEST(Calc, MockCalcTestCase2)
{
    MockCalc calc;
    EXPECT_CALL(calc, Do).Times(3);

    UseCalc(calc, 0, 0);
    UseCalc(calc, 0, 0);
    UseCalc(calc, 0, 0);
}
