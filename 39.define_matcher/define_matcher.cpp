#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <gtest/gtest-matchers.h>
#include <ostream>
#include <string>

using namespace std;

class DivMatcher
{
private:
    int data;

public:
    using is_gtest_matcher = void;

    explicit DivMatcher(int n)
        : data(n)
    {
    }

    bool MatchAndExplain(int param, ostream *) const
    {
        return param % data == 0;
    }

    void DescribeTo(std::ostream *os) const
    {
        *os << "Can be divided by " << data << endl;
    }

    void DescribeNegationTo(std::ostream *os) const
    {
        *os << "Cannot be divided by " << data << endl;
    }
};

using testing::Matcher;

Matcher<int> Div(int n)
{
    return DivMatcher(n);
}

class Calc
{
public:
    virtual int calc(int a, int b) = 0;
};

class MockCalc : public Calc
{
public:
    MOCK_METHOD(int, calc, (int a, int b), (override));
};

TEST(TestCalc, Case1)
{
    MockCalc c;
    EXPECT_CALL(c, calc(Div(3), Div(5)));

    c.calc(6, 10);
}

MATCHER(Div2, (negation ? "is not" : "is") + string(" divisible by 2"))
{
    return (arg % 2) == 0;
}

TEST(TestCalc, Case2)
{
    MockCalc c;
    EXPECT_CALL(c, calc(Div2(), Div2()));

    c.calc(6, 10);
}

MATCHER_P(DivN, n, (negation ? "is not" : "is") + string(" divisible by ") + std::to_string(n))
{
    return (arg % n) == 0;
}

TEST(TestCalc, Case3)
{
    MockCalc c;
    EXPECT_CALL(c, calc(DivN(3), DivN(5)));

    c.calc(6, 10);
}
