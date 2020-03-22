#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <string>
#include <iostream>

class InputOutput {
    public:
        InputOutput();
        std::string input();
        void output(const std::string& infix, const std::string& postfix, const size_t& result);

};

#endif
