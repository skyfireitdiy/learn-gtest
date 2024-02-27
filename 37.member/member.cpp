#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gmock/gmock-function-mocker.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <ostream>

using namespace std;

struct Complex
{
    double r;
    double i;

    string toString() const
    {
        if (r == 0)
        {
            if (i == 0)
            {
                return "0";
            }
            else
            {
                return to_string(i) + "i";
            }
        }
        else
        {
            if (i == 0)
            {
                return to_string(r);
            }
            else
            {
                return to_string(r) + "+" + to_string(i) + "i";
            }
        }
    }
};

class Calc
{
public:
    virtual Complex calc(Complex a, Complex b) = 0;
};

class MockCalc : public Calc
{
public:
    MOCK_METHOD(Complex, calc, (Complex a, Complex b), (override));
};

using testing::_;
using testing::Field;
using testing::Gt;

void PrintTo(const Complex &c, std::ostream *out)
{
    *out << c.toString() << endl;
}

TEST(TestCalc, Case1)
{
    MockCalc calc;
    EXPECT_CALL(calc, calc(Field("real part", &Complex::r, Gt(0)), _));

    calc.calc(Complex {1, 2}, Complex {1, 2});
}

using testing::Property;
using testing::StartsWith;

TEST(TestCalc, Case2)
{
    MockCalc calc;
    EXPECT_CALL(calc, calc(Property("complex string", &Complex::toString, StartsWith("3")), _));

    calc.calc(Complex {3, 2}, Complex {1, 2});
}

using testing::AllOf;

TEST(TestCalc, Case3)
{
    MockCalc calc;
    EXPECT_CALL(calc, calc(
                          AllOf(
                              Field("real part", &Complex::r, Gt(0)),
                              Field("image part", &Complex::i, Gt(0))),
                          _));

    calc.calc(Complex {1, 2}, Complex {1, 2});
}
