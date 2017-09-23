// Calculator
#include "calc.hpp"

#include <iostream>
#include <sstream>
#include <string>

Register::Register() : value(0) {}

int Register::get() { return value; }
void Register::add(int v) { value += v; }
void Register::sub(int v) { value -= v; }
void Register::reset() { value = 0; }

bool parse_line (std::string const &line,
                 char &cmd, int &arg, std::string &err_msg) {

    std::istringstream input(line);

    // remove whitespace
    ws(input);

    if (input.eof()) {
        err_msg = "Empty command";
        return false;
    }

    char ch;
    input >> ch;

    if (input.fail()) {
        err_msg = "Failed to read input";
        return false;
    }


    if (ch == 'c' || ch == '=') {
        // remove whitespace
        std::ws(input);
        if (!input.eof()) {
            err_msg = "Unexpected argument";
            return false;
        }
        cmd = ch;
        return true;
    }
    else if (ch == '+' || ch == '-') {
        int num;
        input >> num;
        if (input.fail()) {
            err_msg = "Missing or bad argument";
            return false;
        }
        ws(input);
        if (!input.eof()) {
            err_msg = "Unexpected argument";
            return false;
        }
        cmd = ch;
        arg = num;
        return true;
    }
    else {
        err_msg = "Unknown command";
        return false;
    }

}
