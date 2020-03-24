#include "validequation.h"

ValidEquation::ValidEquation(const std::string& equation)
{
    this -> equation = equation;
}

void ValidEquation::printError(int errorType)
{
    switch (errorType) {
    case 0:
        std::cout << "The equation you have entered is valid: " << equation << std::endl;
    break;
    case 1:
        std::cout << "The equation you  entered is invalid: " << equation << std::endl << "Unexpected: '"  << tmp << "'" << std::endl;
    break;
    case 2:
        std::cout << "The equation you  entered is invalid: " << equation << std::endl << "Extraneous: '" << tmp << "'" << std::endl;
    break;
    case 3:
        std::cout << "The equation you  entered is invalid: " << equation << std::endl << "Unexpected: '"  << tmp << "' or '" << tmp1 << "'" << std::endl;
    break;
    case 4:
        std::cout << "The equation you  entered is invalid: " << equation << std::endl << "Division by 0"  << std::endl;
    break;



    }
}

int ValidEquation::testBraces()
{
    int diff = 0;
    for (std::size_t i = 0; i < equation.size(); i++) {
        if (equation.at(i) == '(')
            diff++;
        if (equation.at(i) == ')')
            diff--;
    }
    if (!diff)
        return 0;
    if (diff < 0)
        tmp = ')';
    else
        tmp = '(';
        return 2;


}

int ValidEquation::testOperators()
{
    for (std::size_t i = 0; i < equation.size(); i++) {
        if (equation.at(i) == '*' || equation.at(i) == '/' || equation.at(i) == '%') {
            if (equation.at(i + 1) == '*' || equation.at(i + 1) == '/' || equation.at(i + 1) == '%') {
                tmp = equation.at(i);
                tmp1 = equation.at(i + 1);
                return 3;
            }
        }
    }
    return 0;
}

int ValidEquation::expectedChar()
{
    for (std::size_t i = 0; i < equation.size(); i++) {
        if (!((equation.at(i) >= '0' && equation.at(i) <= '9') ||
             equation.at(i) == '%' ||
             equation.at(i) == '-' ||
             equation.at(i) == '/' ||
            (equation.at(i) >= '(' && equation.at(i) <= '+'))) {
            tmp = equation.at(i);
            return 1;
        }
    }
    return 0;
}

int ValidEquation::testAll()
{
    int tmp2 = expectedChar();
    if (tmp2)
        return tmp2;
    tmp2 = testBraces();
    if (tmp2)
        return tmp2;
    tmp2 = testOperators();
    if (tmp2)
        return tmp2;
    return 0;
}

std::string ValidEquation::returnEquation()
{
    return equation;
}
