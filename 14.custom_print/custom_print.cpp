#include <gtest/gtest.h>
#include <ostream>

class Circle
{
private:
    double r_;
    double area_;

public:
    Circle(double r)
        : r_(r)
        , area_(3.14 * r_ * r_)
    {
    }

    bool operator==(const Circle &other) const
    {
        return (r_ == other.r_) && (area_ == other.area_);
    }

    friend void PrintTo(const Circle &circle, std::ostream *out);
};

void PrintTo(const Circle &circle, std::ostream *out)
{
    *out << "Circle(r=" << circle.r_ << ", area=" << circle.area_ << ")";
}

Circle make_circle(double r)
{
    return Circle(r);
}

TEST(CustomPrint, CircleCase)
{
    EXPECT_EQ(make_circle(5.0), Circle(4.9));
}
