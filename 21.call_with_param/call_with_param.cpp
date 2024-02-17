#include "gmock/gmock.h"
#include "gtest/gtest.h"
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

TEST(Calc, MockCalcTestCase1)
{
    MockCalc calc;
    EXPECT_CALL(calc, Do(5, _)); // 第一个参数必须是5，第二个随意

    UseCalc(calc, 5, 10);
}

TEST(Calc, MockCalcTestCase2)
{
    MockCalc calc;
    EXPECT_CALL(calc, Do(testing::Gt(5), testing::Lt(10))); // 第一个参数必须大于5，第二个参数必须小于10

    UseCalc(calc, 6, 9);
}

TEST(Calc, MockCalcTestCase3)
{
    MockCalc calc;
    EXPECT_CALL(calc, Do);

    UseCalc(calc, 0, 0);
}
