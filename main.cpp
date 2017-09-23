/** Main file */
#include <iostream>
#include <sstream>
#include <vector>

#include "calc.hpp"

int main(int argc, char** argv) {

    Register reg;
    // read from stdin until EOF
    while (!std::cin.eof()) {

        // read a line of input until EOL and store in a string
        std::string line;
        std::getline(std::cin, line);

        // if nothing was read, go to top of the while to check for eof
        if (line.size() == 0) {
            continue;
        }

        char cmd;
        int arg;
        std::string err_msg;
        if (parse_line(line, cmd, arg, err_msg)) {
            switch (cmd) {
            case '+':
                reg.add(arg);
                break;
            case '-':
                reg.sub(arg);
                break;
            case 'c':
                reg.reset();
                break;
            case '=':
                std::cout << reg.get() << "\n";
                break;
            }
        }
        else {
            std::cerr << "Error: " << err_msg << "\n";
        }
    }
}
