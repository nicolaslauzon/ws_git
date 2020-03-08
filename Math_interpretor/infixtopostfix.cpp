#include "infixtopostfix.h"

InfixToPostfix::InfixToPostfix() :
file_infix_(25), file_postfix_(25) , pile_operateur_(25)
{

}

void InfixToPostfix::pushString() {
    file_infix_.push("4");
    file_infix_.push("+");
    file_infix_.push("5");
    file_infix_.push("/");
    file_infix_.push("5");
    file_infix_.push("%");
    file_infix_.push("4");
    //file_infix_.push(")");
}

void InfixToPostfix::usageOption(){
    std::string var;
    while (file_infix_.isEmpty()) {
        var = file_infix_.front();
        if (var== "("){
            openParentese();
        }
        else if (var==")"){
            closeParentese();
        }
        else if (var=="*"||var=="/"||var=="%"||var=="+"||var=="-"){
            operateur();
        }
        else
            operandes();
    }
    emptyStack();
}
void InfixToPostfix::openParentese(){
    pile_operateur_.push(file_infix_.front());
    file_infix_.pop();
}

void InfixToPostfix::closeParentese() {
    while (pile_operateur_.top() != "(") {
        file_postfix_.push(pile_operateur_.top());
        pile_operateur_.pop();
    }
    pile_operateur_.pop();
    file_infix_.pop();

}

int InfixToPostfix::getPriority(std::string var) {
    if (var==")"||var=="(")
        return 0;
    else if(var=="+"||var=="-")
        return 1;
    else if(var=="*"||var=="/"||var=="%")
        return 2;
    return -1;
}

void InfixToPostfix::operateur() {
    while (getPriority(file_postfix_.front()) >= getPriority(file_infix_.front())) {
        file_postfix_.push(file_infix_.front());
        file_postfix_.pop();
    }
    pile_operateur_.push(file_infix_.front());
    file_infix_.pop();
}

void InfixToPostfix::operandes() {
    file_postfix_.push(file_infix_.front());
    file_infix_.pop();
}

void InfixToPostfix::emptyStack() {
    while (pile_operateur_.size()) {
        file_postfix_.push(pile_operateur_.top());
        pile_operateur_.pop();
    }
}

std::string InfixToPostfix::getStr(ArrayQueue<std::string> arrayQueue) {
    std::string temp = arrayQueue.front();
    while (arrayQueue.isEmpty()) {
        arrayQueue.pop();
        temp= temp + arrayQueue.front();
    }
    return temp;
}
