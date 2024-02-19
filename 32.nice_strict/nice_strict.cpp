#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Calc
{
    public:
    virtual int add(int a,int b) = 0;
    virtual int sub(int a,int b) = 0;
};

class MockCalc: public Calc
{
    public:
    MOCK_METHOD(int, add, (int a, int b), (override));
    MOCK_METHOD(int, sub, (int a, int b), (override));
};

TEST(TestAdd, Case1)
{
    MockCalc calc;
    EXPECT_CALL(calc, add);

    calc.add(1, 1);
    calc.sub(1, 1);
}

TEST(TestAdd, Case2)
{
    using testing::NiceMock;
    NiceMock<MockCalc> calc;
    EXPECT_CALL(calc, add);

    calc.add(1, 1);
    calc.sub(1, 1);
}

TEST(TestAdd, Case3)
{
    using testing::StrictMock;
    StrictMock<MockCalc> calc;
    EXPECT_CALL(calc, add);

    calc.add(1, 1);
    calc.sub(1, 1);
}