#include <gmock/gmock.h>
#include <string>
#include <cstdlib>

using namespace std;

string generate_tmp_file_name()
{
    return "/tmp/test_file_" + to_string(rand());
}

TEST(StringAssert, Regex)
{
    EXPECT_THAT(generate_tmp_file_name(), testing::MatchesRegex("/tmp/test_file_[0-9]+"));
}

TEST(StringAssert, StartsWith)
{
    EXPECT_THAT(generate_tmp_file_name(), testing::StartsWith("/tmp/test_file_"));
}

TEST(StringAssert, EqualWithoutCase)
{
    EXPECT_THAT("/tmp/test_file", testing::StrCaseEq("/TMP/TEST_FILE"));
}
