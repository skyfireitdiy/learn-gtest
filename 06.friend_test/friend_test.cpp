#include <gtest/gtest.h>

class Circle
{
private:
    double r_;
    double area_;

public:
    Circle(int r)
        : r_(r)
        , area_(r * r * 3.14)
    {
    }

    friend class CircelTest;
    FRIEND_TEST(CircelTest, Area);
};

TEST(CircelTest, Area)
{
    Circle c(5);
    EXPECT_EQ(c.area_, 78.5);
}
