#include "gmock/gmock.h"
#include "gtest/gtest.h"

template<typename Number>
class Calc
{
    public:
    virtual Number calc(Number a, Number b) = 0;
};


template<typename Number>
class MockCalc: public Calc<Number>
{
    public:
    MOCK_METHOD(Number, calc, (Number a, Number b));
};

TEST(TestCalc, Case1)
{
    MockCalc<int> calc;
    EXPECT_CALL(calc, calc);

    calc.calc(1, 2);
}

TEST(TestCalc, Case2)
{
    MockCalc<double> calc;
    EXPECT_CALL(calc,calc);

    calc.calc(2.1, 3.4);
}