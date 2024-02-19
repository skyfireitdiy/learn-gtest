#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Calc
{
public:
    virtual int Do(int a, int b) = 0;
    virtual int Do1(int a, int b) = 0;
};

class MockCalc : public Calc
{
public:
    MOCK_METHOD(int, Do, (int a, int b), (override));
    MOCK_METHOD(int, Do1, (int a, int b), (override));
};

int UseCalc(Calc &c, int a, int b, bool d)
{
    return d ? c.Do(a, b) : c.Do1(a, b);
}

using testing::InSequence;

TEST(Calc, MockCalcTestCase1)
{
    MockCalc calc;

    EXPECT_CALL(calc, Do1);
    EXPECT_CALL(calc, Do);

    UseCalc(calc, 5, 10, true);
    UseCalc(calc, 5, 10, false);
}

TEST(Calc, MockCalcTestCase2)
{
    MockCalc calc;

    InSequence seq;

    EXPECT_CALL(calc, Do1);
    EXPECT_CALL(calc, Do);

    UseCalc(calc, 5, 10, false);
    UseCalc(calc, 5, 10, true);
}
