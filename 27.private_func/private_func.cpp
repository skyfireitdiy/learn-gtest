#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <map>

using namespace std;

class MakeMap
{
private:
    virtual map<int, int> make1() = 0;
    virtual map<int, int> make2() = 0;
};

class MockMakeMap : public MakeMap
{
public:
    MOCK_METHOD((map<int, int>), make1, (), (override));

    using ReturnType = map<int, int>;
    MOCK_METHOD(ReturnType, make2, (), (override));
};

TEST(TestMakeMap, Case1)
{
    MockMakeMap makemap;
    EXPECT_CALL(makemap, make1);
    EXPECT_CALL(makemap, make2);

    makemap.make1();
    makemap.make2();
}
