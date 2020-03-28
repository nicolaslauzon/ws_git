#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include <string>
#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "token.h"
class InfixToPostfix {
    public:
    Queue<Token> file_infix_;
    Queue<Token> file_postfix_;
    Stack<Token> pile_operateur_;
    InfixToPostfix();
    void pushString();
    void usageOption();
    std::string getStr(Queue<Token> arrayQueue);
private:

    void openParentese();
    void  closeParentese();
    int getPriority(std::string var);
    void operateur();
    void operandes();
    void emptyStack();

};

#endif
