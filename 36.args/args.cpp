#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>

class Calc
{
public:
    virtual int calc(int a, int b, int c) = 0;
    virtual int calc(int a, int b) = 0;
};

class MockCalc : public Calc
{
public:
    MOCK_METHOD(int, calc, (int a, int b, int c), (override));
    MOCK_METHOD(int, calc, (int a, int b), (override));
};

using testing::_;
using testing::Lt;

TEST(TestCalc, Case1)
{
    MockCalc calc;
    EXPECT_CALL(calc, calc(_, _)).With(Lt());

    calc.calc(3, 4);
}

using testing::AllArgs;

TEST(TestCalc, Case2)
{
    MockCalc calc;
    EXPECT_CALL(calc, calc(_, _)).With(AllArgs(Lt()));

    calc.calc(3, 4);
}

using testing::AllOf;
using testing::Args;
using testing::Gt;

TEST(TestCalc, Case3)
{
    MockCalc calc;
    EXPECT_CALL(calc, calc(_, _, _)).With(AllOf(Args<0, 1>(Lt()), Args<1, 2>(Gt())));

    calc.calc(3, 4, 2);
}
