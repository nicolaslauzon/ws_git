#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include <string>
#include <iostream>
#include "ArrayQueue.h"
#include "ArrayStack.h"
class InfixToPostfix {
    public:
    ArrayQueue<std::string> file_infix_;
    ArrayQueue<std::string> file_postfix_;
    ArrayStack<std::string> pile_operateur_;
    InfixToPostfix();
    void pushString();
    void usageOption();
    std::string getStr(ArrayQueue<std::string> arrayQueue);
private:

    void openParentese();
    void  closeParentese();
    int getPriority(std::string var);
    void operateur();
    void operandes();
    void emptyStack();

};

#endif
