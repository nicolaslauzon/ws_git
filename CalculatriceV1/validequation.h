#ifndef VALIDEQUATION_H
#define VALIDEQUATION_H

#include <string>
#include <iostream>

class ValidEquation
{
public:
    ValidEquation(const std::string& equation);
    void printError(int errorType);
    int testBraces();
    int testOperators();
    int expectedChar();
    int testAll();
    std::string returnEquation();
private:
    std::string equation;
    char tmp = 0;
    char tmp1 = 0;
};
#endif
