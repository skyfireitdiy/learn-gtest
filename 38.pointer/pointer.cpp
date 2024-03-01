#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>

class Calc
{
public:
    virtual int calc(int *pa, int *pb) = 0;
};

class MockCalc : public Calc
{
public:
    MOCK_METHOD(int, calc, (int *pa, int *pb), (override));
};

using testing::Gt;
using testing::Lt;
using testing::Pointee;

TEST(TestCalc, Case1)
{
    MockCalc c;
    EXPECT_CALL(c, calc(Pointee(Gt(3)), Pointee(Lt(6))));

    int a = 10;
    int b = 5;
    c.calc(&a, &b);
}
