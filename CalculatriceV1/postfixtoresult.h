#ifndef POSTFIXTORESULT_H
#define POSTFIXTORESULT_H

#include "ArrayQueue.h"
#include "ArrayStack.h"
#include <string>
#include <iostream>

class PostfixToResult {
public:
    PostfixToResult(const ArrayQueue<std::string>& file_postFixe);
    int solutionFinder();
private:
    void stackOperandes();
    void doOperation();
    ArrayStack<std::string> pile_operandes;
    ArrayQueue<std::string> file_postfixe;

};

#endif
