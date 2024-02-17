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

int UseCalc(Calc &c, int a, int b)
{
    return c.Do(a, b);
}

using testing::_;
using testing::Return;

TEST(Calc, MockCalcTestCase1)
{
    MockCalc calc;
    EXPECT_CALL(calc, Do)
        .WillOnce(Return(10));

    EXPECT_CALL(calc, Do(5, _))
        .WillOnce(Return(20));

    EXPECT_EQ(UseCalc(calc, 6, 10), 10);
    EXPECT_EQ(UseCalc(calc, 5, 10), 20);
}

// TEST(Calc, MockCalcTestCase2)
// {
// MockCalc calc;
//
// for (int i = 0; i < 3; ++i)
// {
// EXPECT_CALL(calc, Do)
// .WillOnce(Return(10 * i));
// }
//
// EXPECT_EQ(UseCalc(calc, 5, 10), 20);
// }

TEST(Calc, MockCalcTestCase3)
{
    MockCalc calc;

    for (int i = 0; i < 3; ++i)
    {
        EXPECT_CALL(calc, Do(i, _))
            .WillOnce(Return(10 * i));
    }

    EXPECT_EQ(UseCalc(calc, 0, 10), 0);
    EXPECT_EQ(UseCalc(calc, 1, 10), 10);
    EXPECT_EQ(UseCalc(calc, 2, 10), 20);
}

TEST(Calc, MockCalcTestCase4)
{
    MockCalc calc;

    for (int i = 0; i < 3; ++i)
    {
        EXPECT_CALL(calc, Do)
            .WillOnce(Return(10 * i))
            .RetiresOnSaturation();
    }

    EXPECT_EQ(UseCalc(calc, 5, 10), 20);
    EXPECT_EQ(UseCalc(calc, 5, 10), 10);
    EXPECT_EQ(UseCalc(calc, 5, 10), 0);
}
