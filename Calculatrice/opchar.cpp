#include "opchar.h"
#include <string>


OpChar::OpChar(std::string value) {
    this-> value = value;
    getType();
    getpriority();
}

int OpChar::getpriority() {
    switch (value[0]) {
    case '*':case '/':case '%':
        priority = 2;
    case '-':case '+':
        priority = 1;
    case '(':case ')':
        priority = 0;
    default:
        priority = 4;
    }
}

void OpChar::getType() {
    switch (value[0]) {
    case '*':case '/':case '%':case '-':case '+':
        type = 1;
    case '(':
        type = 2;
    case ')':
        type = 3;
    default:
        type = 4;

    }
}

inline int OpChar::returnType() {
    return type;
}

inline int OpChar::returnPriority() {
    return priority;
}
