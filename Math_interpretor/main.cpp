#include <iostream>
#include <string>
#include "ArrayQueue.h"
#include "ArrayStack.h"
#include "inputoutput.h"
#include "infixtopostfix.h"
#include "postfixtoresult.h"
int main() {
    InputOutput inputOutput;
    InfixToPostfix infixToPostfix;

    infixToPostfix.pushString();

    // Get l'equation infixe en string
    std::string EquationInFixe = infixToPostfix.getStr(infixToPostfix.file_infix_);

    infixToPostfix.usageOption(); // Tranform infixe into postfixe

    // Get l'equation postfixe en string
    std::string EquationPostFixe = infixToPostfix.getStr(infixToPostfix.file_postfix_);

    PostfixToResult postfixeToResult(infixToPostfix.file_postfix_); // find solution
    int solution = postfixeToResult.solutionFinder(); //Solution

    inputOutput.output(EquationInFixe,EquationPostFixe,solution); //output
}
