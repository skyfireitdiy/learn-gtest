#include <gtest/gtest.h>
#include <iostream>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

class AddTest : public ::testing::Test
{
public:
    AddTest()
    {
        cout << "AddTest" << endl;
    }
    ~AddTest()
    {
        cout << "~AddTest" << endl;
    }
    void SetUp() override
    {
        cout << "SetUp" << endl;
    }
    void TearDown() override
    {
        cout << "TearDown" << endl;
    }
};

TEST_F(AddTest, AddTwoNumberCase1)
{
    cout << "add two number case1" << endl;
    EXPECT_EQ(add(5, 6), 11);
}

TEST_F(AddTest, AddTwoNumberCase2)
{
    cout << "add two number case2" << endl;
    EXPECT_EQ(add(6, 6), 12);
}
