#include "gmock/gmock.h"
#include <gmock/gmock.h>

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

void UseCalc(Calc &c, int a, int b)
{
    c.Do(a, b);
}

TEST(Calc, MockCalcTest)
{
    MockCalc calc;
    EXPECT_CALL(calc, Do(5, _));

    UseCalc(calc, 5, 10);
}
