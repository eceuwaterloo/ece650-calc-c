#pragma once

#include <string>

/// Register class. Keeps track of one value
class Register
{
    /// the current value of the register
    int value;
public:
    /// Constructor. Creates a register with initial value of 0
    Register();
    /// Returns the current value
    int get();
    /// Adds v to the current value
    void add(int v);
    /// Subtracts v from the current value
    void sub(int v);
    /// Resets the current value to 0
    void reset();
};

/**
 * Parses a command line.
 * Returns a character of a command and an optional argument.
 * Returns true on success and false on a parsing error.
 * On error, err_msg contains the error message
 */
bool parse_line (std::string const &line,
                 char &cmd, int &arg, std::string &err_msg);
