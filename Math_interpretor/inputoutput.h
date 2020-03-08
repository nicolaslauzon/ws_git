#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <string>
#include <iostream>

class InputOutput {
    public:
        InputOutput();
        std::string input();
        void output(std::string infix, std::string postfix, size_t result);

};

#endif
