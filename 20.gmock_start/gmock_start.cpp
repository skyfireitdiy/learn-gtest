#include "gmock/gmock.h"
#include <cstddef>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class File
{
public:
    virtual int open(const char *name) = 0;
    virtual int close() = 0;
    virtual int read(char *buf, size_t size) = 0;
    virtual int write(const char *buf, size_t size) = 0;
};

class Logger
{
private:
    File *file = nullptr;

public:
    Logger(File *f)
        : file(f)
    {
    }

    bool init()
    {
        return file->open("log.txt") == 0;
    }

    bool write(const char *buf, size_t size)
    {
        return file->write(buf, size) == size;
    }
};

class MockFile : public File
{
public:
    MOCK_METHOD(int, open, (const char *name), (override));
    MOCK_METHOD(int, read, (char *buf, size_t size), (override));
    MOCK_METHOD(int, write, (const char *buf, size_t size), (override));
    MOCK_METHOD(int, close, (), (override));
};

using ::testing::_;
using ::testing::Return;

TEST(GMockDemo, InitFailed)
{
    MockFile mockFile;
    EXPECT_CALL(mockFile, open(_))
        .WillOnce(Return(-1));

    Logger logger(&mockFile);

    EXPECT_FALSE(logger.init());
}

TEST(GMockDemo, WriteFailed)
{
    MockFile mockFile;
    EXPECT_CALL(mockFile, open(_))
        .WillOnce(Return(0));

    EXPECT_CALL(mockFile, write(_, 10))
        .Times(3)
        .WillOnce(Return(10))
        .WillOnce(Return(-1))
        .WillOnce(Return(5));

    Logger logger(&mockFile);

    EXPECT_TRUE(logger.init());
    EXPECT_TRUE(logger.write(nullptr, 10));
    EXPECT_FALSE(logger.write(nullptr, 10));
    EXPECT_FALSE(logger.write(nullptr, 10));
}
