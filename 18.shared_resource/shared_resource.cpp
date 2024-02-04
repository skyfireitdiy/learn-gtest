#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class SharedResource : public testing::Test
{
public:
    static int *ptr;

public:
    static void SetUpTestSuite()
    {
        cout << "SetUpTestSuite" << endl;
        ptr = new int(100);
    }

    static void TearDownTestSuite()
    {
        cout << "TearDownTestSuite" << endl;
        delete ptr;
        ptr = nullptr;
    }
};

int *SharedResource::ptr = nullptr;

TEST_F(SharedResource, Case1)
{
    ASSERT_EQ(100, *SharedResource::ptr);
}

TEST_F(SharedResource, Case2)
{
    ASSERT_EQ(100, *SharedResource::ptr);
}
