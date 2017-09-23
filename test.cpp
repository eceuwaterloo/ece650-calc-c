#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "calc.hpp"

// https://github.com/google/googletest/blob/master/googletest/docs/Primer.md

// Simple test, does not use gmock
TEST(Register, CalcTest)
{
    Register reg;
    EXPECT_EQ(reg.get(), 0);
    reg.add(1);
    EXPECT_EQ(reg.get(), 1);
    reg.sub(3);
    EXPECT_EQ(reg.get(), -2);
    reg.reset();
    EXPECT_EQ(reg.get(), 0);
}

TEST(Parser, CalcTest)
{
    char cmd;
    int arg;
    std::string err_msg;

    // initialize local variables
    cmd = 0;
    arg = 0;

    EXPECT_TRUE(parse_line ("+ 10", cmd, arg, err_msg));
    EXPECT_EQ(cmd, '+');
    EXPECT_EQ(arg, 10);

    EXPECT_TRUE(parse_line ("- 10", cmd, arg, err_msg));
    EXPECT_EQ(cmd, '-');
    EXPECT_EQ(arg, 10);

    arg = 42;
    EXPECT_TRUE(parse_line ("=", cmd, arg, err_msg));
    EXPECT_EQ(cmd, '=');
    // test that arg is not changed
    EXPECT_EQ(arg, 42);

    arg = 42;
    EXPECT_TRUE(parse_line ("c", cmd, arg, err_msg));
    EXPECT_EQ(cmd, 'c');
    // test that arg is not changed
    EXPECT_EQ(arg, 42);

    cmd = 0;
    arg = 42;
    EXPECT_FALSE(parse_line ("c 20", cmd, arg, err_msg));
    EXPECT_EQ(cmd, 0);
    // test that arg is not changed
    EXPECT_EQ(arg, 42);
    EXPECT_EQ(err_msg, "Unexpected argument");

    cmd = 0;
    arg = 42;
    EXPECT_FALSE(parse_line ("+ 20 34", cmd, arg, err_msg));
    EXPECT_EQ(cmd, 0);
    // test that arg is not changed
    EXPECT_EQ(arg, 42);
    EXPECT_EQ(err_msg, "Unexpected argument");

    cmd = 0;
    arg = 42;
    EXPECT_FALSE(parse_line ("+ ten", cmd, arg, err_msg));
    EXPECT_EQ(cmd, 0);
    // test that arg is not changed
    EXPECT_EQ(arg, 42);
    EXPECT_EQ(err_msg, "Missing or bad argument");

    cmd = 0;
    arg = 42;
    EXPECT_FALSE(parse_line ("w ten", cmd, arg, err_msg));
    EXPECT_EQ(cmd, 0);
    // test that arg is not changed
    EXPECT_EQ(arg, 42);
    EXPECT_EQ(err_msg, "Unknown command");


}
