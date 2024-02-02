#include <gmock/gmock.h>

#include <string>
#include <random>

std::string Hello()
{
    return "Hello World " + std::to_string(rand());
}

int Rand10()
{
    return rand() % 10;
}

TEST(GeneralizedAssert, Hello)
{
    EXPECT_THAT(Hello(), ::testing::StartsWith("Hello World"));
}

TEST(GeneralizedAssert, Rand10)
{
    EXPECT_THAT(Rand10(), ::testing::AllOf(::testing::Ge(0), ::testing::Lt(10)));
}
