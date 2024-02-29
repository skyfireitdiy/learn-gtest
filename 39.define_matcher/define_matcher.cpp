#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <gtest/gtest-matchers.h>
#include <ostream>

using namespace std;

class DivMatcher
{
    private:
        int data;
    public:

    using is_gtest_matcher = void;

    explicit DivMatcher(int n): data(n) {}

    bool MatchAndExplain(int param, ostream *) const
    {
        return param % data == 0;
    }

    void DescribeTo(std::ostream* os) const
    {
        *os << "Can be divided by " << data << endl;
    }

    void DescribeNegationTo(std::ostream* os) const {
        *os << "Cannot be divided by " << data << endl;
    }
};

using testing::Matcher;

::testing::Matcher<int> Div(int n) 
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
    MOCK_METHOD(int, calc, (int a, int b),(override));
};



TEST(TestCalc, Case1)
{
    MockCalc c;
    EXPECT_CALL(c, calc(Div(3), Div(5)));

    c.calc(6, 10);
}