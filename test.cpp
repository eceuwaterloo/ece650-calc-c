#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "calc.hpp"

// https://github.com/onqtam/doctest/blob/master/doc/markdown/tutorial.md

TEST_CASE("Register Test")
{
    Register reg;
    CHECK(reg.get() == 0);
    reg.add(1);
    CHECK(reg.get() == 1);
    reg.sub(3);
    CHECK(reg.get() == -2);
    reg.reset();
    CHECK(reg.get() == 0);
}

TEST_CASE("Parser Correct")
{
    char cmd = 0;
    int arg = 0;
    std::string err_msg;

    CHECK(parse_line ("+ 10", cmd, arg, err_msg));
    CHECK(cmd == '+');
    CHECK(arg == 10);

    CHECK(parse_line ("- 10", cmd, arg, err_msg));
    CHECK(cmd == '-');
    CHECK(arg == 10);

    arg = 42;
    CHECK(parse_line ("=", cmd, arg, err_msg));
    CHECK(cmd == '=');
    // test that arg is not changed
    CHECK(arg == 42);

    arg = 42;
    CHECK(parse_line ("c", cmd, arg, err_msg));
    CHECK(cmd == 'c');
    // test that arg is not changed
    CHECK(arg == 42);
}

TEST_CASE("Parser Errors")
{
    char cmd = 0;
    int arg = 0;
    std::string err_msg;

    CHECK(parse_line ("c 20", cmd, arg, err_msg) == false);
    CHECK(cmd == 0);
    // test that arg is not changed
    CHECK(arg == 0);
    CHECK(err_msg == "Unexpected argument");

    cmd = 0;
    arg = 42;
    CHECK(parse_line ("+ 20 34", cmd, arg, err_msg) == false);
    CHECK(cmd == 0);
    // test that arg is not changed
    CHECK(arg == 42);
    CHECK(err_msg == "Unexpected argument");

    cmd = 0;
    arg = 42;
    CHECK(parse_line ("+ ten", cmd, arg, err_msg) == false);
    CHECK(cmd == 0);
    // test that arg is not changed
    CHECK(arg == 42);
    CHECK(err_msg == "Missing or bad argument");

    cmd = 0;
    arg = 42;
    CHECK(parse_line ("w ten", cmd, arg, err_msg) == false);
    CHECK(cmd == 0);
    // test that arg is not changed
    CHECK(arg == 42);
    CHECK(err_msg == "Unknown command");
}

TEST_CASE("Failing Test Examples")
{
    CHECK(true == false);
}
