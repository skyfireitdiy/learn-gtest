#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Calc
{
public:
    virtual int add(int a, int b) = 0;
};

class MockCalc : public Calc
{
public:
    MOCK_METHOD(int, add, (int a, int b), (override));
};

TEST(TestAdd, Case1)
{
    MockCalc calc;
    EXPECT_CALL(calc, add);

    ON_CALL(calc, add).WillByDefault([](int a, int b) {
        return a + b;
    });

    EXPECT_EQ(calc.add(1, 1), 2);
}
