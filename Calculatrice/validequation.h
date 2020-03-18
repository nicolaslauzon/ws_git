#ifndef VALIDEQUATION_H
#define VALIDEQUATION_H

#include <string>
#include <iostream>

class ValidEquation
{
public:
    ValidEquation(std::string equation);
    void printError(int errorType);
    int testBraces();
    int testOperators();
    int expectedChar();
    int testAll();
private:
    std::string equation;
    int size;
    char tmp = 0;
    char tmp1 = 0;
};

#endif
