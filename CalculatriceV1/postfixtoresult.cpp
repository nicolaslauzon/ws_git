#include "postfixtoresult.h"
#include "ArrayQueue.h"
#include "ArrayStack.h"
#include <string>
#include <iostream>

PostfixToResult::PostfixToResult(const ArrayQueue<std::string>& file_postFixe)
    : pile_operandes(25),
      file_postfixe(file_postFixe)
{
}

int PostfixToResult::solutionFinder() {
    for(int i =0; i<2;i++){
        stackOperandes();
    }
    while (pile_operandes.size() != 1) {
        if (file_postfixe.front()=="+" || file_postfixe.front()=="-" || file_postfixe.front()=="%" || file_postfixe.front()=="/" || file_postfixe.front()=="*"){
            doOperation();
        }
        else {
            stackOperandes();
        }
    }
    return stoi(pile_operandes.top());

}

void PostfixToResult::stackOperandes() {
    pile_operandes.push(file_postfixe.front());
    file_postfixe.pop();
}

void PostfixToResult::doOperation() {
    int operande1, operande2;
    std::string operateur = file_postfixe.front();
    file_postfixe.pop();
    operande1 = stoi(pile_operandes.top());
    pile_operandes.pop();
    operande2 = stoi(pile_operandes.top());
    pile_operandes.pop();
    if (operateur == "+"){
        operande1 = operande2 + operande1;
    }
    else if (operateur == "-"){
        operande1 = operande2 - operande1;
    }
    else if (operateur == "/"){
        operande1 = operande2 / operande1;
    }
    else if (operateur == "*"){
        operande1 = operande2 * operande1;
    }
    else if (operateur == "%"){
        operande1 = operande2 % operande1;
    }
    pile_operandes.push(std::to_string(operande1));
}
