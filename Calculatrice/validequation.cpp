#include "validequation.h"

ValidEquation::ValidEquation(std::string equation)
{
    this -> equation = equation;
    size = equation.size();
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




    }
}

int ValidEquation::testBraces()
{
    int diff = 0;
    for (int i = 0; i < size; i++) {
        if (equation[i] == '(')
            diff++;
        if (equation[i] == ')')
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
    for (int i = 0; i < size; i++) {
        if (equation[i] == '*' || equation[i] == '/' || equation[i] == '%') {
            if (equation[i+1] == '*' || equation[i+1] == '/' || equation[i+1] == '%') {
                tmp = equation[i];
                tmp1 = equation[i+1];
                return 3;
            }
        }
    }
    return 0;
}

int ValidEquation::expectedChar()
{
    for (int i = 0; i < size; i++) {
        if (!((equation[i] >= '0' && equation[i] <= '9') ||
             equation[i] == '%' ||
             equation[i] == '-' ||
             equation[i] == '/' ||
            (equation[i] >= '(' && equation[i] <= '+'))) {
            tmp = equation[i];
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
